#include "my_decimal.h"

int my_floor(my_decimal value, my_decimal *result) {
  int error_code = 0;
  int sign = get_sign(value);
  my_decimal one = get_one();

  set_empty_decimal(result);

  my_truncate(value, result);

  if (!my_is_equal(value, *result) && sign == 1) {
    my_sub(*result, one, result);
  }

  return error_code;
}