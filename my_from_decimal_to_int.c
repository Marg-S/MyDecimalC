#include "my_decimal.h"

int my_from_decimal_to_int(my_decimal src, int *dst) {
  my_decimal cut = {0};  // структура хранения обрезки
  int error = my_truncate(src, &cut);  // обрезаем src и в cut и в result 0||1
  int sign = get_sign(src);            // узнать знак src
  set_bit(&cut.bits[0], 31, 0);

  if (cut.bits[1] || cut.bits[2]) {
    *dst = 0;
    if (cut.bits[1] == 1 && !cut.bits[2] && sign) {
      *dst = 0x7fffffff;
    }
  } else {
    *dst = cut.bits[0];

    if (sign) {
      *dst = -(*dst);
    }
  }

  return error;
}