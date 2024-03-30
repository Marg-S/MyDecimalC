#include "my_decimal.h"

int my_sub(my_decimal value_1, my_decimal value_2, my_decimal *result) {
  int error = 0;
  memset(result, 0, sizeof(*result));

  int sign1 = get_sign(value_1);
  int sign2 = get_sign(value_2);

  int power_1 = get_exponent(value_1);
  int power_2 = get_exponent(value_2);
  int power_result = (power_1 > power_2) ? power_1 : power_2;

  my_big_decimal norm_val1, norm_val2;
  if (power_1 < power_2) {
    normalize(value_1, power_2 - power_1, &norm_val1);
    get_big_decimal(value_2, &norm_val2);
  } else if (power_1 > power_2) {
    normalize(value_2, power_1 - power_2, &norm_val2);
    get_big_decimal(value_1, &norm_val1);
  } else {
    get_big_decimal(value_1, &norm_val1);
    get_big_decimal(value_2, &norm_val2);
  }

  my_big_decimal buf_result = {{0}};
  if (sign1 != sign2) {
    add_big_decimal(norm_val1, norm_val2, &buf_result);
    set_sign(result, get_sign(value_1));
  } else {
    if (cmp_big_decimal(norm_val1, norm_val2) >= 0) {
      sub_big_decimal(norm_val1, norm_val2, &buf_result);
      set_sign(result, get_sign(value_1));
    } else {
      sub_big_decimal(norm_val2, norm_val1, &buf_result);
      set_sign(result, !get_sign(value_1));
    }
  }

  error = get_decimal(buf_result, &power_result, result);

  set_exponent(result, power_result);

  if (error == 1 && get_sign(*result) == 1) error = 2;

  return error;
}
