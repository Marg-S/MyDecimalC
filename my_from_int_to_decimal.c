#include "my_decimal.h"

int my_from_int_to_decimal(int src, my_decimal *dst) {
  int error = 0;
  if (dst == NULL) {
    error = 1;
  } else {
    set_empty_decimal(dst);

    if (src >= 0) {
      dst->bits[0] = src;
    } else {
      set_sign(dst, 1);
      dst->bits[0] = -src;
    }
  }

  return error;
}
