#include "my_decimal.h"

int get_count_digits(my_decimal dst) {
  my_big_decimal ten = {{0, 0, 0, 0, 0, 0, 0, 10}};
  int count = 0;

  my_big_decimal buf = {{0}};
  get_big_decimal(dst, &buf);

  for (; !is_empty_big_decimal(buf); count++)
    div_with_remainder(buf, ten, &buf);

  return count;
}

void truncate_zero(my_big_decimal *value, int *power) {
  my_big_decimal remainder = {{0}};
  my_big_decimal ten = {{0, 0, 0, 0, 0, 0, 0, 10}};

  while (remainder.bits[7] == 0 && *power > 0) {
    remainder = div_with_remainder(*value, ten, value);
    (*power)--;
  }

  if (remainder.bits[7] != 0) {
    mul_big_decimal(*value, ten, value);
    add_big_decimal(*value, remainder, value);
    (*power)++;
  }
}

int truncate_digits(my_decimal *dst, int count_truncate) {
  int error = 0;
  my_big_decimal buf = {{0}};
  get_big_decimal(*dst, &buf);

  int count_zero = 0, remainder = 0;
  int power = get_exponent(*dst);
  my_big_decimal ten = {{0, 0, 0, 0, 0, 0, 0, 10}};

  while (count_truncate-- > 0) {
    remainder = div_with_remainder(buf, ten, &buf).bits[7];
    if (power > 0)
      power--;
    else
      count_zero++;
  }

  my_big_decimal one = {{0, 0, 0, 0, 0, 0, 0, 1}};
  if (remainder >= 5) add_big_decimal(buf, one, &buf);

  while (count_zero-- > 0) mul_big_decimal(buf, ten, &buf);

  truncate_zero(&buf, &power);
  error = get_decimal(buf, &power, dst);
  set_exponent(dst, power);

  return error;
}

int my_from_float_to_decimal(float src, my_decimal *dst) {
  memset(dst, 0, sizeof(*dst));
  int error = 0;
  int *float_value = (int *)&src;

  if (src != src || src >= __FLT_MAX__ || src <= -__FLT_MAX__) error = 1;
  if (src != 0 && error == 0) {
    dst->bits[0] = (*float_value & 0x7fffff) | 0x800000;
    int exponent = ((*float_value >> 23) & 0xff) - 127 - 23;

    int buf_exponent = (exponent < 0) ? -exponent : exponent;
    for (int i = 0; buf_exponent > 0 && !error; buf_exponent -= i) {
      i = (buf_exponent > 31) ? 31 : buf_exponent;
      my_decimal term = {{1 << i, 0, 0, 0}};
      if (exponent < 0)
        error = my_div(*dst, term, dst);
      else
        error = my_mul(*dst, term, dst);
    }

    if (error == 0) {
      int count_truncate = get_count_digits(*dst) - 7;
      error = truncate_digits(dst, count_truncate);
      if (is_empty_decimal(*dst) || get_exponent(*dst) > 28) error++;
    }
  }

  if (!error) set_sign(dst, get_bit(*float_value, 31));

  return error;
}