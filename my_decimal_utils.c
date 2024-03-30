#include "my_decimal.h"

int get_bit_mantissa(my_decimal value, int position) {
  int element_index = position / 32;
  int bit_index = position % 32;

  return get_bit(value.bits[element_index], bit_index);
}

int get_bit_big_decimal(my_big_decimal value, int position) {
  int element_index = position / 32;
  int bit_index = position % 32;

  return get_bit(value.bits[element_index], bit_index);
}

int get_sign(my_decimal value) { return (value.bits[3] >> 31) & 1; }

int get_exponent(my_decimal value) { return (value.bits[3] >> 16) & 0xFF; }

void set_exponent(my_decimal *value, int exponent) {
  value->bits[3] = (value->bits[3] & 0x80000000) | (exponent << 16);
}

my_decimal init_empty_decimal() {
  my_decimal decimal_empty;

  for (int i = 0; i < 4; i++) {
    decimal_empty.bits[i] = 0;
  }

  return decimal_empty;
}

int is_empty_decimal(my_decimal decimal) {
  int result = 1;
  int i = 0;

  while (result && i < 3) {
    if (decimal.bits[i] != 0) {
      result = 0;
    }
    i++;
  }

  return result;
}

int is_empty_big_decimal(my_big_decimal decimal) {
  int result = 1;
  int i = 0;

  while (result && i < 8) {
    if (decimal.bits[i] != 0) {
      result = 0;
    }
    i++;
  }

  return result;
}

void get_big_decimal(my_decimal val, my_big_decimal *result) {
  memset(result, 0, sizeof(*result));
  int *ptr_result = (int *)result + sizeof(my_big_decimal) / sizeof(int) - 1;

  int *ptr_val = (int *)&val;
  for (int i = 0; i < 3; i++) *ptr_result-- = ptr_val[i];
}

int get_decimal(my_big_decimal value, int *power, my_decimal *result) {
  int error = 0;

  my_big_decimal ten = {{0, 0, 0, 0, 0, 0, 0, 10}};
  my_big_decimal buf_result;
  memcpy(&buf_result, &value, sizeof(buf_result));
  int overflow = 1, remainder = 0, prev_remainder = 0;

  while (overflow != 0 && error == 0) {
    overflow = 0;

    for (int i = 0; i < 5 && overflow == 0 && error == 0; i++) {
      if (buf_result.bits[i] != 0 || *power > 28) {
        if (*power > 0) {
          (*power)--;
          if (remainder != 0) prev_remainder = remainder;
          remainder = div_with_remainder(buf_result, ten, &buf_result).bits[7];
        } else
          error++;

        overflow++;
      }
    }
  }

  unsigned last_digit = div_with_remainder(buf_result, ten, &ten).bits[7];

  if (remainder > 5 ||
      (remainder == 5 &&
       ((prev_remainder == 0 && last_digit % 2 != 0) || prev_remainder != 0))) {
    if (!is_max_decimal(buf_result)) {
      my_big_decimal one = {{0, 0, 0, 0, 0, 0, 0, 1}};
      add_big_decimal(buf_result, one, &buf_result);
    } else {
      error++;
    }
  }  // buf_result.bits[7] += 1;

  if (!error) {
    int *ptr_result = (int *)&buf_result + 7;
    for (int i = 0; i < 3; i++) result->bits[i] = *ptr_result--;
  }

  return error;
}

int is_max_decimal(my_big_decimal value) {
  int max = 0;
  for (int i = 7; i > 4; i--)
    if (value.bits[i] == -1) max++;

  return (max == 3);
}

void add_big_decimal(my_big_decimal val1, my_big_decimal val2,
                     my_big_decimal *result) {
  memset(result, 0, sizeof(*result));
  int *ptr_val1 = (int *)&val1;
  int *ptr_val2 = (int *)&val2;
  int *ptr_result = (int *)result;

  int carry = 0;
  int last = sizeof(my_big_decimal) / sizeof(int) - 1;
  for (int i = last; i >= 0; i--) {
    int sign_val1_old = (ptr_val1[i] < 0);
    ptr_val1[i] += carry;
    int sign_val1 = (ptr_val1[i] < 0);
    int sign_val2 = (ptr_val2[i] < 0);

    ptr_result[i] = ptr_val1[i] + ptr_val2[i];
    int sign_res = (ptr_result[i] < 0);

    if (((sign_val1 == 1 || sign_val1_old == 1) && sign_val2 == 1) ||
        ((sign_val1 != sign_val2 || sign_val1_old != sign_val2) &&
         sign_res == 0))
      carry = 1;
    else
      carry = 0;
  }
}

void sub_big_decimal(my_big_decimal val1, my_big_decimal val2,
                     my_big_decimal *result) {
  memset(result, 0, sizeof(*result));
  int *ptr_val1 = (int *)&val1;
  int *ptr_val2 = (int *)&val2;
  int *ptr_result = (int *)result;

  int carry = 0;
  int last = sizeof(my_big_decimal) / sizeof(int) - 1;
  for (int i = last; i >= 0; i--) {
    ptr_result[i] = ptr_val1[i] - ptr_val2[i];
    ptr_result[i] -= carry;
    unsigned v_1 = ptr_val1[i];
    unsigned v_2 = ptr_val2[i];
    if (v_1 < v_2 || (ptr_val1[i] == ptr_val2[i] && carry == 1))
      carry = 1;
    else
      carry = 0;
  }
}

int shift_big_decimal(my_big_decimal val, int count, my_big_decimal *result) {
  int error = 0;
  int *ptr_val = (int *)&val;
  memcpy(result, ptr_val, sizeof(*result));
  while (count-- > 0) {
    int *ptr = (int *)result;
    if (get_bit(*ptr, 31) == 1) error++;
    for (int i = 0; i < 8; i++) {  // sizeof(my_big_decimal) / sizeof(int) = 8
                                   // ints in big_decimal
      ptr[i] = ptr[i] << 1;
      if (i < 8 - 1)  // 8 ints (7..0) in big_decimal
        set_bit(ptr + i, 0, get_bit(ptr[i + 1], 31));
    }
  }
  return error;
}

void div_big_decimal(my_big_decimal val1, my_big_decimal val2,
                     my_big_decimal *result, int *exp_shift) {
  *exp_shift = 0;

  if (result) memset(result, 0, sizeof(*result));

  my_big_decimal quotient;
  get_big_decimal(init_empty_decimal(), &quotient);

  my_big_decimal ten;
  get_big_decimal(get_ten(), &ten);

  while ((cmp_big_decimal(val1, val2) == -1)) {
    mul_big_decimal(val1, ten, &val1);
    *exp_shift += 1;
  }

  val1 = div_with_remainder(val1, val2, result);

  while (!is_empty_big_decimal(val1) &&
         get_start_bit_big_decimal(*result) > 5 * 32) {
    mul_big_decimal(val1, ten, &val1);
    val1 = div_with_remainder(val1, val2, &quotient);
    *exp_shift += 1;

    mul_big_decimal(*result, ten, result);
    add_big_decimal(*result, quotient, result);
  }
}

int mul_big_decimal(my_big_decimal val1, my_big_decimal val2,
                    my_big_decimal *result) {
  int error = 0;
  my_big_decimal buf1 = {{0}};

  int *ptr_val1 = (int *)&val1;
  int *ptr_val2 = (int *)&val2;

  for (int item = 7; item >= 0; item--) {  // 8 ints in big_decimal
    for (unsigned bit = 0; bit < sizeof(int) * 8; bit++) {  // 8 bits in byte
      if (get_bit(ptr_val2[item], bit) == 1) {
        my_big_decimal buf2 = {{0}};
        memcpy(&buf2, ptr_val1, sizeof(buf2));
        int count =
            (7 - item) * 32 + bit;  // 32 bits in int, 8 ints in big_decimal
        error = shift_big_decimal(buf2, count, &buf2);
        add_big_decimal(buf1, buf2, &buf1);
      }
    }
    memcpy(result, &buf1, sizeof(*result));
  }

  return error;
}

void normalize(my_decimal val, int power, my_big_decimal *result) {
  my_big_decimal ten = {{0, 0, 0, 0, 0, 0, 0, 10}};
  my_big_decimal buf;
  get_big_decimal(val, &buf);

  while (power-- > 0) {
    mul_big_decimal(buf, ten, result);
    memcpy(&buf, result, sizeof(buf));
  }
}

int cmp_big_decimal(my_big_decimal val1, my_big_decimal val2) {
  int result = 0;
  int *ptr_val1 = (int *)&val1;
  int *ptr_val2 = (int *)&val2;
  for (int i = 0; i < 8 && result == 0; i++) {  // 8 ints in big_decimal
    unsigned v_1 = ptr_val1[i], v_2 = ptr_val2[i];
    if (v_1 < v_2) result = -1;
    if (v_1 > v_2) result = 1;
  }
  return result;
}

void set_empty_decimal(my_decimal *decimal) {
  for (int i = 0; i < 4; i++) {
    decimal->bits[i] = 0;
  }
}

int cmp_decimal(my_decimal val1, my_decimal val2) {
  int sign1 = get_sign(val1);
  int sign2 = get_sign(val2);
  int cmp_result = 0;

  if (!is_empty_decimal(val1) || !is_empty_decimal(val2)) {
    if (sign1 < sign2)
      cmp_result++;
    else if (sign1 > sign2)
      cmp_result--;
    else {
      int power_1 = get_exponent(val1);
      int power_2 = get_exponent(val2);

      my_big_decimal norm_val1, norm_val2;
      if (power_1 < power_2) {
        normalize(val1, power_2 - power_1, &norm_val1);
        get_big_decimal(val2, &norm_val2);
      } else if (power_2 < power_1) {
        normalize(val2, power_1 - power_2, &norm_val2);
        get_big_decimal(val1, &norm_val1);
      } else {
        get_big_decimal(val1, &norm_val1);
        get_big_decimal(val2, &norm_val2);
      }

      cmp_result = cmp_big_decimal(norm_val1, norm_val2);
      if (sign1 == 1 && sign2 == 1) cmp_result = -cmp_result;
    }
  }

  return cmp_result;
}

int get_bit(int number, int index) { return number >> index & 1; }

void set_bit(int *number, int index, int value) {
  if (value == 1) *number = 1 << index | *number;
  if (value == 0) *number = ~(1 << index) & *number;
}

my_decimal get_ten(void) {
  my_decimal result = init_empty_decimal();
  result.bits[0] = 10;

  return result;
}

my_decimal get_one(void) {
  my_decimal result = init_empty_decimal();
  result.bits[0] = 1;

  return result;
}

void set_sign(my_decimal *value, int sign) {
  set_bit(&(value->bits[3]), 31, sign);
}

my_big_decimal div_with_remainder(my_big_decimal val1, my_big_decimal val2,
                                  my_big_decimal *result) {
  my_big_decimal quotient, remainder;
  get_big_decimal(init_empty_decimal(), &quotient);
  get_big_decimal(init_empty_decimal(), &remainder);
  memset(result, 0, sizeof(*result));

  if (cmp_big_decimal(val1, val2) >= 0) {
    quotient.bits[7] = 1;
  }

  if (cmp_big_decimal(val1, val2) >= 0) {
    while (cmp_big_decimal(val1, val2) >= 0) {
      memset(&quotient, 0, sizeof(quotient));
      quotient.bits[7] = 1;
      my_big_decimal modified_val2 = val2;

      while (cmp_big_decimal(val1, modified_val2) >= 0 &&
             !get_bit_big_decimal(val1, 31)) {
        shift_big_decimal(modified_val2, 1, &modified_val2);
        shift_big_decimal(quotient, 1, &quotient);
      }

      if ((cmp_big_decimal(modified_val2, val1) >= 0)) {
        shift_big_decimal_right(modified_val2, 1, &modified_val2);
        shift_big_decimal_right(quotient, 1, &quotient);
      }

      sub_big_decimal(val1, modified_val2, &val1);
      add_big_decimal(*result, quotient, result);
    }
  }

  remainder = val1;

  return remainder;
}

int get_start_bit_big_decimal(my_big_decimal value) {
  int result_bit = 0;

  for (int i = 7; i >= 0; i--) {
    for (int j = 0; j <= 31; j++) {
      if (get_bit_big_decimal(value, i * 32 + j)) {
        result_bit = i * 32 + j;
      }
    }
  }

  return result_bit;
}

int shift_big_decimal_right(my_big_decimal val, int count,
                            my_big_decimal *result) {
  int error = 0;
  int *ptr_val = (int *)&val;
  memcpy(result, ptr_val, sizeof(*result));

  while (count-- > 0) {
    int *ptr = (int *)result;

    for (int i = 7; i >= 0; i--) {
      ptr[i] >>= 1;
      if (i != 0) {
        int bit = get_bit(ptr[i - 1], 0);
        set_bit(ptr + i, 31, bit);
      }
    }
  }

  return error;
}