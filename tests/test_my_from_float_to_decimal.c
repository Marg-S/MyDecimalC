#include "my_tests.h"

START_TEST(test_from_float_1) {
  float val = 0.f;
  my_decimal system_result = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_from_float_2) {
  float val = -0.f;
  my_decimal system_result = {{0x00000000, 0x00000000, 0x00000000, 0x80000000}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_from_float_3) {
  float val = -1.f;
  my_decimal system_result = {{0x00000001, 0x00000000, 0x00000000, 0x80000000}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_from_float_4) {
  float val = 1.f;
  my_decimal system_result = {{0x00000001, 0x00000000, 0x00000000, 0x00000000}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_from_float_5) {
  float val = -2.f;
  my_decimal system_result = {{0x00000002, 0x00000000, 0x00000000, 0x80000000}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_from_float_6) {
  float val = 2.f;
  my_decimal system_result = {{0x00000002, 0x00000000, 0x00000000, 0x00000000}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_from_float_7) {
  float val = 2147483650.f;
  my_decimal system_result = {{0x80000160, 0x00000000, 0x00000000, 0x00000000}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_from_float_8) {
  float val = -2147483650.f;
  my_decimal system_result = {{0x80000160, 0x00000000, 0x00000000, 0x80000000}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_from_float_9) {
  float val = -9999999440000000000000000000.f;
  my_decimal system_result = {{0x31600000, 0x085B549B, 0x204FCE28, 0x80000000}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_from_float_10) {
  float val = 1234567.5f;
  my_decimal system_result = {{0x0012D688, 0x00000000, 0x00000000, 0x00000000}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_from_float_11) {
  float val = 1234567.88f;
  my_decimal system_result = {{0x0012D688, 0x00000000, 0x00000000, 0x00000000}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_from_float_12) {
  float val = 1E-28f;
  my_decimal system_result = {{0x00000001, 0x00000000, 0x00000000, 0x001C0000}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_from_float_13) {
  float val = 1.00000003E-27f;
  my_decimal system_result = {{0x00000001, 0x00000000, 0x00000000, 0x001B0000}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_from_float_14) {
  float val = 1.19999996E-27f;
  my_decimal system_result = {{0x0000000C, 0x00000000, 0x00000000, 0x001C0000}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_from_float_15) {
  float val = 1.50000004E-27f;
  my_decimal system_result = {{0x0000000F, 0x00000000, 0x00000000, 0x001C0000}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_from_float_16) {
  float val = 1.89999999E-27f;
  my_decimal system_result = {{0x00000013, 0x00000000, 0x00000000, 0x001C0000}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_from_float_17) {
  float val = 9.99999989E-27f;
  my_decimal system_result = {{0x00000001, 0x00000000, 0x00000000, 0x001A0000}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_from_float_18) {
  float val = 1E-23f;
  my_decimal system_result = {{0x00000001, 0x00000000, 0x00000000, 0x00170000}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_from_float_19) {
  float val = 1E-23f;
  my_decimal system_result = {{0x00000001, 0x00000000, 0x00000000, 0x00170000}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_from_float_20) {
  float val = -0.00167000003f;
  my_decimal system_result = {{0x000000A7, 0x00000000, 0x00000000, 0x80050000}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_from_float_21) {
  float val = 19.9999981f;
  my_decimal system_result = {{0x00000014, 0x00000000, 0x00000000, 0x00000000}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_from_float_22) {
  float val = 70172132300000000000000000000.f;
  my_decimal system_result = {{0xA9400000, 0xB25EFECA, 0xE2BD0685, 0x00000000}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_from_float_23) {
  float val = 0.00000000000000000000000000016929383838292f;
  my_decimal system_result = {{0x00000002, 0x00000000, 0x00000000, 0x001C0000}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_from_float_24) {
  float val = 0.00000000000000000000000858598287381972f;
  my_decimal system_result = {{0x0000218A, 0x00000000, 0x00000000, 0x001B0000}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_from_float_25) {
  float val = nan("");
  my_decimal system_result = {{0}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 1);
}
END_TEST

START_TEST(test_from_float_26) {
  float val = -nan("");
  my_decimal system_result = {{0}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 1);
}
END_TEST

START_TEST(test_from_float_27) {
  float val = INFINITY;
  my_decimal system_result = {{0}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 1);
}
END_TEST

START_TEST(test_from_float_28) {
  float val = -INFINITY;
  my_decimal system_result = {{0}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 1);
}
END_TEST

START_TEST(test_from_float_29) {
  float val = FLT_MIN;
  my_decimal system_result = {{0}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 1);
}
END_TEST

START_TEST(test_from_float_30) {
  float val = -FLT_MIN;
  my_decimal system_result = {{0}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 1);
}
END_TEST

START_TEST(test_from_float_31) {
  float val = FLT_MAX;
  my_decimal system_result = {{0}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 1);
}
END_TEST

START_TEST(test_from_float_32) {
  float val = -FLT_MAX;
  my_decimal system_result = {{0}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 1);
}
END_TEST

START_TEST(test_from_float_33) {
  float val = 1.0e-29f;
  my_decimal system_result = {{0}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 1);
}
END_TEST

START_TEST(test_from_float_34) {
  float val = -1.763e-29f;
  my_decimal system_result = {{0}};
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 1);
}
END_TEST

START_TEST(test_from_float_35) {
  float val = powf(2.0, 96);
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_return, 1);
}
END_TEST

START_TEST(test_from_float_36) {
  float val = -powf(2.0, 96);
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_return, 1);
}
END_TEST

START_TEST(test_from_float_37) {
  float val = powf(1.99, 110);
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_return, 1);
}
END_TEST

START_TEST(test_from_float_38) {
  float val = -powf(1.99, 110);
  my_decimal my_result;
  int my_return = my_from_float_to_decimal(val, &my_result);
  ck_assert_int_eq(my_return, 1);
}
END_TEST

Suite* suite_from_float_to_decimal(void) {
  Suite* suite = suite_create("my_from_float");
  TCase* tc_my_from_float;

  tc_my_from_float = tcase_create("tc_my_from_float");
  tcase_add_test(tc_my_from_float, test_from_float_1);
  tcase_add_test(tc_my_from_float, test_from_float_2);
  tcase_add_test(tc_my_from_float, test_from_float_3);
  tcase_add_test(tc_my_from_float, test_from_float_4);
  tcase_add_test(tc_my_from_float, test_from_float_5);
  tcase_add_test(tc_my_from_float, test_from_float_6);
  tcase_add_test(tc_my_from_float, test_from_float_7);
  tcase_add_test(tc_my_from_float, test_from_float_8);
  tcase_add_test(tc_my_from_float, test_from_float_9);
  tcase_add_test(tc_my_from_float, test_from_float_10);
  tcase_add_test(tc_my_from_float, test_from_float_11);
  tcase_add_test(tc_my_from_float, test_from_float_12);
  tcase_add_test(tc_my_from_float, test_from_float_13);
  tcase_add_test(tc_my_from_float, test_from_float_14);
  tcase_add_test(tc_my_from_float, test_from_float_15);
  tcase_add_test(tc_my_from_float, test_from_float_16);
  tcase_add_test(tc_my_from_float, test_from_float_17);
  tcase_add_test(tc_my_from_float, test_from_float_18);
  tcase_add_test(tc_my_from_float, test_from_float_19);
  tcase_add_test(tc_my_from_float, test_from_float_20);
  tcase_add_test(tc_my_from_float, test_from_float_21);
  tcase_add_test(tc_my_from_float, test_from_float_22);
  tcase_add_test(tc_my_from_float, test_from_float_23);
  tcase_add_test(tc_my_from_float, test_from_float_24);
  tcase_add_test(tc_my_from_float, test_from_float_25);
  tcase_add_test(tc_my_from_float, test_from_float_26);
  tcase_add_test(tc_my_from_float, test_from_float_27);
  tcase_add_test(tc_my_from_float, test_from_float_28);
  tcase_add_test(tc_my_from_float, test_from_float_29);
  tcase_add_test(tc_my_from_float, test_from_float_30);
  tcase_add_test(tc_my_from_float, test_from_float_31);
  tcase_add_test(tc_my_from_float, test_from_float_32);
  tcase_add_test(tc_my_from_float, test_from_float_33);
  tcase_add_test(tc_my_from_float, test_from_float_34);
  tcase_add_test(tc_my_from_float, test_from_float_35);
  tcase_add_test(tc_my_from_float, test_from_float_36);
  tcase_add_test(tc_my_from_float, test_from_float_37);
  tcase_add_test(tc_my_from_float, test_from_float_38);

  suite_add_tcase(suite, tc_my_from_float);

  return suite;
}
