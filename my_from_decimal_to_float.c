#include "my_decimal.h"

int my_from_decimal_to_float(my_decimal src, float *dst) {
  int error_code = 0;
  *dst = 0.0;

  double value = (double)*dst;
  int sign = get_sign(src);
  int exponent = get_exponent(src);

  for (int i = 95; i >= 0; i--) {
    value += get_bit_mantissa(src, i) * pow(2, i);
  }

  value *= pow(10, exponent * (-1));

  if (sign) {
    value *= -1;
  }

  *dst = value;

  return error_code;
}