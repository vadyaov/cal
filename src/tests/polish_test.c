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
  free(polishString);
}
END_TEST

START_TEST(polish_t2) {
  const char input[] = "+2 * asin(-0.56)/acos(0.123)+ ln(16.0/4.0)/log( 1.0/2.0)";
  int error = 0;
  double result = 0.0, expected = 0.0;
  char *polishString = polish(input, &error);
  if (0 == error) result = calc(polishString); 
  expected = +2 * asin(-0.56)/acos(0.123)+ log(16.0/4.0)/log10( 1.0/2.0);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
  free(polishString);
}
END_TEST

START_TEST(polish_t3) {
  const char input[] = "+2 * atan(-0.56)/sqrt(144.144)+ -3 * 10.0 mod 3.0";
  int error = 0;
  double result = 0.0, expected = 0.0;
  char *polishString = polish(input, &error);
  if (0 == error) result = calc(polishString); 
  expected = +2 * atan(-0.56)/sqrt(144.144)+ -3 * fmod(10.0, 3.0);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
  free(polishString);
}
END_TEST

START_TEST(polish_t4) {
  const char input[] = "2 ^ 3 ^ 2";
  int error = 0;
  double result = 0.0, expected = 0.0;
  char *polishString = polish(input, &error);
  if (0 == error) result = calc(polishString); 
  expected = pow(2.0, pow(3.0, 2.0)) /*fmod(10, fmod(1.3, 0.5))*/;
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
  free(polishString);
}
END_TEST


START_TEST(polish_t5) {
  const char input[] = "cos( 9.456+ 909  /sin((-1  )*ln(2.3  ))) + 5689.98 ^ (-1.9)";
  int error = 0;
  double result = 0.0, expected = 0.0;
  char *polishString = polish(input, &error);
  if (0 == error) result = calc(polishString); 
  expected = cos(9.456+909/sin((-1)*log(2.3)))+pow(5689.98, (-1.9));
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
  free(polishString);
}
END_TEST

START_TEST(polish_t6) {
  const char input[] = "tan(6.08123 / log(5.6321 + 345 * (-5.2345) * (-13.111))) / ln(45.32 / (+99.1334)) ^ (  +2)";
  int error = 0;
  double result = 0.0, expected = 0.0;
  char *polishString = polish(input, &error);
  if (0 == error) result = calc(polishString); 
  expected = tan(6.08123 / log10(5.6321 + 345 * (-5.2345) * (-13.111))) / pow(log(45.32 / (+99.1334)), 2);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
  free(polishString);
}
END_TEST

START_TEST(polish_t7) {
  const char input[] = "asin(0.256) * acos(-0.3456) / atan(0.000023456) + (2345.667 ^ (0.5) - 12.3)";
  int error = 0;
  double result = 0.0, expected = 0.0;
  char *polishString = polish(input, &error);
  if (0 == error) result = calc(polishString); 
  expected = asin(0.256) * acos(-0.3456) / atan(0.000023456) + (pow(2345.667, 0.5) - 12.3);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
  free(polishString);
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
  tcase_add_test(tc, polish_t6);
  tcase_add_test(tc, polish_t7);

  suite_add_tcase(polish, tc);

  return polish;
}
