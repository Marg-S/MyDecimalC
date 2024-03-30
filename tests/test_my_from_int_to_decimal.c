#include "my_tests.h"

START_TEST(test_from_int_to_decimal_1) {
  int value = 0;
  my_decimal system_result = {{0, 0, 0, 0}};
  my_decimal my_result;

  int error = my_from_int_to_decimal(value, &my_result);

  ck_assert_int_eq(error, 0);
  ck_assert_mem_eq(&my_result, &system_result, sizeof(my_decimal));
}
END_TEST

START_TEST(test_from_int_to_decimal_2) {
  int value = 1;
  my_decimal system_result = {{0x00000001, 0, 0, 0}};
  my_decimal my_result;

  int error = my_from_int_to_decimal(value, &my_result);

  ck_assert_int_eq(error, 0);
  ck_assert_mem_eq(&my_result, &system_result, sizeof(my_decimal));
}
END_TEST

START_TEST(test_from_int_to_decimal_3) {
  int value = -1;
  my_decimal system_result = {{0x00000001, 0, 0, 0x80000000}};
  my_decimal my_result;

  int error = my_from_int_to_decimal(value, &my_result);

  ck_assert_int_eq(error, 0);
  ck_assert_mem_eq(&my_result, &system_result, sizeof(my_decimal));
}
END_TEST

START_TEST(test_from_int_to_decimal_4) {
  int value = 100;
  my_decimal system_result = {{0x00000064, 0, 0, 0}};
  my_decimal my_result;

  int error = my_from_int_to_decimal(value, &my_result);

  ck_assert_int_eq(error, 0);
  ck_assert_mem_eq(&my_result, &system_result, sizeof(my_decimal));
}
END_TEST

START_TEST(test_from_int_to_decimal_5) {
  int value = -100;
  my_decimal system_result = {{0x00000064, 0, 0, 0x80000000}};
  my_decimal my_result;

  int error = my_from_int_to_decimal(value, &my_result);

  ck_assert_int_eq(error, 0);
  ck_assert_mem_eq(&my_result, &system_result, sizeof(my_decimal));
}
END_TEST

START_TEST(test_from_int_to_decimal_6) {
  int value = 123456789;
  my_decimal system_result = {{0x075BCD15, 0, 0, 0}};
  my_decimal my_result;

  int error = my_from_int_to_decimal(value, &my_result);

  ck_assert_int_eq(error, 0);
  ck_assert_mem_eq(&my_result, &system_result, sizeof(my_decimal));
}
END_TEST

START_TEST(test_from_int_to_decimal_7) {
  int value = -987654321;
  my_decimal system_result = {{987654321, 0, 0, 0x80000000}};
  my_decimal my_result;

  int error = my_from_int_to_decimal(value, &my_result);

  ck_assert_int_eq(error, 0);
  ck_assert_mem_eq(&my_result, &system_result, sizeof(my_decimal));
}
END_TEST

START_TEST(test_from_int_to_decimal_error) {
  int value = -987654321;
  my_decimal* my_result = NULL;

  int error = my_from_int_to_decimal(value, my_result);

  ck_assert_int_eq(error, 1);
}
END_TEST

Suite* suite_from_int_to_decimal(void) {
  Suite* suite = suite_create("my_from_int_to_decimal");
  TCase* tc_my_from_int_to_decimal;

  tc_my_from_int_to_decimal = tcase_create("tc_my_from_int_to_decimal");
  tcase_add_test(tc_my_from_int_to_decimal, test_from_int_to_decimal_1);
  tcase_add_test(tc_my_from_int_to_decimal, test_from_int_to_decimal_2);
  tcase_add_test(tc_my_from_int_to_decimal, test_from_int_to_decimal_3);
  tcase_add_test(tc_my_from_int_to_decimal, test_from_int_to_decimal_4);
  tcase_add_test(tc_my_from_int_to_decimal, test_from_int_to_decimal_5);
  tcase_add_test(tc_my_from_int_to_decimal, test_from_int_to_decimal_6);
  tcase_add_test(tc_my_from_int_to_decimal, test_from_int_to_decimal_7);
  tcase_add_test(tc_my_from_int_to_decimal, test_from_int_to_decimal_error);

  suite_add_tcase(suite, tc_my_from_int_to_decimal);

  return suite;
}
