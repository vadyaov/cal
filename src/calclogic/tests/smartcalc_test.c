#include "test.h"

START_TEST(polish_t1) {
  info x = {0};
  const char input[] = "-2 * sin(30)/cos(30) -(-1) + sqrt(16/4)/tan( 1/2)";
  int error = 0;
  double result = 0.0, expected = 0.0;
  result = calc(input, &x);
  expected = -2 * sin(30) / cos(30) - (-1) + sqrt(16 / 4) / tan(1.0 / 2.0);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t2) {
  info x = {0};
  const char input[] =
      "+2 * asin(-0.56)/acos(0.123)+ ln(16.0/4.0)/log( 1.0/2.0)";
  int error = 0;
  double result = 0.0, expected = 0.0;
  result = calc(input, &x);
  expected =
      +2 * asin(-0.56) / acos(0.123) + log(16.0 / 4.0) / log10(1.0 / 2.0);
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
  expected = +2 * atan(-0.56) / sqrt(144.144) + -3 * fmod(10.0, 3.0);
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
  const char input[] =
      "cos( 9.456+ 909  /sin((-1  )*ln(2.3  ))) + 5689.98 ^ (-1.9)";
  int error = 0;
  double result = 0.0, expected = 0.0;
  result = calc(input, &x);
  expected = cos(9.456 + 909 / sin((-1) * log(2.3))) + pow(5689.98, (-1.9));
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t6) {
  info x = {0};
  const char input[] =
      "tan(6.08123 / log(5.6321 + 345 * (-5.2345) * (-13.111))) / ln(45.32 / "
      "(+99.1334)) ^ (  +2)";
  int error = 0;
  double result = 0.0, expected = 0.0;
  result = calc(input, &x);
  expected = tan(6.08123 / log10(5.6321 + 345 * (-5.2345) * (-13.111))) /
             pow(log(45.32 / (+99.1334)), 2);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t7) {
  info x = {0};
  const char input[] =
      "asin(0.256) * acos(-0.3456) / atan(0.000023456) + (2345.667 ^ (0.5) - "
      "12.3)";
  int error = 0;
  double result = 0.0, expected = 0.0;
  result = calc(input, &x);
  expected = asin(0.256) * acos(-0.3456) / atan(0.000023456) +
             (pow(2345.667, 0.5) - 12.3);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t8) {
  info x = {0};
  const char input[] =
      "tan(6.08123 /log(   5.6321 + 345 * (-x) *(-   13.111))   ) /ln(45.32 / "
      "(+99.1334)   )^(  +2)";
  int error = 0;
  double result = 0.0, expected = 0.0;
  x.x = 5.2345;
  result = calc(input, &x);
  expected = tan(6.08123 / log10(5.6321 + 345 * (-5.2345) * (-13.111))) /
             pow(log(45.32 / (+99.1334)), 2);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t9) {
  info x = {0};
  const char input[] =
      "555.666 mod 3.456 + ( ( atan(0.9876/x) + (-asin(0.222)  )  )  * cos((x "
      "* 3) ^ (  0.7889 ) ) - 2222.2 / ( -777.7 ) )";
  int error = 0;
  double result = 0.0, expected = 0.0;
  x.x = 17.239;
  result = calc(input, &x);
  expected = fmod(555.666, 3.456) + ((atan(0.9876 / 17.239) + (-asin(0.222))) *
                                         cos(pow(17.239 * 3, 0.7889)) -
                                     2222.2 / (-777.7));
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t10) {
  info x = {0};
  const char input[] =
      "-1678.2322 * x +  sqrt( log  (38.38 /24.55 ) + ln(58.2 - (-300.4))) * x "
      "* x * (-x)";
  int error = 0;
  double result = 0.0, expected = 0.0;
  x.x = 0.009;
  result = calc(input, &x);
  expected =
      -1678.2322 * 0.009 + sqrt(log10(38.38 / 24.55) + log(58.2 - (-300.4))) *
                               0.009 * 0.009 * (-0.009);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t11) {
  info x = {0};
  const char input[] =
      "678.987 * sin ( 23.2 -  6.7 +  sin(x *   x) -9.789 * cos(22.37/2.32)) + "
      "tan(342.35 ^ 0.7) + sin ( 23.2 -  6.7 +  sin(x *   x)"
      "* cos(22.37/2.32) + tan(-3.4235))";
  int error = 0;
  double result = 0.0, expected = 0.0;
  x.x = 17.239;
  result = calc(input, &x);
  expected =
      678.987 *
          sin(23.2 - 6.7 + sin(17.239 * 17.239) - 9.789 * cos(22.37 / 2.32)) +
      tan(pow(342.35, 0.7)) +
      sin(23.2 - 6.7 + sin(17.239 * 17.239) * cos(22.37 / 2.32) + tan(-3.4235));
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t12) {
  info x = {0};
  const char input[] =
      "-(-87.543*sin(0.999+tan(x)-2.234))-50.66*(acos(0.234)/atan(0.55))";
  int error = 0;
  double result = 0.0, expected = 0.0;
  x.x = 55.5;
  result = calc(input, &x);
  expected = -(-87.543 * sin(0.999 + tan(55.5) - 2.234)) -
             50.66 * (acos(0.234) / atan(0.55));
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t1_error) {
  info x;
  initInfo(&x);
  const char input[] = ".3";
  double result = 0.0, expected = 0.0;
  x.x = 55.5;
  result = calc(input, &x);
  expected = 0.0;
  ck_assert_int_eq(x.err, 1);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t2_error) {
  info x;
  initInfo(&x);
  const char input[] = "sin(3)cos11)/15";
  double result = 0.0, expected = 0.0;
  x.x = 55.5;
  result = calc(input, &x);
  expected = 0.0;
  ck_assert_int_eq(x.err, 1);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t3_error) {
  info x;
  initInfo(&x);
  const char input[] = "+-/sin*(3)//cos11)/15";
  double result = 0.0, expected = 0.0;
  x.x = 55.5;
  result = calc(input, &x);
  expected = 0.0;
  ck_assert_int_eq(x.err, 1);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t4_error) {
  info x;
  initInfo(&x);
  const char input[] = "35/+*///mod1-+";
  double result = 0.0, expected = 0.0;
  x.x = 55.5;
  result = calc(input, &x);
  expected = 0.0;
  ck_assert_int_eq(x.err, 1);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t5_error) {
  info x;
  initInfo(&x);
  const char input[] = "sin((--1(()()))))";
  double result = 0.0, expected = 0.0;
  x.x = 55.5;
  result = calc(input, &x);
  expected = 0.0;
  ck_assert_int_eq(x.err, 1);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t6_error) {
  info x;
  initInfo(&x);
  const char input[] = "sin cos + tan log((()) -";
  double result = 0.0, expected = 0.0;
  x.x = 55.5;
  result = calc(input, &x);
  expected = 0.0;
  ck_assert_int_eq(x.err, 1);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t7_error) {
  info x;
  initInfo(&x);
  const char input[] = "3...44.5..2..23.4..5.5.5.3.4.3.4.";
  double result = 0.0, expected = 0.0;
  x.x = 55.5;
  result = calc(input, &x);
  expected = 0.0;
  ck_assert_int_eq(x.err, 1);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t8_error) {
  info x;
  initInfo(&x);
  const char input[] = "sin((((((((((((((1)";
  double result = 0.0, expected = 0.0;
  x.x = 55.5;
  result = calc(input, &x);
  expected = 0.0;
  ck_assert_int_eq(x.err, 1);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(polish_t9_error) {
  info x;
  initInfo(&x);
  const char input[] = "-------sin-------((((((((((((((++-++1)++++++++";
  double result = 0.0, expected = 0.0;
  x.x = 55.5;
  result = calc(input, &x);
  expected = 0.0;
  ck_assert_int_eq(x.err, 1);
  ck_assert_double_eq_tol(result, expected, 1e-7);
}
END_TEST

START_TEST(credit_t1) {
  creditInfo info;
  initCreditInfo(&info);
  info.amount = 500000.0;
  info.time = 24.0;
  info.rate = 7.0;
  info.type = 'a';
  char *out = creditCalc(&info);
  ck_assert_str_eq(out,
                   "Month Payment: 22386.29\n"
                   "Total Payment: 537270.95\nOverpayment : 37270.95\n");
  free(out);
}
END_TEST

START_TEST(credit_t2) {
  creditInfo info;
  initCreditInfo(&info);
  info.amount = 10000000.0;
  info.time = 15 * 12;
  info.rate = 11.2;
  info.type = 'd';
  char *out = creditCalc(&info);
  ck_assert_str_eq(out,
                   "Month Payment:\n\t from: 148888.89\n\t   to:    56074.07\n"
                   "Total Payment: 18446666.67\nOverpayment : 8446666.67\n");
  free(out);
}
END_TEST

START_TEST(deposit_nocap_t1) {
  deposit depo;
  initDeposit(&depo);
  depo.depSum = 350000.0;
  char startdate[] = "12.11.2022", enddate[] = "12.11.2023";
  depo.depTerm = days(startdate, enddate);
  depo.intRate = 4.7;
  depo.taxRate = 30;
  depo.frequency = chooseFrequency("every quarter");
  depo.cap = false;
  char *out = depcalc(&depo);
  ck_assert_str_eq(
      out, "Percents: 16450.00\nDeposit:  350000.00\nYourTax:  4935.00\n");
  free(out);
}
END_TEST

START_TEST(deposit_cap_t1) {
  deposit depo;
  initDeposit(&depo);
  depo.depSum = 350000.0;
  char startdate[] = "12.11.2022", enddate[] = "12.11.2023";
  depo.depTerm = days(startdate, enddate);
  depo.intRate = 4.7;
  depo.taxRate = 30;
  depo.frequency = chooseFrequency("every day");
  depo.cap = true;
  char *out = depcalc(&depo);
  ck_assert_str_eq(
      out, "Percents: 16842.00\nDeposit:  366842.00\nYourTax:  5053.00\n");
  free(out);
}
END_TEST

START_TEST(deposit_nocap_t2) {
  deposit depo;
  initDeposit(&depo);
  depo.depSum = 500000.0;
  char startdate[] = "12.11.2022", enddate[] = "17.10.2025";
  depo.depTerm = days(startdate, enddate);
  depo.intRate = 4.7;
  depo.taxRate = 30;
  depo.frequency = chooseFrequency("every month");
  depo.replanishment = chooseFrequency("every 6 months");
  depo.repSum = 20000;
  depo.cap = false;
  char *out = depcalc(&depo);
  ck_assert_str_eq(
      out, "Percents: 75609.00\nDeposit:  600000.00\nYourTax:  22683.00\n");
  free(out);
}
END_TEST

START_TEST(deposit_cap_t2) {
  deposit depo;
  initDeposit(&depo);
  depo.depSum = 500000.0;
  char startdate[] = "12.11.2022", enddate[] = "17.10.2025";
  depo.depTerm = days(startdate, enddate);
  depo.intRate = 4.7;
  depo.taxRate = 30;
  depo.frequency = chooseFrequency("every week");
  depo.replanishment = chooseFrequency("every 2 months");
  depo.repSum = 20000;
  depo.withdrawals = chooseFrequency("every 4 month");
  depo.remSum = 15000;
  depo.cap = true;
  char *out = depcalc(&depo);
  ck_assert_str_eq(
      out, "Percents: 89300.00\nDeposit:  809300.00\nYourTax:  26790.00\n");
  free(out);
}
END_TEST

START_TEST(deposit_cap_t3) {
  deposit depo;
  initDeposit(&depo);
  depo.depSum = 350000.0;
  char startdate[] = "12.11.2022", enddate[] = "12.11.2025";
  depo.depTerm = days(startdate, enddate);
  depo.intRate = 4.7;
  depo.taxRate = 30;
  depo.frequency = chooseFrequency("every year");
  depo.cap = true;
  char *out = depcalc(&depo);
  ck_assert_str_eq(
      out, "Percents: 51755.00\nDeposit:  401755.00\nYourTax:  15527.00\n");
  free(out);
}
END_TEST

Suite *SmartCalcSuite() {
  Suite *smartcalc = suite_create("[SmartCalc Unit Test]");
  TCase *tc = tcase_create("smartcalc");

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
  tcase_add_test(tc, polish_t1_error);
  tcase_add_test(tc, polish_t2_error);
  tcase_add_test(tc, polish_t3_error);
  tcase_add_test(tc, polish_t4_error);
  tcase_add_test(tc, polish_t5_error);
  tcase_add_test(tc, polish_t6_error);
  tcase_add_test(tc, polish_t7_error);
  tcase_add_test(tc, polish_t8_error);
  tcase_add_test(tc, polish_t9_error);

  tcase_add_test(tc, credit_t1);
  tcase_add_test(tc, credit_t2);

  tcase_add_test(tc, deposit_nocap_t1);
  tcase_add_test(tc, deposit_nocap_t2);
  tcase_add_test(tc, deposit_cap_t1);
  tcase_add_test(tc, deposit_cap_t2);
  tcase_add_test(tc, deposit_cap_t3);

  suite_add_tcase(smartcalc, tc);

  return smartcalc;
}
