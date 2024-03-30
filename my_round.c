#include "my_decimal.h"

int my_round(my_decimal value, my_decimal *result) {
  int error_code = 0;
  set_empty_decimal(result);

  int exp = get_exponent(value);
  int sign = get_sign(value);

  my_big_decimal ten, big_value, one;
  int remainder = 0;
  get_big_decimal(get_ten(), &ten);
  get_big_decimal(value, &big_value);
  get_big_decimal(get_one(), &one);

  for (; exp > 0; exp--) {
    remainder = div_with_remainder(big_value, ten, &big_value).bits[7];
  }

  if (remainder >= 5) {
    add_big_decimal(big_value, one, &big_value);
  }

  error_code = get_decimal(big_value, &exp, result);
  set_exponent(result, exp);
  set_sign(result, sign);

  return error_code ? 1 : 0;
}