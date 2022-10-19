#include "test.h"

START_TEST(polish_t1) {
  info x = {0};
  const char input[] = "-2 * sin(30)/cos(30) -(-1) + sqrt(16/4)/tan( 1/2)";
  int error = 0;
  double result = 0.0, expected = 0.0;
  result = calc(input, &x); 
  expected = -2 * sin(30)/cos(30) -(-1) + sqrt(16/4)/tan( 1.0/2.0);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t2) {
  info x = {0};
  const char input[] = "+2 * asin(-0.56)/acos(0.123)+ ln(16.0/4.0)/log( 1.0/2.0)";
  int error = 0;
  double result = 0.0, expected = 0.0;
  result = calc(input, &x); 
  expected = +2 * asin(-0.56)/acos(0.123)+ log(16.0/4.0)/log10( 1.0/2.0);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t3) {
  info x = {0};
  const char input[] = "+2 * atan(-0.56)/sqrt(144.144)+ -3 * 10.0 mod 3.0";
  int error = 0;
  double result = 0.0, expected = 0.0;
  result = calc(input, &x); 
  expected = +2 * atan(-0.56)/sqrt(144.144)+ -3 * fmod(10.0, 3.0);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t4) {
  info x = {0};
  const char input[] = "2 ^ 3 ^ 2";
  int error = 0;
  double result = 0.0, expected = 0.0;
  result = calc(input, &x); 
  expected = pow(2.0, pow(3.0, 2.0)) /*fmod(10, fmod(1.3, 0.5))*/;
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST


START_TEST(polish_t5) {
  info x = {0};
  const char input[] = "cos( 9.456+ 909  /sin((-1  )*ln(2.3  ))) + 5689.98 ^ (-1.9)";
  int error = 0;
  double result = 0.0, expected = 0.0;
  result = calc(input, &x); 
  expected = cos(9.456+909/sin((-1)*log(2.3)))+pow(5689.98, (-1.9));
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t6) {
  info x = {0};
  const char input[] = "tan(6.08123 / log(5.6321 + 345 * (-5.2345) * (-13.111))) / ln(45.32 / (+99.1334)) ^ (  +2)";
  int error = 0;
  double result = 0.0, expected = 0.0;
  result = calc(input, &x); 
  expected = tan(6.08123 / log10(5.6321 + 345 * (-5.2345) * (-13.111))) / pow(log(45.32 / (+99.1334)), 2);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t7) {
  info x = {0};
  const char input[] = "asin(0.256) * acos(-0.3456) / atan(0.000023456) + (2345.667 ^ (0.5) - 12.3)";
  int error = 0;
  double result = 0.0, expected = 0.0;
  result = calc(input, &x); 
  expected = asin(0.256) * acos(-0.3456) / atan(0.000023456) + (pow(2345.667, 0.5) - 12.3);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t8) {
  info x = {0};
  const char input[] = "tan(6.08123 /log(   5.6321 + 345 * (-x) *(-   13.111))   ) /ln(45.32 / (+99.1334)   )^(  +2)";
  int error = 0;
  double result = 0.0, expected = 0.0;
  x.x = 5.2345;
  result = calc(input, &x); 
  expected = tan(6.08123 / log10(5.6321 + 345 * (-5.2345) * (-13.111))) / pow(log(45.32 / (+99.1334)), 2);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t9) {
  info x = {0};
  const char input[] = "555.666 mod 3.456 + ( ( atan(0.9876/x) + (-asin(0.222)  )  )  * cos((x * 3) ^ (  0.7889 ) ) - 2222.2 / ( -777.7 ) )";
  int error = 0;
  double result = 0.0, expected = 0.0;
  x.x = 17.239;
  result = calc(input, &x); 
  expected = fmod(555.666, 3.456) + ((atan(0.9876/17.239) + (-asin(0.222))) * cos(pow(17.239 * 3, 0.7889)) - 2222.2 / (-777.7));
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t10) {
  info x = {0};
  const char input[] = "-1678.2322 * x +  sqrt( log  (38.38 /24.55 ) + ln(58.2 - (-300.4))) * x * x * (-x)";
  int error = 0;
  double result = 0.0, expected = 0.0;
  x.x = 0.009; 
  result = calc(input, &x); 
  expected = -1678.2322 * 0.009 +  sqrt( log10  (38.38 /24.55 ) + log(58.2 - (-300.4)))* 0.009 * 0.009 * (-0.009);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t11) {
  info x = {0};
  const char input[] = "678.987 * sin ( 23.2 -  6.7 +  sin(x *   x) -9.789 * cos(22.37/2.32)) + tan(342.35 ^ 0.7) + sin ( 23.2 -  6.7 +  sin(x *   x)"
                        "* cos(22.37/2.32) + tan(-3.4235))";
  int error = 0;
  double result = 0.0, expected = 0.0;
  x.x = 17.239; 
  result = calc(input, &x); 
  expected = 678.987 * sin ( 23.2 -  6.7 +  sin(17.239 *   17.239) -9.789 * cos(22.37/2.32)) + tan(pow(342.35, 0.7)) + sin ( 23.2 -  6.7 +  sin(17.239 *   17.239)
                        * cos(22.37/2.32) + tan(-3.4235));
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t12) {
  info x = {0};
  const char input[] = "-(-87.543*sin(0.999+tan(x)-2.234))-50.66*(acos(0.234)/atan(0.55))";
  int error = 0;
  double result = 0.0, expected = 0.0;
  x.x = 55.5; 
  result = calc(input, &x); 
  expected = -(-87.543*sin(0.999+tan(55.5)-2.234))-50.66*(acos(0.234)/atan(0.55));
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
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
  tcase_add_test(tc, polish_t8);
  tcase_add_test(tc, polish_t9);
  tcase_add_test(tc, polish_t10);
  tcase_add_test(tc, polish_t11);
  tcase_add_test(tc, polish_t12);

  suite_add_tcase(polish, tc);

  return polish;
}
