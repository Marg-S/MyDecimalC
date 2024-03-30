#ifndef MY_DECIMAL
#define MY_DECIMAL

#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int bits[4];
} my_decimal;

typedef struct {
  int bits[8];
} my_big_decimal;

int my_add(my_decimal value_1, my_decimal value_2, my_decimal *result);
int my_sub(my_decimal value_1, my_decimal value_2, my_decimal *result);
int my_mul(my_decimal value_1, my_decimal value_2, my_decimal *result);
int my_div(my_decimal value_1, my_decimal value_2, my_decimal *result);

int my_is_less(my_decimal, my_decimal);
int my_is_less_or_equal(my_decimal, my_decimal);
int my_is_greater(my_decimal, my_decimal);
int my_is_greater_or_equal(my_decimal, my_decimal);
int my_is_equal(my_decimal, my_decimal);
int my_is_not_equal(my_decimal, my_decimal);

int my_from_int_to_decimal(int src, my_decimal *dst);
int my_from_float_to_decimal(float src, my_decimal *dst);
int my_from_decimal_to_int(my_decimal src, int *dst);
int my_from_decimal_to_float(my_decimal src, float *dst);

int my_floor(my_decimal value, my_decimal *result);
int my_round(my_decimal value, my_decimal *result);
int my_truncate(my_decimal value, my_decimal *result);
int my_negate(my_decimal value, my_decimal *result);

// Utils
my_decimal init_empty_decimal();
int is_empty_decimal(my_decimal decimal);
void set_empty_decimal(my_decimal *decimal);
void normalize(my_decimal val, int power, my_big_decimal *result);
int get_decimal(my_big_decimal value, int *power, my_decimal *result);
int cmp_decimal(my_decimal val1, my_decimal val2);
my_decimal init_empty_decimal();

void get_big_decimal(my_decimal val, my_big_decimal *result);
void add_big_decimal(my_big_decimal val1, my_big_decimal val2,
                     my_big_decimal *result);
void sub_big_decimal(my_big_decimal val1, my_big_decimal val2,
                     my_big_decimal *result);
void div_big_decimal(my_big_decimal val1, my_big_decimal val2,
                     my_big_decimal *result, int *exp_shift);
my_big_decimal div_with_remainder(my_big_decimal val1, my_big_decimal val2,
                                  my_big_decimal *result);
int mul_big_decimal(my_big_decimal val1, my_big_decimal val2,
                    my_big_decimal *result);
int shift_big_decimal(my_big_decimal val, int count, my_big_decimal *result);
int shift_big_decimal_right(my_big_decimal val, int count,
                            my_big_decimal *result);
int cmp_big_decimal(my_big_decimal val1, my_big_decimal val2);
my_big_decimal div_with_remainder(my_big_decimal val1, my_big_decimal val2,
                                  my_big_decimal *result);
int get_start_bit_big_decimal(my_big_decimal value);
int is_empty_big_decimal(my_big_decimal decimal);
int get_bit_big_decimal(my_big_decimal value, int position);
int shift_big_decimal_right(my_big_decimal val, int count,
                            my_big_decimal *result);

int get_sign(my_decimal value);
void set_sign(my_decimal *value, int sign);
int get_exponent(my_decimal value);
void set_exponent(my_decimal *value, int exponent);
int get_bit(int number, int index);
void set_bit(int *number, int index, int value);

int get_bit_mantissa(my_decimal value, int position);

my_decimal get_ten(void);
my_decimal get_one(void);

#endif  // MY_DECIMAL

int is_max_decimal(my_big_decimal value);
