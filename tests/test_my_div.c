#include "my_tests.h"

START_TEST(test_div_1) {
  my_decimal value_1 = {{200, 0, 0, 0}};       // 200
  my_decimal value_2 = {{5, 0, 0, 0}};         // 5
  my_decimal system_result = {{40, 0, 0, 0}};  // 40
  my_decimal my_result;

  int error_code = my_div(value_1, value_2, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_div_2) {
  my_decimal value_1 = {{0x0000000A, 0, 0, 0}};  // 10
  my_decimal value_2 = {{0x00004E2A, 0, 0, 0}};  // 20010
  my_decimal system_result = {{0x9BD58676, 0x15E87A6F, 0x00042243,
                               0x001C0000}};  // 0.0004997501249375312343828086
  my_decimal my_result;

  int error_code = my_div(value_1, value_2, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_div_3) {
  my_decimal value_1 = {
      {0x15C0748C, 0x00000000, 0x00000000, 0x80000000}};  // -364934284
  my_decimal value_2 = {
      {0x000019B2, 0x00000000, 0x00000000, 0x80000000}};  //  -6578
  my_decimal system_result = {
      {0x0000D8B6, 0x00000000, 0x00000000, 0x00000000}};  // 55478
  my_decimal my_result;

  int error_code = my_div(value_1, value_2, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_div_4) {
  my_decimal value_1 = {{0x014CF9BF, 0, 0, 0x80020000}};  // -218218.87
  my_decimal value_2 = {
      {0x9336DD9D, 0x00000032, 0, 0x80020000}};  // -2172182112.29
  my_decimal system_result = {{0xADCFD4F0, 0xD696F916, 0x0000D4BB,
                               0x001C0000}};  // 0.0001004606698330394895308016
  my_decimal my_result;

  int error_code = my_div(value_1, value_2, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_div_5) {
  my_decimal value_1 = {{0, 0, 0, 0}};        // 0
  my_decimal value_2 = {{10000, 0, 0, 0}};    // 10000
  my_decimal system_result = {{0, 0, 0, 0}};  // 0
  my_decimal my_result;

  int error_code = my_div(value_1, value_2, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_div_6) {
  my_decimal value_1 = {{0x0001DC88, 0, 0, 0x00020000}};  // 1219.92
  my_decimal value_2 = {{0x0116F341, 0, 0, 0x80030000}};  // -18281.281
  my_decimal system_result = {{0x9C29AC03, 0x8B157841, 0x0227FB71,
                               0x801C0000}};  // -0.0667305535098990054362164227
  my_decimal my_result;

  int error_code = my_div(value_1, value_2, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_div_7) {
  my_decimal value_1 = {{0x001D537F, 0, 0, 0x80020000}};  // -19219.19
  my_decimal value_2 = {{0x00007208, 0, 0, 0}};           // 29192
  my_decimal system_result = {{0xEF1E9F89, 0xA0889681, 0x1545EC8B,
                               0x801C0000}};  // -0.6583718141956700465881063305
  my_decimal my_result;

  int error_code = my_div(value_1, value_2, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_div_8) {
  my_decimal value_1 = {{0x00000369, 0, 0, 0}};  // 873
  my_decimal value_2 = {{0x000D9987, 0, 0, 0}};  //  891271
  my_decimal system_result = {{0x39A7B007, 0x0C3825D8, 0x00081A2C,
                               0x001C0000}};  //  0.0009795000622706225154863111
  my_decimal my_result;

  int error_code = my_div(value_1, value_2, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_div_9) {
  my_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                         0}};  // 79228162514264337593543950335
  my_decimal value_2 = {{0x00001DE5, 0, 0, 0x00010000}};  //  765.3
  my_decimal system_result = {{0x1AA07F61, 0xB8149B14, 0x2173706D,
                               0x00020000}};  //  103525627223656523707753757.13
  my_decimal my_result;

  int error_code = my_div(value_1, value_2, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_div_10) {
  my_decimal value_1 = {{0x0098967F, 0, 0, 0x00070000}};        // 0.9999999
  my_decimal value_2 = {{0x00000001, 0, 0, 0}};                 //  1
  my_decimal system_result = {{0x0098967F, 0, 0, 0x00070000}};  //  0.9999999
  my_decimal my_result;

  int error_code = my_div(value_1, value_2, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_div_11) {
  my_decimal value_1 = {{0x0098967F, 0, 0, 0x00070000}};  // 0.9999999
  my_decimal value_2 = {{0x3B9AC60D, 0, 0, 0x80090000}};  //  -0.999998989
  my_decimal system_result = {
      {0x1AF606CC, 0x18EB582D, 0x204FD04C,
       0x801C0000}};  //  -1.0000009110009210219311531724
  my_decimal my_result;

  int error_code = my_div(value_1, value_2, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_div_12) {
  my_decimal value_1 = {{0x0098967F, 0, 0, 0x80070000}};  // -0.9999999
  my_decimal value_2 = {
      {0xD4B49FE1, 0x000000E8, 0, 0x000C0000}};  //  1.000001019873
  my_decimal system_result = {
      {0xF97B0D96, 0x28B45460, 0x204FCBFF,
       0x801C0000}};  //  -0.9999988801281421270713044374
  my_decimal my_result;

  int error_code = my_div(value_1, value_2, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_div_13) {
  my_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                         0x80000000}};  // -79228162514264337593543950335
  my_decimal value_2 = {{0x00000019, 0, 0, 0x00010000}};  //  2.5
  my_decimal system_result = {{0x66666666, 0x66666666, 0x66666666,
                               0x80000000}};  //  -31691265005705735037417580134
  my_decimal my_result;

  int error_code = my_div(value_1, value_2, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_div_14) {
  my_decimal value_1 = {{0x00000065, 0, 0, 0x00020000}};  // 1.01
  my_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                         0x80000000}};  //  -79228162514264337593543950335
  my_decimal system_result = {{0, 0, 0, 0x801C0000}};  //  0.0000000000000000000
  my_decimal my_result;

  int error_code = my_div(value_1, value_2, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_div_15) {
  my_decimal value_1 = {{0x4B743118, 0xC29C4065, 0xF1343498,
                         0x00190000}};  // 7464.8999890549484848686575896
  my_decimal value_2 = {{0x036EACCF, 0, 0, 0x00030000}};  //  57584.847
  my_decimal system_result = {{0x97AB5CFD, 0x3AF46695, 0x04304CAF,
                               0x001C0000}};  //  0.1296330610907926608690765053
  my_decimal my_result;

  int error_code = my_div(value_1, value_2, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_div_16) {
  my_decimal value_1 = {{200, 0, 0, 0x00030000}};      // 200.000
  my_decimal value_2 = {{100, 0, 0, 0}};               //  100
  my_decimal system_result = {{2, 0, 0, 0x00030000}};  //  2.000
  my_decimal my_result;

  int error_code = my_div(value_1, value_2, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_div_17) {
  my_decimal value_1 = {{0x007FEBFE, 0, 0, 0x00020000}};        // 83834.86
  my_decimal value_2 = {{0x00000002, 0, 0, 0}};                 //  2
  my_decimal system_result = {{0x003FF5FF, 0, 0, 0x00020000}};  //  41917.43
  my_decimal my_result;

  int error_code = my_div(value_1, value_2, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_div_18) {
  my_decimal value_1 = {{0x007FEBFE, 0, 0, 0x00020000}};  // 83834.86
  my_decimal value_2 = {{0x007FEBFE, 0, 0, 0x00020000}};  // 83834.86
  my_decimal system_result = {{1, 0, 0, 0}};              //  1
  my_decimal my_result;

  int error_code = my_div(value_1, value_2, &my_result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
}
END_TEST

START_TEST(test_div_error_1) {
  my_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                         0}};  // 79228162514264337593543950335
  my_decimal value_2 = {{1, 0, 0, 0x00010000}};  // 0.1
  int system_error_code = 1;
  my_decimal my_result;

  int error_code = my_div(value_1, value_2, &my_result);

  ck_assert_int_eq(error_code, system_error_code);
}
END_TEST

START_TEST(test_div_error_2) {
  my_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                         0}};  // 79228162514264337593543950335
  my_decimal value_2 = {{123, 0, 0, 0x80090000}};  // -0.000000123
  int system_error_code = 2;
  my_decimal my_result;

  int error_code = my_div(value_1, value_2, &my_result);

  ck_assert_int_eq(error_code, system_error_code);
}
END_TEST

START_TEST(test_div_error_3) {
  my_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                         0}};           // 79228162514264337593543950335
  my_decimal value_2 = {{0, 0, 0, 0}};  // 0
  int system_error_code = 3;
  my_decimal my_result;

  int error_code = my_div(value_1, value_2, &my_result);

  ck_assert_int_eq(error_code, system_error_code);
}
END_TEST

Suite* suite_div(void) {
  Suite* suite = suite_create("my_div");
  TCase* tc_my_div;

  tc_my_div = tcase_create("tc_my_div");
  tcase_add_test(tc_my_div, test_div_1);
  tcase_add_test(tc_my_div, test_div_2);
  tcase_add_test(tc_my_div, test_div_3);
  tcase_add_test(tc_my_div, test_div_4);
  tcase_add_test(tc_my_div, test_div_5);
  tcase_add_test(tc_my_div, test_div_6);
  tcase_add_test(tc_my_div, test_div_7);
  tcase_add_test(tc_my_div, test_div_8);
  tcase_add_test(tc_my_div, test_div_9);
  tcase_add_test(tc_my_div, test_div_10);
  tcase_add_test(tc_my_div, test_div_11);
  tcase_add_test(tc_my_div, test_div_12);
  tcase_add_test(tc_my_div, test_div_13);
  tcase_add_test(tc_my_div, test_div_14);
  tcase_add_test(tc_my_div, test_div_15);
  tcase_add_test(tc_my_div, test_div_16);
  tcase_add_test(tc_my_div, test_div_17);
  tcase_add_test(tc_my_div, test_div_18);
  tcase_add_test(tc_my_div, test_div_error_1);
  tcase_add_test(tc_my_div, test_div_error_2);
  tcase_add_test(tc_my_div, test_div_error_3);

  suite_add_tcase(suite, tc_my_div);

  return suite;
}