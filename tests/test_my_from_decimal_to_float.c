#include "my_tests.h"

START_TEST(test_from_decimal_to_float_1) {
  my_decimal value = {{0, 0, 0, 0}};  // 0
  float system_result = 0.0;
  float my_result;

  my_from_decimal_to_float(value, &my_result);

  ck_assert_float_eq_tol(my_result, system_result, 0.0000001);
}
END_TEST

START_TEST(test_from_decimal_to_float_2) {
  my_decimal value = {{0x00000001, 0, 0, 0}};  // 1
  float system_result = 1.0;
  float my_result;

  my_from_decimal_to_float(value, &my_result);

  ck_assert_float_eq_tol(my_result, system_result, 0.0000001);
}
END_TEST

START_TEST(test_from_decimal_to_float_3) {
  my_decimal value = {{0x00000001, 0, 0, 0x80000000}};  // -1
  float system_result = -1.0;
  float my_result;

  my_from_decimal_to_float(value, &my_result);

  ck_assert_float_eq_tol(my_result, system_result, 0.0000001);
}
END_TEST

START_TEST(test_from_decimal_to_float_4) {
  my_decimal value = {{0x0000000F, 0, 0, 0x80010000}};  // -1.5
  float system_result = -1.5;
  float my_result;

  my_from_decimal_to_float(value, &my_result);

  ck_assert_float_eq_tol(my_result, system_result, 0.0000001);
}
END_TEST

START_TEST(test_from_decimal_to_float_5) {
  my_decimal value = {{7, 0, 0, 0x00010000}};  // 0.7
  float system_result = 0.7;
  float my_result;

  my_from_decimal_to_float(value, &my_result);

  ck_assert_float_eq_tol(my_result, system_result, 0.0000001);
}
END_TEST

START_TEST(test_from_decimal_to_float_6) {
  my_decimal value = {{0x075BCD15, 0, 0, 0x80090000}};  // 0.123456789
  float system_result = -0.123456789;
  float my_result;

  my_from_decimal_to_float(value, &my_result);

  ck_assert_float_eq_tol(my_result, system_result, 0.0000001);
}
END_TEST

START_TEST(test_from_decimal_to_float_7) {
  my_decimal value = {{0xFFFFFFFF, 0, 0, 0x00060000}};  // 4294.967295
  float system_result = 4294.967295;
  float my_result;

  my_from_decimal_to_float(value, &my_result);

  ck_assert_float_eq_tol(my_result, system_result, 0.0000001);
}
END_TEST

START_TEST(test_from_decimal_to_float_8) {
  my_decimal value = {{999999, 0, 0, 0x00050000}};  // 9.99999
  float system_result = 9.99999;
  float my_result;

  my_from_decimal_to_float(value, &my_result);

  ck_assert_float_eq_tol(my_result, system_result, 0.0000001);
}
END_TEST

START_TEST(test_from_decimal_to_float_9) {
  my_decimal value = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0}};  // 79228162514264337593543950335
  float system_result = 79228162514264337593543950335.0;
  float my_result;

  my_from_decimal_to_float(value, &my_result);

  ck_assert_float_eq_tol(my_result, system_result, 0.0000001);
}
END_TEST

START_TEST(test_from_decimal_to_float_10) {
  my_decimal value = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0x80000000}};  // -79228162514264337593543950335
  float system_result = -79228162514264337593543950335.0;
  float my_result;

  my_from_decimal_to_float(value, &my_result);

  ck_assert_float_eq_tol(my_result, system_result, 0.0000001);
}
END_TEST

START_TEST(test_from_decimal_to_float_11) {
  my_decimal value = {{2, 0, 0, 0x00140000}};  // 0.00000000000000000002
  float system_result = 0.00000000000000000002;
  float my_result;

  my_from_decimal_to_float(value, &my_result);

  ck_assert_float_eq_tol(my_result, system_result, 0.0000001);
}
END_TEST

START_TEST(test_from_decimal_to_float_12) {
  my_decimal value = {{0x000000D3, 0x00007C45, 0x00007C57,
                       0x80080000}};  // -5871783107468845.32076755
  float system_result = -5871783107468845.32076755;
  float my_result;

  my_from_decimal_to_float(value, &my_result);

  ck_assert_float_eq_tol(my_result, system_result, 0.0000001);
}
END_TEST

START_TEST(test_from_decimal_to_float_13) {
  my_decimal value = {{0, 0, 0, 0x800A0000}};  // 0.0000000000
  float system_result = 0.0000000000;
  float my_result;

  my_from_decimal_to_float(value, &my_result);

  ck_assert_float_eq_tol(my_result, system_result, 0.0000001);
}
END_TEST

START_TEST(test_from_decimal_to_float_14) {
  my_decimal value = {
      {0x1FC40A5D, 0xA98FD4BE, 0, 0x80020000}};  // -122182182271212611.49
  float system_result = -122182182271212611.49;
  float my_result;

  my_from_decimal_to_float(value, &my_result);

  ck_assert_float_eq_tol(my_result, system_result, 0.0000001);
}
END_TEST

START_TEST(test_from_decimal_to_float_15) {
  my_decimal value = {{0x075BCD15, 0, 0, 0x00120000}};  // 0.000000000123456789
  float system_result = 0.000000000123456789;
  float my_result;

  my_from_decimal_to_float(value, &my_result);

  ck_assert_float_eq_tol(my_result, system_result, 0.0000001);
}
END_TEST

Suite* suite_from_decimal_to_float(void) {
  Suite* suite = suite_create("my_from_decimal_to_float");
  TCase* tc_my_from_decimal_to_float;

  tc_my_from_decimal_to_float = tcase_create("tc_my_from_decimal_to_float");
  tcase_add_test(tc_my_from_decimal_to_float, test_from_decimal_to_float_1);
  tcase_add_test(tc_my_from_decimal_to_float, test_from_decimal_to_float_2);
  tcase_add_test(tc_my_from_decimal_to_float, test_from_decimal_to_float_3);
  tcase_add_test(tc_my_from_decimal_to_float, test_from_decimal_to_float_4);
  tcase_add_test(tc_my_from_decimal_to_float, test_from_decimal_to_float_5);
  tcase_add_test(tc_my_from_decimal_to_float, test_from_decimal_to_float_6);
  tcase_add_test(tc_my_from_decimal_to_float, test_from_decimal_to_float_7);
  tcase_add_test(tc_my_from_decimal_to_float, test_from_decimal_to_float_8);
  tcase_add_test(tc_my_from_decimal_to_float, test_from_decimal_to_float_9);
  tcase_add_test(tc_my_from_decimal_to_float, test_from_decimal_to_float_10);
  tcase_add_test(tc_my_from_decimal_to_float, test_from_decimal_to_float_11);
  tcase_add_test(tc_my_from_decimal_to_float, test_from_decimal_to_float_12);
  tcase_add_test(tc_my_from_decimal_to_float, test_from_decimal_to_float_13);
  tcase_add_test(tc_my_from_decimal_to_float, test_from_decimal_to_float_14);
  tcase_add_test(tc_my_from_decimal_to_float, test_from_decimal_to_float_15);

  suite_add_tcase(suite, tc_my_from_decimal_to_float);

  return suite;
}