#include "my_tests.h"

START_TEST(test_utils_1) {
  my_decimal val = {{123, 456, 789, 0}};
  my_big_decimal result;
  get_big_decimal(val, &result);
  ck_assert_int_eq(result.bits[7], 123);
  ck_assert_int_eq(result.bits[6], 456);
  ck_assert_int_eq(result.bits[5], 789);
  ck_assert_int_eq(result.bits[4], 0);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[0], 0);
}
END_TEST

START_TEST(test_utils_2) {
  my_big_decimal val1 = {{0, 0, 0, 0, 0, 0, 123456, 123456}};
  my_big_decimal val2 = {{0, 0, 0, 0, 0, 0, 2, 1}};
  my_big_decimal result;
  add_big_decimal(val1, val2, &result);
  ck_assert_int_eq(result.bits[7], 123457);
  ck_assert_int_eq(result.bits[6], 123458);
  ck_assert_int_eq(result.bits[5], 0);
  ck_assert_int_eq(result.bits[4], 0);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[0], 0);
}
END_TEST

START_TEST(test_utils_3) {
  my_big_decimal val1 = {{0, 0, 0, 0, 0, 0, 0, 10}};
  my_big_decimal val2 = {{0, 0, 0, 0, 0, 0, 0, 100}};
  my_big_decimal result;
  mul_big_decimal(val1, val2, &result);
  ck_assert_int_eq(result.bits[7], 1000);
  ck_assert_int_eq(result.bits[6], 0);
  ck_assert_int_eq(result.bits[5], 0);
  ck_assert_int_eq(result.bits[4], 0);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[0], 0);
}
END_TEST

START_TEST(test_utils_4) {
  my_decimal val = {{0, 0, 0, 0}};
  my_big_decimal result;
  normalize(val, 3, &result);
  ck_assert_int_eq(result.bits[7], 0);
  ck_assert_int_eq(result.bits[6], 0);
  ck_assert_int_eq(result.bits[5], 0);
  ck_assert_int_eq(result.bits[4], 0);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[0], 0);
}
END_TEST

START_TEST(test_utils_add_carry_1) {
  my_big_decimal val1 = {{0, 0, 0, 0, 0, 0, 123456, 0xffffffff}};
  my_big_decimal val2 = {{0, 0, 0, 0, 0, 0, 2, 1}};
  my_big_decimal result;
  add_big_decimal(val1, val2, &result);
  ck_assert_int_eq(result.bits[7], 0);
  ck_assert_int_eq(result.bits[6], 123459);
  ck_assert_int_eq(result.bits[5], 0);
  ck_assert_int_eq(result.bits[4], 0);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[0], 0);
}
END_TEST

START_TEST(test_utils_add_carry_2) {
  my_big_decimal val1 = {
      {0, 0, 0, 0, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff}};
  my_big_decimal val2 = {
      {0, 0, 0, 1, 0xffffffff, 0xffffffff, 0xffffffff, 0xfffffffe}};
  my_big_decimal result;
  add_big_decimal(val1, val2, &result);
  ck_assert_int_eq(result.bits[7], -3);
  ck_assert_int_eq(result.bits[6], -1);
  ck_assert_int_eq(result.bits[5], -1);
  ck_assert_int_eq(result.bits[4], -1);
  ck_assert_int_eq(result.bits[3], 2);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[0], 0);
}
END_TEST

START_TEST(test_utils_add_carry_3) {
  my_big_decimal val1 = {{0, 0, 0, 0, 0xffffffff, 0, 0xffffffff, 0xffffffff}};
  my_big_decimal val2 = {{0, 0, 0, 0, 0xffffffff, 0, 0xffffffff, 0xffffffff}};
  my_big_decimal result;
  add_big_decimal(val1, val2, &result);
  ck_assert_int_eq(result.bits[7], -2);
  ck_assert_int_eq(result.bits[6], -1);
  ck_assert_int_eq(result.bits[5], 1);
  ck_assert_int_eq(result.bits[4], -2);
  ck_assert_int_eq(result.bits[3], 1);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[0], 0);
}
END_TEST

START_TEST(test_utils_sub_1) {
  my_big_decimal val1 = {
      {0, 0, 0, 0, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff}};
  my_big_decimal val2 = {{0, 0, 0, 0, 0, 0, 0, 1}};
  my_big_decimal result;
  sub_big_decimal(val1, val2, &result);
  ck_assert_int_eq(result.bits[7], -2);
  ck_assert_int_eq(result.bits[6], -1);
  ck_assert_int_eq(result.bits[5], -1);
  ck_assert_int_eq(result.bits[4], -1);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[0], 0);
}
END_TEST

START_TEST(test_utils_sub_2) {
  my_big_decimal val1 = {{0, 0, 0, 0, 0, 0, 123456, -127}};
  my_big_decimal val2 = {{0, 0, 0, 0, 0, 0, 2, -126}};
  my_big_decimal result;
  sub_big_decimal(val1, val2, &result);
  ck_assert_int_eq(result.bits[7], -1);
  ck_assert_int_eq(result.bits[6], 123453);
  ck_assert_int_eq(result.bits[5], 0);
  ck_assert_int_eq(result.bits[4], 0);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[0], 0);
}
END_TEST

START_TEST(test_utils_sub_3) {
  my_big_decimal val1 = {{0, 0, 0, 0, 0, 0xffffffff, 1, 0xfffffffe}};
  my_big_decimal val2 = {{0, 0, 0, 0, 0, 0xfffffffe, 1, 0xffffffff}};
  my_big_decimal result;
  sub_big_decimal(val1, val2, &result);
  ck_assert_int_eq(result.bits[7], -1);
  ck_assert_int_eq(result.bits[6], -1);
  ck_assert_int_eq(result.bits[5], 0);
  ck_assert_int_eq(result.bits[4], 0);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[0], 0);
}
END_TEST

START_TEST(test_utils_5) {
  my_big_decimal val1 = {{6, 0, 0, 0, 0, 0, 0, 5}};
  my_big_decimal val2 = {{6, 0, 0, 0, 0, 0, 0, 5}};
  ck_assert_int_eq(cmp_big_decimal(val1, val2), 0);
}
END_TEST

START_TEST(test_utils_6) {
  my_big_decimal val1 = {{5, 0, 0, 0, 0, 0, 0, 6}};
  my_big_decimal val2 = {{6, 0, 0, 0, 0, 0, 0, 5}};
  ck_assert_int_eq(cmp_big_decimal(val1, val2), -1);
}
END_TEST

START_TEST(test_utils_7) {
  my_big_decimal val1 = {{0xffffffff, 0, 0, 0, 0, 0, 0, 6}};
  my_big_decimal val2 = {{0x8fffffff, 0, 0, 0, 0, 0, 0, 5}};
  ck_assert_int_eq(cmp_big_decimal(val1, val2), 1);
}
END_TEST

START_TEST(test_div_r_3) {
  my_big_decimal val1 = {{0, 0, 0, 0, 0, 0, 0, 123456}};
  my_big_decimal val2 = {{0, 0, 0, 0, 0, 0, 0, 10}};
  my_big_decimal result;
  my_big_decimal remainder = div_with_remainder(val1, val2, &result);
  ck_assert_int_eq(result.bits[7], 12345);
  ck_assert_int_eq(remainder.bits[7], 6);
}
END_TEST

START_TEST(test_shift_5) {
  my_big_decimal val1 = {
      {0, 0, 0, 0, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff}};
  my_big_decimal result;
  shift_big_decimal(val1, 300, &result);
  ck_assert_int_eq(result.bits[7], 0);
  ck_assert_int_eq(result.bits[6], 0);
  ck_assert_int_eq(result.bits[5], 0);
  ck_assert_int_eq(result.bits[4], 0);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[0], 0);
}
END_TEST

START_TEST(test_shift_r_6) {
  my_big_decimal val1 = {
      {0, 0, 0, 0, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff}};
  my_big_decimal result;
  shift_big_decimal_right(val1, 200, &result);
  ck_assert_int_eq(result.bits[7], 0);
  ck_assert_int_eq(result.bits[6], 0);
}
END_TEST

START_TEST(test_shift_r_7) {
  my_big_decimal val1 = {{0, 0, 0, 0, 0, 0, 1, 0}};
  my_big_decimal result;
  shift_big_decimal_right(val1, 100, &result);
  ck_assert_int_eq(result.bits[7], 0);
  ck_assert_int_eq(result.bits[6], 0);
}
END_TEST

Suite* suite_utils(void) {
  Suite* suite = suite_create("my_utils");
  TCase* tc_my_utils;

  tc_my_utils = tcase_create("tc_my_utils");
  tcase_add_test(tc_my_utils, test_utils_1);
  tcase_add_test(tc_my_utils, test_utils_2);
  tcase_add_test(tc_my_utils, test_utils_add_carry_1);
  tcase_add_test(tc_my_utils, test_utils_add_carry_2);
  tcase_add_test(tc_my_utils, test_utils_add_carry_3);
  tcase_add_test(tc_my_utils, test_utils_sub_1);
  tcase_add_test(tc_my_utils, test_utils_sub_2);
  tcase_add_test(tc_my_utils, test_utils_sub_3);
  tcase_add_test(tc_my_utils, test_utils_3);
  tcase_add_test(tc_my_utils, test_utils_4);
  tcase_add_test(tc_my_utils, test_utils_5);
  tcase_add_test(tc_my_utils, test_utils_6);
  tcase_add_test(tc_my_utils, test_utils_7);
  tcase_add_test(tc_my_utils, test_div_r_3);
  tcase_add_test(tc_my_utils, test_shift_5);
  tcase_add_test(tc_my_utils, test_shift_r_6);
  tcase_add_test(tc_my_utils, test_shift_r_7);
  suite_add_tcase(suite, tc_my_utils);

  return suite;
}
