#include "my_decimal.h"

int my_add(my_decimal value_1, my_decimal value_2, my_decimal* result) {
  int error_code = 0;
  set_empty_decimal(result);

  int sign_1 = get_sign(value_1);
  int sign_2 = get_sign(value_2);

  int exp_1 = get_exponent(value_1);
  int exp_2 = get_exponent(value_2);
  int exp_diff = exp_1 - exp_2;
  int exp = exp_1;

  my_big_decimal norm_val1, norm_val2, result_big_decimal;
  get_big_decimal(*result, &result_big_decimal);

  if (sign_1 == sign_2) {
    if (exp_diff > 0) {
      normalize(value_2, exp_diff, &norm_val2);
      get_big_decimal(value_1, &norm_val1);
    } else if (exp_diff < 0) {
      normalize(value_1, -exp_diff, &norm_val1);
      get_big_decimal(value_2, &norm_val2);
      exp = exp_2;
    } else {
      get_big_decimal(value_1, &norm_val1);
      get_big_decimal(value_2, &norm_val2);
    }

    add_big_decimal(norm_val1, norm_val2, &result_big_decimal);
    error_code = get_decimal(result_big_decimal, &exp, result);
    set_exponent(result, exp);

    if (sign_1 == 1) set_sign(result, sign_1);
    if (error_code || exp > 28 || exp < 0) {
      error_code = get_sign(*result) ? 2 : 1;
    }
  } else if (sign_1) {
    set_sign(&value_1, 0);
    error_code = my_sub(value_2, value_1, result);
  } else {
    set_sign(&value_2, 0);
    error_code = my_sub(value_1, value_2, result);
  }

  return error_code;
}