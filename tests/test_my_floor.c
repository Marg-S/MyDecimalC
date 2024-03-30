#include "my_tests.h"

START_TEST(test_floor_1) {
  my_decimal value = {{0, 0, 0, 0}};          // 0
  my_decimal system_result = {{0, 0, 0, 0}};  // 0
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_2) {
  my_decimal value = {{0x00000001, 0, 0, 0}};          // 1
  my_decimal system_result = {{0x00000001, 0, 0, 0}};  // 1
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_3) {
  my_decimal value = {{0x00000001, 0, 0, 0x80000000}};          // -1
  my_decimal system_result = {{0x00000001, 0, 0, 0x80000000}};  // -1
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_4) {
  my_decimal value = {{234567890, 0, 0, 0}};          // 234567890
  my_decimal system_result = {{234567890, 0, 0, 0}};  // 234567890
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_5) {
  my_decimal value = {
      {0xFEADBDA2, 0x000001FB, 0, 0x80060000}};              // -2181821.218210
  my_decimal system_result = {{2181822, 0, 0, 0x80000000}};  // -2181822
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_6) {
  my_decimal value = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0}};  // 79228162514264337593543950335
  my_decimal system_result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                               0}};  // 79228162514264337593543950335
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_7) {
  my_decimal value = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0x80000000}};  // -79228162514264337593543950335
  my_decimal system_result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                               0x80000000}};  // -79228162514264337593543950335
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_8) {
  my_decimal value = {{0, 0, 0, 0x00020000}};  // 0.00
  my_decimal system_result = {{0, 0, 0, 0}};   // 0
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_9) {
  my_decimal value = {{0, 0, 0, 0x80020000}};          // -0.00
  my_decimal system_result = {{0, 0, 0, 0x80000000}};  // -0
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_10) {
  my_decimal value = {{999900, 0, 0, 0x00020000}};  // 9999.00
  my_decimal system_result = {{9999, 0, 0, 0}};     // 9999
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_11) {
  my_decimal value = {{999900, 0, 0, 0x80020000}};        // -9999.00
  my_decimal system_result = {{9999, 0, 0, 0x80000000}};  // -9999
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_12) {
  my_decimal value = {{0x00000467, 0x0000007A, 0x00003215,
                       0x00010000}};  // 23650570576955414727997.5
  my_decimal system_result = {
      {0xCCCCCD3D, 0x199999A5, 0x00000502, 0}};  // 23650570576955414727997
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_13) {
  my_decimal value = {{99999, 0, 0, 0}};          // 99999
  my_decimal system_result = {{99999, 0, 0, 0}};  // 99999
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_14) {
  my_decimal value = {{99, 0, 0, 0x00010000}};  // 9.9
  my_decimal system_result = {{9, 0, 0, 0}};    // 9
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_15) {
  my_decimal value = {{99, 0, 0, 0x80010000}};          // -9.9
  my_decimal system_result = {{10, 0, 0, 0x80000000}};  // -10
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_16) {
  my_decimal value = {{95, 0, 0, 0x80010000}};          // -9.5
  my_decimal system_result = {{10, 0, 0, 0x80000000}};  // -10
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_17) {
  my_decimal value = {{95, 0, 0, 0x00010000}};  // 9.5
  my_decimal system_result = {{9, 0, 0, 0}};    // 9
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_18) {
  my_decimal value = {{912, 0, 0, 0x80020000}};         // -9.12
  my_decimal system_result = {{10, 0, 0, 0x80000000}};  // -10
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_19) {
  my_decimal value = {{912, 0, 0, 0x00020000}};  // 9.12
  my_decimal system_result = {{9, 0, 0, 0}};     // 9
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_20) {
  my_decimal value = {{9654, 0, 0, 0x00030000}};  // 9.654
  my_decimal system_result = {{9, 0, 0, 0}};      // 9
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_21) {
  my_decimal value = {{9654, 0, 0, 0x80030000}};        // -9.654
  my_decimal system_result = {{10, 0, 0, 0x80000000}};  // -10
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_22) {
  my_decimal value = {
      {0x1FC40A5F, 0xA98FD4BE, 0, 0x00020000}};  // 122182182271212611.51
  my_decimal system_result = {
      {0x24285C43, 0x01B2140C, 0, 0}};  // 122182182271212611
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_23) {
  my_decimal value = {
      {0x1FC40A5D, 0xA98FD4BE, 0, 0x00020000}};  // 122182182271212611.49
  my_decimal system_result = {
      {0x24285C43, 0x01B2140C, 0, 0}};  // 122182182271212611
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_24) {
  my_decimal value = {
      {0x1FC40A5F, 0xA98FD4BE, 0, 0x80020000}};  // -122182182271212611.51
  my_decimal system_result = {
      {0x24285C44, 0x01B2140C, 0, 0x80000000}};  // -122182182271212612
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_25) {
  my_decimal value = {
      {0x1FC40A5D, 0xA98FD4BE, 0, 0x80020000}};  // -122182182271212611.49
  my_decimal system_result = {
      {0x24285C44, 0x01B2140C, 0, 0x80000000}};  // -122182182271212612
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_26) {
  my_decimal value = {{0x00000001, 0, 0, 0x000E0000}};  // 0.000000000000010
  my_decimal system_result = {{0, 0, 0, 0}};            // 0
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_floor_27) {
  my_decimal value = {{0x00000001, 0, 0, 0x800E0000}};  // -0.000000000000010
  my_decimal system_result = {{1, 0, 0, 0x80000000}};   // -1
  my_decimal my_result;

  int error_code = my_floor(value, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

Suite* suite_floor(void) {
  Suite* suite = suite_create("my_floor");
  TCase* tc_my_floor;

  tc_my_floor = tcase_create("tc_my_floor");
  tcase_add_test(tc_my_floor, test_floor_1);
  tcase_add_test(tc_my_floor, test_floor_2);
  tcase_add_test(tc_my_floor, test_floor_3);
  tcase_add_test(tc_my_floor, test_floor_4);
  tcase_add_test(tc_my_floor, test_floor_5);
  tcase_add_test(tc_my_floor, test_floor_6);
  tcase_add_test(tc_my_floor, test_floor_7);
  tcase_add_test(tc_my_floor, test_floor_8);
  tcase_add_test(tc_my_floor, test_floor_9);
  tcase_add_test(tc_my_floor, test_floor_10);
  tcase_add_test(tc_my_floor, test_floor_11);
  tcase_add_test(tc_my_floor, test_floor_12);
  tcase_add_test(tc_my_floor, test_floor_13);
  tcase_add_test(tc_my_floor, test_floor_14);
  tcase_add_test(tc_my_floor, test_floor_15);
  tcase_add_test(tc_my_floor, test_floor_16);
  tcase_add_test(tc_my_floor, test_floor_17);
  tcase_add_test(tc_my_floor, test_floor_18);
  tcase_add_test(tc_my_floor, test_floor_19);
  tcase_add_test(tc_my_floor, test_floor_20);
  tcase_add_test(tc_my_floor, test_floor_21);
  tcase_add_test(tc_my_floor, test_floor_22);
  tcase_add_test(tc_my_floor, test_floor_23);
  tcase_add_test(tc_my_floor, test_floor_24);
  tcase_add_test(tc_my_floor, test_floor_25);
  tcase_add_test(tc_my_floor, test_floor_26);
  tcase_add_test(tc_my_floor, test_floor_27);

  suite_add_tcase(suite, tc_my_floor);

  return suite;
}