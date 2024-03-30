#include "my_decimal.h"

int my_div(my_decimal value_1, my_decimal value_2, my_decimal* result) {
  int error_code = 0;
  set_empty_decimal(result);

  if (is_empty_decimal(value_2)) {
    error_code = 3;
  } else if (my_is_equal(value_2, get_one())) {
    *result = value_1;
  } else if (my_is_equal(value_1, value_2)) {
    *result = get_one();
  } else if (is_empty_decimal(value_1)) {
    *result = init_empty_decimal();
  } else {
    my_big_decimal modified_value_1, modified_value_2, modified_result;
    get_big_decimal(value_1, &modified_value_1);
    get_big_decimal(value_2, &modified_value_2);
    get_big_decimal(*result, &modified_result);

    int sign_1 = get_sign(value_1);
    int sign_2 = get_sign(value_2);
    int sign_result = sign_1 ^ sign_2;

    int exp_1 = get_exponent(value_1);
    int exp_2 = get_exponent(value_2);
    int result_exp = 0;

    div_big_decimal(modified_value_1, modified_value_2, &modified_result,
                    &result_exp);
    result_exp += exp_1 - exp_2;

    if (get_decimal(modified_result, &result_exp, result)) {
      error_code = sign_result ? 2 : 1;
    } else if (result_exp < 0) {
      error_code = sign_result ? 2 : 1;
    } else {
      set_sign(result, sign_result);
      set_exponent(result, result_exp);
    }
  }

  return error_code;
}