#include "my_tests.h"

START_TEST(test_from_decimal_to_int_1) {
  my_decimal value = {{0, 0, 0, 0}};  // 0
  int system_result = 0;
  int my_result;

  int error = my_from_decimal_to_int(value, &my_result);

  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(my_result, system_result);
}
END_TEST

START_TEST(test_from_decimal_to_int_2) {
  my_decimal value = {{0x00000001, 0, 0, 0}};  // 1
  int system_result = 1;
  int my_result;

  int error = my_from_decimal_to_int(value, &my_result);

  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(my_result, system_result);
}
END_TEST

START_TEST(test_from_decimal_to_int_3) {
  my_decimal value = {{0x00000001, 0, 0, 0x80000000}};  // -1
  int system_result = -1;
  int my_result;

  int error = my_from_decimal_to_int(value, &my_result);

  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(my_result, system_result);
}
END_TEST

START_TEST(test_from_decimal_to_int_4) {
  my_decimal value = {{0x0000000F, 0, 0, 0x80010000}};  // -1.5
  int system_result = -1;
  int my_result;

  int error = my_from_decimal_to_int(value, &my_result);

  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(my_result, system_result);
}
END_TEST

START_TEST(test_from_decimal_to_int_5) {
  my_decimal value = {{7, 0, 0, 0x00010000}};  // 0.7
  int system_result = 0;
  int my_result;

  int error = my_from_decimal_to_int(value, &my_result);

  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(my_result, system_result);
}
END_TEST

START_TEST(test_from_decimal_to_int_6) {
  my_decimal value = {{0x075BCD15, 0, 0, 0x80090000}};  // 0.123456789
  int system_result = 0;
  int my_result;

  int error = my_from_decimal_to_int(value, &my_result);

  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(my_result, system_result);
}
END_TEST

START_TEST(test_from_decimal_to_int_7) {
  my_decimal value = {{0xFFFFFFFF, 0, 0, 0x00060000}};  // 4294.967295
  int system_result = 4294;
  int my_result;

  int error = my_from_decimal_to_int(value, &my_result);

  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(my_result, system_result);
}
END_TEST

START_TEST(test_from_decimal_to_int_8) {
  my_decimal value = {{999999, 0, 0, 0x00050000}};  // 9.99999
  int system_result = 9;
  int my_result;

  int error = my_from_decimal_to_int(value, &my_result);

  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(my_result, system_result);
}
END_TEST

START_TEST(test_from_decimal_to_int_9) {
  my_decimal value = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0}};  // 79228162514264337593543950335
  int system_result = 0;
  int my_result;

  int error = my_from_decimal_to_int(value, &my_result);

  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(my_result, system_result);
}
END_TEST

START_TEST(test_from_decimal_to_int_10) {
  my_decimal value = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0x80000000}};  // -79228162514264337593543950335
  int system_result = 0;
  int my_result;

  int error = my_from_decimal_to_int(value, &my_result);

  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(my_result, system_result);
}
END_TEST

START_TEST(test_from_decimal_to_int_11) {
  my_decimal value = {{2, 0, 0, 0x00140000}};  // 0.00000000000000000002
  int system_result = 0;
  int my_result;

  int error = my_from_decimal_to_int(value, &my_result);

  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(my_result, system_result);
}
END_TEST

START_TEST(test_from_decimal_to_int_12) {
  my_decimal value = {{0x00000000, 0x00000001, 0x00000000, 0x00000000}};
  int system_result = 0;
  int my_result;

  int error = my_from_decimal_to_int(value, &my_result);

  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(my_result, system_result);
}
END_TEST

START_TEST(test_from_decimal_to_int_13) {  // 4294967295.999
  my_decimal value = {{0xFFFFFFFF, 0x000003E7, 0x00000000, 0x00030000}};
  int system_result = 2147483647;
  int my_result;

  int error = my_from_decimal_to_int(value, &my_result);

  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(my_result, system_result);
}
END_TEST

START_TEST(test_from_decimal_to_int_14) {  // -4294967295.999
  my_decimal value = {{0xFFFFFFFF, 0x000003E7, 0x00000000, 0x80030000}};
  int system_result = -2147483647;
  int my_result;

  int error = my_from_decimal_to_int(value, &my_result);

  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(my_result, system_result);
}
END_TEST

START_TEST(test_from_decimal_to_int_15) {  // -4294967296
  my_decimal value = {{0x00000000, 0x00000001, 0x00000000, 0x80000000}};
  int system_result = 2147483647;
  int my_result;

  int error = my_from_decimal_to_int(value, &my_result);

  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(my_result, system_result);
}
END_TEST

Suite* suite_from_decimal_to_int(void) {
  Suite* suite = suite_create("my_from_decimal_to_int");
  TCase* tc_my_from_decimal_to_int;

  tc_my_from_decimal_to_int = tcase_create("tc_my_from_decimal_to_int");
  tcase_add_test(tc_my_from_decimal_to_int, test_from_decimal_to_int_1);
  tcase_add_test(tc_my_from_decimal_to_int, test_from_decimal_to_int_2);
  tcase_add_test(tc_my_from_decimal_to_int, test_from_decimal_to_int_3);
  tcase_add_test(tc_my_from_decimal_to_int, test_from_decimal_to_int_4);
  tcase_add_test(tc_my_from_decimal_to_int, test_from_decimal_to_int_5);
  tcase_add_test(tc_my_from_decimal_to_int, test_from_decimal_to_int_6);
  tcase_add_test(tc_my_from_decimal_to_int, test_from_decimal_to_int_7);
  tcase_add_test(tc_my_from_decimal_to_int, test_from_decimal_to_int_8);
  tcase_add_test(tc_my_from_decimal_to_int, test_from_decimal_to_int_9);
  tcase_add_test(tc_my_from_decimal_to_int, test_from_decimal_to_int_10);
  tcase_add_test(tc_my_from_decimal_to_int, test_from_decimal_to_int_11);
  tcase_add_test(tc_my_from_decimal_to_int, test_from_decimal_to_int_12);
  tcase_add_test(tc_my_from_decimal_to_int, test_from_decimal_to_int_13);
  tcase_add_test(tc_my_from_decimal_to_int, test_from_decimal_to_int_14);
  tcase_add_test(tc_my_from_decimal_to_int, test_from_decimal_to_int_15);

  suite_add_tcase(suite, tc_my_from_decimal_to_int);

  return suite;
}
