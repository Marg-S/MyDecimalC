#ifndef MY_TESTS_DECIMAL
#define MY_TESTS_DECIMAL

#include <check.h>
#include <stdio.h>

#include "../my_decimal.h"

Suite *suite_add(void);
Suite *suite_utils(void);
Suite *suite_cmp(void);
Suite *suite_mul(void);
Suite *suite_sub(void);
Suite *suite_from_float_to_decimal(void);
Suite *suite_div(void);
Suite *suite_from_int_to_decimal(void);
Suite *suite_from_float_to_decimal(void);
Suite *suite_from_decimal_to_int(void);
Suite *suite_from_decimal_to_float(void);
Suite *suite_floor(void);
Suite *suite_round(void);
Suite *suite_truncate(void);
Suite *suite_negate(void);

#endif  // MY_TESTS_DECIMAL
