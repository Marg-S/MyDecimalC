#include "my_decimal.h"

int my_negate(my_decimal value, my_decimal *result) {
  int error_code = 0;
  set_empty_decimal(result);
  my_decimal minus_one = get_one();
  set_sign(&minus_one, 1);

  error_code = my_mul(value, minus_one, result);

  return error_code ? 1 : 0;
}