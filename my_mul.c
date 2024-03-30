#include "my_decimal.h"

int my_mul(my_decimal value_1, my_decimal value_2, my_decimal *result) {
  int error = 0;

  my_big_decimal big_val1, big_val2, buf_result;
  get_big_decimal(value_1, &big_val1);
  get_big_decimal(value_2, &big_val2);

  error = mul_big_decimal(big_val1, big_val2, &buf_result);

  int sign_result = 0;
  if (get_sign(value_1) != get_sign(value_2)) sign_result = 1;
  set_sign(result, sign_result);

  int power_result = get_exponent(value_1) + get_exponent(value_2);
  error = get_decimal(buf_result, &power_result, result);

  set_exponent(result, power_result);

  if (error == 1 && get_sign(*result) == 1) error = 2;

  return error;
}
