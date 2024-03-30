#include "my_tests.h"

int main(void) {
  int failed = 0;
  Suite *suite[14];
  SRunner *runner;

  suite[0] = suite_add();
  suite[1] = suite_cmp();
  suite[2] = suite_mul();
  suite[3] = suite_sub();
  suite[4] = suite_div();
  suite[5] = suite_from_int_to_decimal();
  suite[6] = suite_from_float_to_decimal();
  suite[7] = suite_from_decimal_to_int();
  suite[8] = suite_from_decimal_to_float();
  suite[9] = suite_floor();
  suite[10] = suite_round();
  suite[11] = suite_truncate();
  suite[12] = suite_negate();
  suite[13] = suite_utils();
  runner = srunner_create(suite[0]);

  srunner_add_suite(runner, suite[1]);
  srunner_add_suite(runner, suite[2]);
  srunner_add_suite(runner, suite[3]);
  srunner_add_suite(runner, suite[4]);
  srunner_add_suite(runner, suite[5]);
  srunner_add_suite(runner, suite[6]);
  srunner_add_suite(runner, suite[7]);
  srunner_add_suite(runner, suite[8]);
  srunner_add_suite(runner, suite[9]);
  srunner_add_suite(runner, suite[10]);
  srunner_add_suite(runner, suite[11]);
  srunner_add_suite(runner, suite[12]);
  srunner_add_suite(runner, suite[13]);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
