#include "my_tests.h"

START_TEST(test_sub_1) {
  my_decimal val1 = {{123, 2, 0, 0}};
  my_decimal val2 = {{2, 0, 0, 0}};
  my_decimal system_result = {{121, 2, 0, 0}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_2) {
  my_decimal val1 = {{0}};
  my_decimal val2 = {{0}};
  my_decimal my_result;
  my_decimal system_result = {{0}};
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_3) {
  my_decimal val1 = {{0, 0, 0, 0x80010000}};
  my_decimal val2 = {{0}};
  my_decimal my_result;
  my_decimal system_result = {{0, 0, 0, 0x80010000}};
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_4) {
  my_decimal val1 = {{0}};
  my_decimal val2 = {{0, 0, 0, 0x80010000}};
  my_decimal my_result;
  my_decimal system_result = {{0, 0, 0, 0x00010000}};
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_5) {
  my_decimal val1 = {{0, 0, 0, 0x00010000}};
  my_decimal val2 = {{0}};
  my_decimal system_result = {{0, 0, 0, 0x00010000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_6) {
  my_decimal val1 = {{0}};
  my_decimal val2 = {{0, 0, 0, 0x00010000}};
  my_decimal system_result = {{0, 0, 0, 0x00010000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_7) {
  my_decimal val1 = {{0x00000019, 0, 0, 0x00010000}};
  my_decimal val2 = {{0x00000019, 0, 0, 0x00010000}};
  my_decimal system_result = {{0, 0, 0, 0x00010000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_8) {
  my_decimal val1 = {{1, 0, 0, 0x800E0000}};
  my_decimal val2 = {{6, 0, 0, 0x000F0000}};
  my_decimal system_result = {{16, 0, 0, 0x800F0000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_9) {
  my_decimal val1 = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  my_decimal val2 = {{0x00000005, 0, 0, 0x00010000}};
  my_decimal system_result = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_10) {
  my_decimal val1 = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  my_decimal val2 = {{0x00000033, 0x00000000, 0x00000000, 0x00020000}};
  my_decimal system_result = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_11) {
  // -79228162514264337593543950334 - 0.5 = -79228162514264337593543950334
  my_decimal val1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  my_decimal val2 = {{0x00000005, 0, 0, 0x00010000}};
  my_decimal system_result = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_12) {
  my_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  my_decimal val2 = {{0x00000000, 0x00000000, 0x00000000, 0x000A0000}};
  my_decimal system_result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_13) {
  // -79228162514264337593543950334 - 0.51 = -79228162514264337593543950334
  my_decimal val1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  my_decimal val2 = {{0x00000033, 0x00000000, 0x00000000, 0x00020000}};
  my_decimal system_result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_14) {
  my_decimal val1 = {{0x00000019, 0x00000000, 0x00000000, 0x00010000}};
  my_decimal val2 = {{0x00000064, 0x00000000, 0x00000000, 0x00000000}};
  my_decimal system_result = {{0x000003CF, 0x00000000, 0x00000000, 0x80010000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_15) {
  my_decimal val1 = {{0x00000183, 0x00000000, 0x00000000, 0x00020000}};
  my_decimal val2 = {{0x00004DA6, 0x00000000, 0x00000000, 0x00020000}};
  my_decimal system_result = {{0x00004C23, 0x00000000, 0x00000000, 0x80020000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_16) {
  my_decimal val1 = {{0x14490831, 0x00048E23, 0x00000000, 0x00070000}};
  my_decimal val2 = {{0x164214B7, 0x00000028, 0x00000000, 0x00040000}};
  my_decimal system_result = {{0x22281D59, 0x0003F18C, 0x00000000, 0x00070000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_17) {
  my_decimal val1 = {{0x00000001, 0x00000000, 0x00000000, 0x00000000}};
  my_decimal val2 = {{0x00000019, 0x00000000, 0x00000000, 0x00010000}};
  my_decimal system_result = {{0x0000000F, 0x00000000, 0x00000000, 0x80010000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_18) {
  my_decimal val1 = {{0x77D5E3AA, 0x0000011C, 0x00000000, 0x00060000}};
  my_decimal val2 = {{0x00212155, 0x00000000, 0x00000000, 0x00070000}};
  my_decimal system_result = {{0xAE39C34F, 0x00000B1C, 0x00000000, 0x00070000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_19) {
  my_decimal val1 = {{0x80000000, 0x80000000, 0x80000000, 0x801C0000}};
  my_decimal val2 = {{0x80000000, 0x80000000, 0x80000000, 0x801C0000}};
  my_decimal system_result = {{0x00000000, 0x00000000, 0x00000000, 0x801C0000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_20) {
  my_decimal val1 = {{0x80000000, 0x80000000, 0x80000000, 0x000E0000}};
  my_decimal val2 = {{0x80000000, 0x80000000, 0x80000000, 0x000E0000}};
  my_decimal system_result = {{0x00000000, 0x00000000, 0x00000000, 0x000E0000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_21) {
  my_decimal val1 = {{0x00000001, 0x00000000, 0x00000000, 0x001C0000}};
  my_decimal val2 = {{0x00000001, 0x00000000, 0x00000000, 0x001C0000}};
  my_decimal system_result = {{0x00000000, 0x00000000, 0x00000000, 0x001C0000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_22) {
  my_decimal val1 = {{0x000F4240, 0x00000000, 0x00000000, 0x001C0000}};
  my_decimal val2 = {{0x000186A0, 0x00000000, 0x00000000, 0x00140000}};
  my_decimal system_result = {{0x4E635DC0, 0x00000918, 0x00000000, 0x801C0000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_23) {
  my_decimal val1 = {{0x80000000, 0x80000000, 0x80000000, 0x00000000}};
  my_decimal val2 = {{0x00000000, 0x00000000, 0x00000000, 0x000A0000}};
  my_decimal system_result = {{0x80000000, 0x80000000, 0x80000000, 0x00000000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_24) {
  my_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00010000}};
  my_decimal val2 = {{0x00000005, 0x00000000, 0x00000000, 0x00010000}};
  my_decimal system_result = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x00010000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_25) {
  my_decimal val1 = {{0x1422CF6C, 0x000001FC, 0x00000000, 0x80030000}};
  my_decimal val2 = {{0xF96C01C5, 0x0007B6B6, 0x00000000, 0x800B0000}};
  my_decimal system_result = {{0x3D3DEA3B, 0xD45ACA59, 0x0000000B, 0x800B0000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_26) {
  my_decimal val1 = {{0x2564B1EA, 0x3927F1F3, 0x041C50D7, 0x000B0000}};
  my_decimal val2 = {{0x00033F4A, 0x00000000, 0x00000000, 0x000C0000}};
  my_decimal system_result = {{0x75EBB3DA, 0x3B8F737F, 0x291B2868, 0x000C0000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_27) {
  my_decimal val1 = {{0x0001869F, 0x00000000, 0x00000000, 0x00050000}};
  my_decimal val2 = {{0x00000001, 0x00000000, 0x00000000, 0x00050000}};
  my_decimal system_result = {{0x0001869E, 0x00000000, 0x00000000, 0x00050000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_28) {
  my_decimal val1 = {{0x0098967E, 0x00000000, 0x00000000, 0x80060000}};
  my_decimal val2 = {{0x00000002, 0x00000000, 0x00000000, 0x80060000}};
  my_decimal system_result = {{0x0098967C, 0x00000000, 0x00000000, 0x80060000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_29) {
  my_decimal val1 = {{0x000000CF, 0x00000000, 0x00000000, 0x00010000}};
  my_decimal val2 = {{0x00003F86, 0x00000000, 0x00000000, 0x00160000}};
  my_decimal system_result = {{0x035FC07A, 0x7E1382FF, 0x00002BD5, 0x00160000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_30) {
  my_decimal val1 = {{0x0707E3C5, 0x002D8D61, 0x00000000, 0x80090000}};
  my_decimal val2 = {{0x058FEC8A, 0x00000000, 0x00000000, 0x00050000}};
  my_decimal system_result = {{0x4D0FB265, 0x002D8E3A, 0x00000000, 0x80090000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_31) {
  my_decimal val1 = {{0x846A4B4C, 0x0000012A, 0x00000000, 0x00080000}};
  my_decimal val2 = {{0x0081787B, 0x00000000, 0x00000000, 0x80080000}};
  my_decimal system_result = {{0x84EBC3C7, 0x0000012A, 0x00000000, 0x00080000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_32) {
  my_decimal val1 = {{0x000035A3, 0x00000000, 0x00000000, 0x00170000}};
  my_decimal val2 = {{0x0001F8A8, 0x00000000, 0x00000000, 0x00030000}};
  my_decimal system_result = {{0x827FCA5D, 0x3C3F28D0, 0x000AAFBF, 0x80170000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_33) {
  my_decimal val1 = {{0x79353447, 0x00000004, 0x00000000, 0x00010000}};
  my_decimal val2 = {{0xD927FFFF, 0xE1003B28, 0x00000004, 0x00140000}};
  my_decimal system_result = {{0xDA380000, 0x5C68A936, 0x3E14F384, 0x00130000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_34) {
  my_decimal val1 = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  my_decimal val2 = {{0x00000031, 0x00000000, 0x00000000, 0x00020000}};
  my_decimal system_result = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_35) {
  my_decimal val1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  my_decimal val2 = {{0x00000031, 0x00000000, 0x00000000, 0x00020000}};
  my_decimal system_result = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_36) {
  my_decimal val1 = {{0x25D10992, 0xC0F1C9E2, 0x00000075, 0x000D0000}};
  my_decimal val2 = {{0x2B1BA438, 0x0022C51B, 0x00000000, 0x00060000}};
  my_decimal system_result = {{0x1B79E26E, 0xB810475F, 0x00001443, 0x800D0000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_37) {
  my_decimal val1 = {{0x05D6E6CB, 0x00000000, 0x00000000, 0x00000000}};
  my_decimal val2 = {{0x0365445B, 0x00000000, 0x00000000, 0x000C0000}};
  my_decimal system_result = {{0x47DE6BA5, 0x4F9AE2F8, 0x00000005, 0x000C0000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_38) {
  my_decimal val1 = {{0xCC392EC8, 0x000490A0, 0x00000000, 0x00000000}};
  my_decimal val2 = {{0x13F6BD6D, 0x1738423E, 0x00000000, 0x000D0000}};
  my_decimal system_result = {{0x6E564293, 0x510205DD, 0x29849C5D, 0x000D0000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_39) {
  my_decimal val1 = {{0x10C2F579, 0x00000000, 0x00000000, 0x80050000}};
  my_decimal val2 = {{0x10C44951, 0x00000000, 0x00000000, 0x80030000}};
  my_decimal system_result = {{0x7BE9AE2B, 0x00000006, 0x00000000, 0x00050000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_sub_40) {
  my_decimal val1 = {{0x00000190, 0x00000000, 0x00000000, 0x80000000}};
  my_decimal val2 = {{0x00000190, 0x00000000, 0x00000000, 0x80000000}};
  my_decimal system_result = {{0x00000000, 0x00000000, 0x00000000, 0x80000000}};
  my_decimal my_result;
  int error = my_sub(val1, val2, &my_result);
  ck_assert_int_eq(my_result.bits[0], system_result.bits[0]);
  ck_assert_int_eq(my_result.bits[1], system_result.bits[1]);
  ck_assert_int_eq(my_result.bits[2], system_result.bits[2]);
  ck_assert_int_eq(my_result.bits[3], system_result.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

Suite* suite_sub(void) {
  Suite* suite = suite_create("my_sub");
  TCase* tc_my_sub;

  tc_my_sub = tcase_create("tc_my_sub");
  tcase_add_test(tc_my_sub, test_sub_1);
  tcase_add_test(tc_my_sub, test_sub_2);
  tcase_add_test(tc_my_sub, test_sub_3);
  tcase_add_test(tc_my_sub, test_sub_4);
  tcase_add_test(tc_my_sub, test_sub_5);
  tcase_add_test(tc_my_sub, test_sub_6);
  tcase_add_test(tc_my_sub, test_sub_7);
  tcase_add_test(tc_my_sub, test_sub_8);
  tcase_add_test(tc_my_sub, test_sub_9);
  tcase_add_test(tc_my_sub, test_sub_10);
  tcase_add_test(tc_my_sub, test_sub_11);
  tcase_add_test(tc_my_sub, test_sub_12);
  tcase_add_test(tc_my_sub, test_sub_13);
  tcase_add_test(tc_my_sub, test_sub_14);
  tcase_add_test(tc_my_sub, test_sub_15);
  tcase_add_test(tc_my_sub, test_sub_16);
  tcase_add_test(tc_my_sub, test_sub_17);
  tcase_add_test(tc_my_sub, test_sub_18);
  tcase_add_test(tc_my_sub, test_sub_19);
  tcase_add_test(tc_my_sub, test_sub_20);
  tcase_add_test(tc_my_sub, test_sub_21);
  tcase_add_test(tc_my_sub, test_sub_22);
  tcase_add_test(tc_my_sub, test_sub_23);
  tcase_add_test(tc_my_sub, test_sub_24);
  tcase_add_test(tc_my_sub, test_sub_25);
  tcase_add_test(tc_my_sub, test_sub_26);
  tcase_add_test(tc_my_sub, test_sub_27);
  tcase_add_test(tc_my_sub, test_sub_28);
  tcase_add_test(tc_my_sub, test_sub_29);
  tcase_add_test(tc_my_sub, test_sub_30);
  tcase_add_test(tc_my_sub, test_sub_31);
  tcase_add_test(tc_my_sub, test_sub_32);
  tcase_add_test(tc_my_sub, test_sub_33);
  tcase_add_test(tc_my_sub, test_sub_34);
  tcase_add_test(tc_my_sub, test_sub_35);
  tcase_add_test(tc_my_sub, test_sub_36);
  tcase_add_test(tc_my_sub, test_sub_37);
  tcase_add_test(tc_my_sub, test_sub_38);
  tcase_add_test(tc_my_sub, test_sub_39);
  tcase_add_test(tc_my_sub, test_sub_40);

  suite_add_tcase(suite, tc_my_sub);

  return suite;
}
