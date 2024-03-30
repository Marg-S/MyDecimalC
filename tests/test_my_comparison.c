#include "my_tests.h"

START_TEST(test_less_1) {
  my_decimal val1, val2;
  memset(&val1, 0, sizeof(val1));
  memset(&val2, 0, sizeof(val2));
  val1.bits[2] = 5;
  val1.bits[0] = 5;
  val2.bits[2] = 6;
  val2.bits[0] = 6;
  ck_assert_int_eq(my_is_less(val1, val2), 1);
  ck_assert_int_eq(my_is_less_or_equal(val1, val2), 1);
  ck_assert_int_eq(my_is_greater(val1, val2), 0);
  ck_assert_int_eq(my_is_greater_or_equal(val1, val2), 0);
  ck_assert_int_eq(my_is_equal(val1, val2), 0);
  ck_assert_int_eq(my_is_not_equal(val1, val2), 1);
}
END_TEST

START_TEST(test_greater_2) {
  my_decimal val1, val2;
  memset(&val1, 0, sizeof(val1));
  memset(&val2, 0, sizeof(val2));
  val1.bits[2] = 6;
  val1.bits[0] = 50;
  val2.bits[2] = 5;
  val2.bits[0] = 6;
  ck_assert_int_eq(my_is_less(val1, val2), 0);
  ck_assert_int_eq(my_is_less_or_equal(val1, val2), 0);
  ck_assert_int_eq(my_is_greater(val1, val2), 1);
  ck_assert_int_eq(my_is_greater_or_equal(val1, val2), 1);
  ck_assert_int_eq(my_is_equal(val1, val2), 0);
  ck_assert_int_eq(my_is_not_equal(val1, val2), 1);
}
END_TEST

START_TEST(test_equal_3) {
  my_decimal val1, val2;
  memset(&val1, 0, sizeof(val1));
  memset(&val2, 0, sizeof(val2));
  val1.bits[2] = 5;
  val1.bits[0] = 50;
  val2.bits[2] = 5;
  val2.bits[0] = 50;
  ck_assert_int_eq(my_is_less(val1, val2), 0);
  ck_assert_int_eq(my_is_less_or_equal(val1, val2), 1);
  ck_assert_int_eq(my_is_greater(val1, val2), 0);
  ck_assert_int_eq(my_is_greater_or_equal(val1, val2), 1);
  ck_assert_int_eq(my_is_equal(val1, val2), 1);
  ck_assert_int_eq(my_is_not_equal(val1, val2), 0);
}
END_TEST

START_TEST(test_less_exp) {
  my_decimal val1, val2;
  memset(&val1, 0, sizeof(val1));
  memset(&val2, 0, sizeof(val2));
  val1.bits[0] = 5;
  val1.bits[1] = 6;
  val1.bits[2] = 6;
  val1.bits[3] = 6;
  val1.bits[3] <<= 16;
  val2.bits[0] = 6;
  val2.bits[1] = 5;
  val2.bits[2] = 5;
  val2.bits[3] = 2;
  val2.bits[3] <<= 16;
  ck_assert_int_eq(my_is_less(val1, val2), 1);
  ck_assert_int_eq(my_is_less_or_equal(val1, val2), 1);
  ck_assert_int_eq(my_is_greater(val1, val2), 0);
  ck_assert_int_eq(my_is_greater_or_equal(val1, val2), 0);
  ck_assert_int_eq(my_is_equal(val1, val2), 0);
  ck_assert_int_eq(my_is_not_equal(val1, val2), 1);
}
END_TEST

START_TEST(test_greater_exp) {
  my_decimal val1, val2;
  memset(&val1, 0, sizeof(val1));
  memset(&val2, 0, sizeof(val2));
  val1.bits[0] = 50;
  val1.bits[1] = 6;
  val1.bits[2] = 6;
  val1.bits[3] = 6;
  val1.bits[3] <<= 16;
  val2.bits[0] = 6;
  val2.bits[1] = 6;
  val2.bits[2] = 50;
  val2.bits[3] = 10;
  val2.bits[3] <<= 16;
  ck_assert_int_eq(my_is_less(val1, val2), 0);
  ck_assert_int_eq(my_is_less_or_equal(val1, val2), 0);
  ck_assert_int_eq(my_is_greater(val1, val2), 1);
  ck_assert_int_eq(my_is_greater_or_equal(val1, val2), 1);
  ck_assert_int_eq(my_is_equal(val1, val2), 0);
  ck_assert_int_eq(my_is_not_equal(val1, val2), 1);
}
END_TEST

START_TEST(test_equal_exp) {
  my_decimal val1, val2;
  memset(&val1, 0, sizeof(val1));
  memset(&val2, 0, sizeof(val2));
  val1.bits[0] = 50;
  val1.bits[1] = 50;
  val1.bits[2] = 5;
  val1.bits[3] = 5;
  val1.bits[3] <<= 16;
  val2.bits[0] = 50;
  val2.bits[1] = 50;
  val2.bits[2] = 5;
  val2.bits[3] = 5;
  val2.bits[3] <<= 16;
  ck_assert_int_eq(my_is_less(val1, val2), 0);
  ck_assert_int_eq(my_is_less_or_equal(val1, val2), 1);
  ck_assert_int_eq(my_is_greater(val1, val2), 0);
  ck_assert_int_eq(my_is_greater_or_equal(val1, val2), 1);
  ck_assert_int_eq(my_is_equal(val1, val2), 1);
  ck_assert_int_eq(my_is_not_equal(val1, val2), 0);
}
END_TEST

Suite* suite_cmp(void) {
  Suite* suite = suite_create("my_cmp");
  TCase* tc_my_cmp;

  tc_my_cmp = tcase_create("tc_my_cmp");
  tcase_add_test(tc_my_cmp, test_less_1);
  tcase_add_test(tc_my_cmp, test_greater_2);
  tcase_add_test(tc_my_cmp, test_equal_3);
  tcase_add_test(tc_my_cmp, test_less_exp);
  tcase_add_test(tc_my_cmp, test_greater_exp);
  tcase_add_test(tc_my_cmp, test_equal_exp);

  suite_add_tcase(suite, tc_my_cmp);

  return suite;
}
