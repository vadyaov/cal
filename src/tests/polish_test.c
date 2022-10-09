#include "test.h"

START_TEST(polish_t1) {
  const char input[] = "-2 * sin(30)/cos(30) -(-1) + sqrt(16/4)/tan( 1/2)";
  int error = 0;
  double result = 0.0, expected = 0.0;
  char *polishString = polish(input, &error);
  if (0 == error) result = calc(polishString); 
  expected = -2 * sin(30)/cos(30) -(-1) + sqrt(16/4)/tan( 1.0/2.0);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST
/*
START_TEST(polish_t2) {
  char input[] = "";
  int error = 0;
  char *output = polish(input, &error);
  if (output) free(output);
  char expected[] = "";
  ck_assert_int_eq(error, 0);
  ck_assert_str_eq(output, expected);

}
END_TEST

START_TEST(polish_t3) {
  char input[] = "";
  int error = 0;
  char *output = polish(input, &error);
  if (output) free(output);
  char expected[] = "";
  ck_assert_int_eq(error, 0);
  ck_assert_str_eq(output, expected);

}
END_TEST

START_TEST(polish_t4) {
  char input[] = "";
  int error = 0;
  char *output = polish(input, &error);
  if (output) free(output);
  char expected[] = "";
  ck_assert_int_eq(error, 0);
  ck_assert_str_eq(output, expected);

}
END_TEST

START_TEST(polish_t5) {
  char input[] = "";
  int error = 0;
  char *output = polish(input, &error);
  if (output) free(output);
  char expected[] = "";
  ck_assert_int_eq(error, 0);
  ck_assert_str_eq(output, expected);

}
END_TEST
*/
Suite *polishSuite() {
  Suite *polish = suite_create("[Polish Unit Test]");
  TCase *tc = tcase_create("polish");

  tcase_add_test(tc, polish_t1);
 /* tcase_add_test(tc, polish_t2);
  tcase_add_test(tc, polish_t3);
  tcase_add_test(tc, polish_t4);
  tcase_add_test(tc, polish_t5);
*/
  suite_add_tcase(polish, tc);

  return polish;
}
