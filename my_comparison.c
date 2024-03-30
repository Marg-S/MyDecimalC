#include "my_decimal.h"

int my_is_less(my_decimal val1, my_decimal val2) {
  int cmp_result = cmp_decimal(val1, val2);
  return (cmp_result < 0);
}

int my_is_less_or_equal(my_decimal val1, my_decimal val2) {
  int cmp_result = cmp_decimal(val1, val2);
  return (cmp_result < 0 || cmp_result == 0);
}

int my_is_greater(my_decimal val1, my_decimal val2) {
  int cmp_result = cmp_decimal(val1, val2);
  return (cmp_result > 0);
}

int my_is_greater_or_equal(my_decimal val1, my_decimal val2) {
  int cmp_result = cmp_decimal(val1, val2);
  return (cmp_result > 0 || cmp_result == 0);
}

int my_is_equal(my_decimal val1, my_decimal val2) {
  int cmp_result = cmp_decimal(val1, val2);
  return (cmp_result == 0);
}

int my_is_not_equal(my_decimal val1, my_decimal val2) {
  int cmp_result = cmp_decimal(val1, val2);
  return (cmp_result != 0);
}
