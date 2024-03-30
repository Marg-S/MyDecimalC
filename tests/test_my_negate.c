#include "my_tests.h"

START_TEST(test_negate_1) {
  my_decimal value = {{0, 0, 0, 0}};                   // 0
  my_decimal system_result = {{0, 0, 0, 0x80000000}};  // -0
  my_decimal my_result;

  int error_code = my_negate(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_negate_2) {
  my_decimal value = {{0x00000001, 0, 0, 0}};                   // 1
  my_decimal system_result = {{0x00000001, 0, 0, 0x80000000}};  // -1
  my_decimal my_result;

  int error_code = my_negate(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_negate_3) {
  my_decimal value = {{0x00000001, 0, 0, 0x80000000}};  // -1
  my_decimal system_result = {{0x00000001, 0, 0, 0}};   // 1
  my_decimal my_result;

  int error_code = my_negate(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_negate_4) {
  my_decimal value = {{234567890, 0, 0, 0}};                   // 234567890
  my_decimal system_result = {{234567890, 0, 0, 0x80000000}};  // -234567890
  my_decimal my_result;

  int error_code = my_negate(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_negate_5) {
  my_decimal value = {
      {0xFEADBDA2, 0x000001FB, 0, 0x80060000}};  // -2181821.218210
  my_decimal system_result = {
      {0xFEADBDA2, 0x000001FB, 0, 0x00060000}};  // 2181821.218210
  my_decimal my_result;

  int error_code = my_negate(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_negate_6) {
  my_decimal value = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0}};  // 79228162514264337593543950335
  my_decimal system_result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                               0x80000000}};  // -79228162514264337593543950335
  my_decimal my_result;

  int error_code = my_negate(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_negate_7) {
  my_decimal value = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0x80000000}};  // -79228162514264337593543950335
  my_decimal system_result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                               0}};  // 79228162514264337593543950335
  my_decimal my_result;

  int error_code = my_negate(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_negate_8) {
  my_decimal value = {{0, 0, 0, 0x00020000}};          // 0.00
  my_decimal system_result = {{0, 0, 0, 0x80020000}};  // -0.00
  my_decimal my_result;

  int error_code = my_negate(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_negate_9) {
  my_decimal value = {{0, 0, 0, 0x80020000}};          // -0.00
  my_decimal system_result = {{0, 0, 0, 0x00020000}};  // 0.00
  my_decimal my_result;

  int error_code = my_negate(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_negate_10) {
  my_decimal value = {{999900, 0, 0, 0x00020000}};          // 9999.00
  my_decimal system_result = {{999900, 0, 0, 0x80020000}};  // -9999.00
  my_decimal my_result;

  int error_code = my_negate(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_negate_11) {
  my_decimal value = {{999900, 0, 0, 0x80020000}};          // -9999.00
  my_decimal system_result = {{999900, 0, 0, 0x00020000}};  // 9999.00
  my_decimal my_result;

  int error_code = my_negate(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_negate_12) {
  my_decimal value = {{0x00000467, 0x0000007A, 0x00003215,
                       0x00010000}};  // 23650570576955414727997.5
  my_decimal system_result = {{0x00000467, 0x0000007A, 0x00003215,
                               0x80010000}};  // -23650570576955414727997.5
  my_decimal my_result;

  int error_code = my_negate(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_negate_13) {
  my_decimal value = {{99999, 0, 0, 0}};                   // 99999
  my_decimal system_result = {{99999, 0, 0, 0x80000000}};  // -99999
  my_decimal my_result;

  int error_code = my_negate(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_negate_14) {
  my_decimal value = {{99, 0, 0, 0x00010000}};          // 9.9
  my_decimal system_result = {{99, 0, 0, 0x80010000}};  // -9.9
  my_decimal my_result;

  int error_code = my_negate(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_negate_15) {
  my_decimal value = {{99, 0, 0, 0x80010000}};          // -9.9
  my_decimal system_result = {{99, 0, 0, 0x00010000}};  // 9.9
  my_decimal my_result;

  int error_code = my_negate(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_negate_16) {
  my_decimal value = {{0x00000001, 0, 0, 0x000E0000}};  // 0.000000000000010
  my_decimal system_result = {
      {0x00000001, 0, 0, 0x800E0000}};  // -0.000000000000010
  my_decimal my_result;

  int error_code = my_negate(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_negate_17) {
  my_decimal value = {{0x00000001, 0, 0, 0x800E0000}};  // -0.000000000000010
  my_decimal system_result = {
      {0x00000001, 0, 0, 0x000E0000}};  // 0.000000000000010
  my_decimal my_result;

  int error_code = my_negate(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

Suite* suite_negate(void) {
  Suite* suite = suite_create("my_negate");
  TCase* tc_my_negate;

  tc_my_negate = tcase_create("tc_my_negate");
  tcase_add_test(tc_my_negate, test_negate_1);
  tcase_add_test(tc_my_negate, test_negate_2);
  tcase_add_test(tc_my_negate, test_negate_3);
  tcase_add_test(tc_my_negate, test_negate_4);
  tcase_add_test(tc_my_negate, test_negate_5);
  tcase_add_test(tc_my_negate, test_negate_6);
  tcase_add_test(tc_my_negate, test_negate_7);
  tcase_add_test(tc_my_negate, test_negate_8);
  tcase_add_test(tc_my_negate, test_negate_9);
  tcase_add_test(tc_my_negate, test_negate_10);
  tcase_add_test(tc_my_negate, test_negate_11);
  tcase_add_test(tc_my_negate, test_negate_12);
  tcase_add_test(tc_my_negate, test_negate_13);
  tcase_add_test(tc_my_negate, test_negate_14);
  tcase_add_test(tc_my_negate, test_negate_15);
  tcase_add_test(tc_my_negate, test_negate_16);
  tcase_add_test(tc_my_negate, test_negate_17);

  suite_add_tcase(suite, tc_my_negate);

  return suite;
}