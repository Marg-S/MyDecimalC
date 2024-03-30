#include "my_tests.h"

START_TEST(test_mul_1) {
  my_decimal val1 = {{123, 2, 0, 0}};
  my_decimal val2 = {{2, 0, 0, 0}};
  my_decimal system_result = {{246, 4, 0, 0}};
  my_decimal my_result;
  int my_return = my_mul(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_mul_2) {
  my_decimal val1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x00080000}};
  my_decimal val2 = {{1, 0, 0, 0}};
  my_decimal system_result = {{-1, -1, -1, 524288}};
  my_decimal my_result;
  int my_return = my_mul(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_mul_3) {
  my_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x000F0000}};
  my_decimal val2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  my_decimal system_result = {{0x096EE456, 0x359A3B3E, 0xCAD2F7F5, 0x80010000}};
  my_decimal my_result;
  int my_return = my_mul(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_mul_4) {
  my_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  my_decimal val2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00180000}};
  my_decimal system_result = {{0x096EE456, 0x359A3B3E, 0xCAD2F7F5, 0x80130000}};
  my_decimal my_result;
  int my_return = my_mul(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_mul_5) {
  my_decimal val1 = {{0x6C47741F, 0x00000007, 0x00000000, 0x801C0000}};
  my_decimal val2 = {{0xF8CF2CDA, 0x0000001F, 0x00000000, 0x00150000}};
  my_decimal system_result = {{0x00000004, 0x00000000, 0x00000000, 0x801C0000}};
  my_decimal my_result;
  int my_return = my_mul(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_mul_6) {
  my_decimal val1 = {{0x3B97BBCF, 0x00000000, 0x00000000, 0x001C0000}};
  my_decimal val2 = {{0xF8CF2CDA, 0x0000001F, 0x00000000, 0x00150000}};
  my_decimal system_result = {{0x00000000, 0x00000000, 0x00000000, 0x001C0000}};
  my_decimal my_result;
  int my_return = my_mul(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_mul_7) {
  my_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  my_decimal val2 = {{0x04000001, 0xC308736A, 0x02E87669, 0x001B0000}};
  my_decimal system_result = {{0x666666B5, 0x66666666, 0xE6666666, 0x00000000}};
  my_decimal my_result;
  int my_return = my_mul(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_mul_8) {
  my_decimal val1 = {{0}};
  my_decimal val2 = {{0}};
  my_decimal system_result = {{0}};
  my_decimal my_result;
  int my_return = my_mul(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_mul_9) {
  my_decimal val1 = {{0x00000000, 0x00000000, 0x00000000, 0x00030000}};
  my_decimal val2 = {{0x00000000, 0x00000000, 0x00000000, 0x80050000}};
  my_decimal system_result = {{0x00000000, 0x00000000, 0x00000000, 0x80080000}};
  my_decimal my_result;
  int my_return = my_mul(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_mul_10) {
  my_decimal val1 = {{0x0000000F, 0x00000000, 0x00000000, 0x00010000}};
  my_decimal val2 = {{0x00000002, 0x00000000, 0x00000000, 0x00000000}};
  my_decimal system_result = {{0x0000001E, 0x00000000, 0x00000000, 0x00010000}};
  my_decimal my_result;
  int my_return = my_mul(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_mul_11) {
  my_decimal val1 = {{0x00000001, 0x00000000, 0x00000000, 0x000F0000}};
  my_decimal val2 = {{0x540BE400, 0x00000002, 0x00000000, 0x00000000}};
  my_decimal system_result = {{0x540BE400, 0x00000002, 0x00000000, 0x000F0000}};
  my_decimal my_result;
  int my_return = my_mul(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_mul_12) {
  my_decimal val1 = {{0xC4D5AAEC, 0x00000025, 0x00000000, 0x00060000}};
  my_decimal val2 = {{0x0000033B, 0x00000000, 0x00000000, 0x00040000}};
  my_decimal system_result = {{0xDE3F2864, 0x00007A02, 0x00000000, 0x000A0000}};
  my_decimal my_result;
  int my_return = my_mul(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_mul_13) {
  my_decimal val1 = {{0x74489B46, 0x11C6B4C4, 0x00000000, 0x00050000}};
  my_decimal val2 = {{0x0005C187, 0x00000000, 0x00000000, 0x000F0000}};
  my_decimal system_result = {{0x17B7A7EA, 0xB5E7B4AF, 0x00006651, 0x00140000}};
  my_decimal my_result;
  int my_return = my_mul(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_mul_14) {
  my_decimal val1 = {{0xA4C194B9, 0xDF05E1A3, 0x000786BE, 0x00050000}};
  my_decimal val2 = {{0x000003DD, 0x00000000, 0x00000000, 0x00000000}};
  my_decimal system_result = {{0x7FDB8EB5, 0x99B8B533, 0x1D138F63, 0x00050000}};
  my_decimal my_result;
  int my_return = my_mul(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_mul_15) {
  my_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  my_decimal val2 = {{0x00000001, 0x00000000, 0x00000000, 0x80000000}};
  my_decimal system_result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  my_decimal my_result;
  int my_return = my_mul(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_mul_16) {
  my_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  my_decimal val2 = {{0x00000005, 0x00000000, 0x00000000, 0x00010000}};
  my_decimal system_result = {{0x00000000, 0x00000000, 0x80000000, 0x00000000}};
  my_decimal my_result;
  int my_return = my_mul(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_mul_17) {
  my_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  my_decimal val2 = {{0x00000159, 0x00000000, 0x00000000, 0x00040000}};
  my_decimal system_result = {{0x851EB852, 0x1EB851EB, 0x5851EB85, 0x00010000}};
  my_decimal my_result;
  int my_return = my_mul(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_mul_18) {
  my_decimal val1 = {{0x0098967F, 0x00000000, 0x00000000, 0x00070000}};
  my_decimal val2 = {{0x0D01C1BA, 0x00000000, 0x00000000, 0x00010000}};
  my_decimal system_result = {{0x81D21746, 0x0007C0B0, 0x00000000, 0x00080000}};
  my_decimal my_result;
  int my_return = my_mul(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

START_TEST(test_mul_19) {
  my_decimal val1 = {{0x0000036C, 0x00000000, 0x00000000, 0x00110000}};
  my_decimal val2 = {{0x3E41371C, 0x01632A10, 0x00000000, 0x80040000}};
  my_decimal system_result = {{0x072893D0, 0xBF53EF95, 0x00000004, 0x80150000}};
  my_decimal my_result;
  int my_return = my_mul(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(my_return, 0);
}
END_TEST

Suite* suite_mul(void) {
  Suite* suite = suite_create("my_mul");
  TCase* tc_my_mul;

  tc_my_mul = tcase_create("tc_my_mul");
  tcase_add_test(tc_my_mul, test_mul_1);
  tcase_add_test(tc_my_mul, test_mul_2);
  tcase_add_test(tc_my_mul, test_mul_3);
  tcase_add_test(tc_my_mul, test_mul_4);
  tcase_add_test(tc_my_mul, test_mul_5);
  tcase_add_test(tc_my_mul, test_mul_6);
  tcase_add_test(tc_my_mul, test_mul_7);
  tcase_add_test(tc_my_mul, test_mul_8);
  tcase_add_test(tc_my_mul, test_mul_9);
  tcase_add_test(tc_my_mul, test_mul_10);
  tcase_add_test(tc_my_mul, test_mul_11);
  tcase_add_test(tc_my_mul, test_mul_12);
  tcase_add_test(tc_my_mul, test_mul_13);
  tcase_add_test(tc_my_mul, test_mul_14);
  tcase_add_test(tc_my_mul, test_mul_15);
  tcase_add_test(tc_my_mul, test_mul_16);
  tcase_add_test(tc_my_mul, test_mul_17);
  tcase_add_test(tc_my_mul, test_mul_18);
  tcase_add_test(tc_my_mul, test_mul_19);

  suite_add_tcase(suite, tc_my_mul);

  return suite;
}
