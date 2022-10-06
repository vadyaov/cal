#include "test.h"

START_TEST(polish_t1) {
  char input[] = "";
  int error = 0;
  char *output = polish(input, &error);
  if (output) free(output);
  char expected[] = "";
  ck_assert_int_eq(error, 0);
  ck_assert_str_eq(output, expected);
}
END_TEST
  char input[] = "";
  int error = 0;
  char *output = polish(input, &error);
  if (output) free(output);
  char expected[] = "";
  ck_assert_int_eq(error, 0);
  ck_assert_str_eq(output, expected);

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

Suite *polishSuite() {
  Suite *polish = suite_create("[Polish Unit Test]");
  TCase *tc = tcase_create("polish");

  tcase_add_test(tc, polish_t1);
  tcase_add_test(tc, polish_t2);
  tcase_add_test(tc, polish_t3);
  tcase_add_test(tc, polish_t4);
  tcase_add_test(tc, polish_t5);

  suite_add_tcase(s, tc);

  return s;
}
