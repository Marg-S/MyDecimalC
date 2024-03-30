#include "my_tests.h"

START_TEST(test_add_1) {
  my_decimal value_1 = {{0, 0, 0, 0}};  // 0
  my_decimal value_2 = {{0, 0, 0, 0}};  // 0
  my_decimal my_result;
  my_decimal system_result = {{0, 0, 0, 0}};  // 0

  int my_error_code = my_add(value_1, value_2, &my_result);
  int system_error_code = 0;

  ck_assert_int_eq(my_error_code, system_error_code);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_add_2) {
  my_decimal value_1 = {{0, 0, 0, 0}};           // 0
  my_decimal value_2 = {{0, 0, 0, 0x80010000}};  // 0.0
  my_decimal my_result;
  my_decimal system_result = {{0, 0, 0, 0x00010000}};  // 0.0

  int my_error_code = my_add(value_1, value_2, &my_result);
  int system_error_code = 0;

  ck_assert_int_eq(my_error_code, system_error_code);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_add_3) {
  my_decimal value_1 = {{8, 0, 0, 0x800E0000}};  // -0.00000000000008
  my_decimal value_2 = {{6, 0, 0, 0x000F0000}};  // 0.000000000000006
  my_decimal my_result;
  my_decimal system_result = {{74, 0, 0, 0x800F0000}};  // -0.000000000000002

  int my_error_code = my_add(value_1, value_2, &my_result);
  int system_error_code = 0;

  ck_assert_int_eq(my_error_code, system_error_code);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_add_4) {
  my_decimal value_1 = {{99, 0, 0, 0x00010000}};  // 9.9
  my_decimal value_2 = {{1000, 0, 0, 0}};         // 1000
  my_decimal my_result;
  my_decimal system_result = {{10099, 0, 0, 0x00010000}};  // 1009.9

  int my_error_code = my_add(value_1, value_2, &my_result);
  int system_error_code = 0;

  ck_assert_int_eq(my_error_code, system_error_code);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_add_5) {
  my_decimal value_1 = {{12345, 0, 0, 0x00020000}};  // 123.45
  my_decimal value_2 = {{6789, 0, 0, 0x00020000}};   // 67.89
  my_decimal my_result;
  my_decimal system_result = {{19134, 0, 0, 0x00020000}};  // 191.34

  int my_error_code = my_add(value_1, value_2, &my_result);
  int system_error_code = 0;

  ck_assert_int_eq(my_error_code, system_error_code);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_add_6) {
  my_decimal value_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF,
                         0}};  // 79228162514264337593543950334
  my_decimal value_2 = {{0x00000005, 0, 0, 0x00010000}};  // 0.5
  my_decimal my_result;
  my_decimal system_result = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF,
                               0}};  // 79228162514264337593543950334
  int my_error_code = my_add(value_1, value_2, &my_result);
  int system_error_code = 0;

  ck_assert_int_eq(my_error_code, system_error_code);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], system_result.bits[i]);
  }
}
END_TEST

START_TEST(test_add_7) {
  my_decimal value_1 = {{45, 0, 0, 0x00010000}};  // 4.5
  my_decimal value_2 = {{1, 0, 0, 0}};            // 1
  my_decimal my_result;
  my_decimal system_result = {{55, 0, 0, 0x00010000}};  // 5.5

  int my_error_code = my_add(value_1, value_2, &my_result);
  int system_error_code = 0;

  ck_assert_int_eq(my_error_code, system_error_code);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_add_8) {
  my_decimal value_1 = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF,
                         0}};  // 79228162514264337593543950333
  my_decimal value_2 = {{0x00000031, 0, 0, 0x00020000}};  // 0.49
  my_decimal my_result;
  my_decimal system_result = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF,
                               0}};  // 79228162514264337593543950333

  int my_error_code = my_add(value_1, value_2, &my_result);
  int system_error_code = 0;

  ck_assert_int_eq(my_error_code, system_error_code);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], system_result.bits[i]);
  }
}
END_TEST

START_TEST(test_add_9) {
  my_decimal value_1 = {
      {1, 0, 0, 0x001C0000}};  // 0.0000000000000000000000000001
  my_decimal value_2 = {
      {1, 0, 0, 0x001C0000}};  // 0.0000000000000000000000000001
  my_decimal my_result;
  my_decimal system_result = {
      {2, 0, 0, 0x001C0000}};  // 0.0000000000000000000000000002

  int my_error_code = my_add(value_1, value_2, &my_result);
  int system_error_code = 0;

  ck_assert_int_eq(my_error_code, system_error_code);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_add_10) {
  my_decimal value_1 = {
      {0x000F4240, 0, 0, 0x001C0000}};  // 0.0000000000000000000001000000
  my_decimal value_2 = {
      {0x000186A0, 0, 0, 0x00140000}};  // 0.00000000000000100000
  my_decimal my_result;
  my_decimal system_result = {{0x4E81E240, 0x00000918, 0,
                               0x001C0000}};  // 0.0000000000000010000001000000

  int my_error_code = my_add(value_1, value_2, &my_result);
  int system_error_code = 0;

  ck_assert_int_eq(my_error_code, system_error_code);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_add_11) {
  my_decimal value_1 = {{0x80000000, 0x80000000, 0x80000000, 0}};
  my_decimal value_2 = {{0, 0, 0, 0x001C0000}};
  my_decimal my_result;
  my_decimal system_result = {{0x80000000, 0x80000000, 0x80000000, 0}};

  int my_error_code = my_add(value_1, value_2, &my_result);
  int system_error_code = 0;

  ck_assert_int_eq(my_error_code, system_error_code);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_add_12) {
  my_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                         0x00010000}};  // 7922816251426433759354395033.5
  my_decimal value_2 = {{0x00000005, 0, 0, 0x00010000}};  // 0.5
  my_decimal my_result;
  my_decimal system_result = {
      {0x9999999A, 0x99999999, 0x19999999, 0}};  // 7922816251426433759354395034

  int my_error_code = my_add(value_1, value_2, &my_result);
  int system_error_code = 0;

  ck_assert_int_eq(my_error_code, system_error_code);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_add_13) {
  my_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                         0}};  // 79228162514264337593543950335
  my_decimal value_2 = {{0, 0, 0, 0x000A0000}};  // 0.0000000000
  my_decimal my_result;
  my_decimal system_result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                               0}};  // 79228162514264337593543950335

  int my_error_code = my_add(value_1, value_2, &my_result);
  int system_error_code = 0;

  ck_assert_int_eq(my_error_code, system_error_code);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_add_14) {
  my_decimal value_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF,
                         0}};  // 79228162514264337593543950334
  my_decimal value_2 = {{0x00000033, 0, 0, 0x00020000}};  // 0.51
  my_decimal my_result;
  my_decimal system_result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                               0}};  // 79228162514264337593543950335

  int my_error_code = my_add(value_1, value_2, &my_result);
  int system_error_code = 0;

  ck_assert_int_eq(my_error_code, system_error_code);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], system_result.bits[i]);
  }
}
END_TEST

START_TEST(test_add_15) {
  my_decimal value_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF,
                         0}};  // 79228162514264337593543950334
  my_decimal value_2 = {{0x00000031, 0, 0, 0x00020000}};  // 0.49
  my_decimal my_result;
  my_decimal system_result = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF,
                               0}};  // 79228162514264337593543950334

  int my_error_code = my_add(value_1, value_2, &my_result);
  int system_error_code = 0;

  ck_assert_int_eq(my_error_code, system_error_code);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], system_result.bits[i]);
  }
}
END_TEST

START_TEST(test_add_16) {
  my_decimal value_1 = {{9999, 0, 0, 0x00040000}};  // 0.9999
  my_decimal value_2 = {{1, 0, 0, 0x00040000}};     // 0.0001
  my_decimal my_result;
  my_decimal system_result = {{10000, 0, 0, 0x00040000}};  // 1.0000

  int my_error_code = my_add(value_1, value_2, &my_result);
  int system_error_code = 0;

  ck_assert_int_eq(my_error_code, system_error_code);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], system_result.bits[i]);
  }
}
END_TEST

START_TEST(test_add_17) {
  my_decimal value_1 = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF,
                         0}};  // 79228162514264337593543950333
  my_decimal value_2 = {{0x00000005, 0, 0, 0x00010000}};  // 0.5
  my_decimal my_result;
  my_decimal system_result = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF,
                               0}};  // 79228162514264337593543950334

  int my_error_code = my_add(value_1, value_2, &my_result);
  int system_error_code = 0;

  ck_assert_int_eq(my_error_code, system_error_code);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], system_result.bits[i]);
  }
}
END_TEST

START_TEST(test_add_18) {
  my_decimal value_1 = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF,
                         0}};  // 79228162514264337593543950333
  my_decimal value_2 = {{0x00000033, 0, 0, 0x00020000}};  // 0.51
  my_decimal my_result;
  my_decimal system_result = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF,
                               0}};  // 79228162514264337593543950334

  int my_error_code = my_add(value_1, value_2, &my_result);
  int system_error_code = 0;

  ck_assert_int_eq(my_error_code, system_error_code);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], system_result.bits[i]);
  }
}
END_TEST

START_TEST(test_add_error_1) {
  my_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                         0}};  // 79228162514264337593543950335
  my_decimal value_2 = {{9, 0, 0, 0x00010000}};  // 0.9
  my_decimal my_result;
  int system_error_code = 1;

  int my_error_code = my_add(value_1, value_2, &my_result);

  ck_assert_int_eq(my_error_code, system_error_code);
}
END_TEST

START_TEST(test_add_error_2) {
  my_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                         0x80000000}};  // -79228162514264337593543950335
  my_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                         0x80000000}};  // -79228162514264337593543950335
  my_decimal my_result;
  int system_error_code = 2;

  int my_error_code = my_add(value_1, value_2, &my_result);

  ck_assert_int_eq(my_error_code, system_error_code);
}
END_TEST

Suite* suite_add(void) {
  Suite* suite = suite_create("my_add");
  TCase* tc_my_add;

  tc_my_add = tcase_create("tc_my_add");

  tcase_add_test(tc_my_add, test_add_1);
  tcase_add_test(tc_my_add, test_add_2);
  tcase_add_test(tc_my_add, test_add_3);
  tcase_add_test(tc_my_add, test_add_4);
  tcase_add_test(tc_my_add, test_add_5);
  tcase_add_test(tc_my_add, test_add_6);
  tcase_add_test(tc_my_add, test_add_7);
  tcase_add_test(tc_my_add, test_add_8);
  tcase_add_test(tc_my_add, test_add_9);
  tcase_add_test(tc_my_add, test_add_10);
  tcase_add_test(tc_my_add, test_add_11);
  tcase_add_test(tc_my_add, test_add_12);
  tcase_add_test(tc_my_add, test_add_13);
  tcase_add_test(tc_my_add, test_add_14);
  tcase_add_test(tc_my_add, test_add_15);
  tcase_add_test(tc_my_add, test_add_16);
  tcase_add_test(tc_my_add, test_add_17);
  tcase_add_test(tc_my_add, test_add_18);
  tcase_add_test(tc_my_add, test_add_error_1);
  tcase_add_test(tc_my_add, test_add_error_2);

  suite_add_tcase(suite, tc_my_add);

  return suite;
}
