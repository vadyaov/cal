#include "deposit.h"

char *depcalc(deposit *depo) {
  double per = 0.0, tax = 0.0, all = 0.0;
  char *res;
  if (depo->cap) {
    all = capital(depo);
    per = all - depo->depSum;
  } else {
    if (depo->replanishment || depo->withdrawals) {
      char r = depo->replanishment;
      char c = depo->frequency;
      char m = depo->withdrawals;
      printf("payment frequency = %c\n", c);
      printf("adding to deposit = %c\n", r);
      printf("remove from depos = %c\n", m);
      int paymInPer = countPayments(r, depo->depTerm);
      int captInPer = countCapitals(c, depo->depTerm);
      printf("number of addings: %d\n", paymInPer);
      printf("number of capital: %d\n", captInPer);
      per += (depo->depSum * depo->intRate * depo->depTerm) / 36500.0;
    } else {
      all = depo->depSum;
      per = (depo->depSum * depo->intRate * depo->depTerm) / 36500.0;
    }
  }
  tax = per * depo->taxRate / 100.0;
  asprintf(&res, "percents:%lf\nall:%lf\ntax:%lf\n", per, all, tax);
  printf("strlen = %zu\n", strlen(res));
  return res;
}

void initDeposit(deposit *depo) {
  depo->depSum = 0.0;
  depo->depTerm = 0.0; 
  depo->intRate = 0.0;
  depo->taxRate = 0.0;
  depo->repSum = 0.0;
  depo->remSum = 0.0;
  depo->frequency = 0;
  depo->replanishment = 0;
  depo->withdrawals = 0;
  depo->cap = false;
}

size_t days(const char *startDate, const char *endDate) {
  int startDay = toNumber(startDate, 2), startMonth = toNumber(startDate + 3, 2),
      startYear = toNumber(startDate + 6, 4),
      endDay = toNumber(endDate, 2), endMonth = toNumber(endDate + 3, 2),
      endYear = toNumber(endDate + 6, 4);
  size_t u1 = yulian(startDay, startMonth, startYear),
         u2 = yulian(endDay, endMonth, endYear);
  return u2 - u1;
}

int toNumber(const char *p, int n) {
  int res = 0, i = 0, size = n;
  while (i < n)
    res += (p[i++] - '0') * pow(10, size-- - 1);
  return res;
}

size_t yulian(int day, int month, int year) {
  int a = (14 - month) / 12,
      y = year + 4800 - a,
      m = month + 12 * a - 3;
  size_t JDN = day + ((153 * m + 2) / 5) + 365 * y + y / 4 - y / 100 + y / 400 -
               32045;
  return JDN;
}

char chooseFrequency(const char *str) {
  char res = 0;
  if (strstr(str, "day")) res = 'd';
  else if (strstr(str, "week")) res = 'w';
  else if (strchr(str, '2')) res = '2';
  else if (strchr(str, '4')) res = '4';
  else if (strchr(str, '6')) res = '6';
  else if (strstr(str, "month")) res = '1';
  else if (strstr(str, "quarter")) res = 'q';
  else if (strstr(str, "year")) res = 'y';
  return res;
}

double capCount(deposit *depo, double a, double b) {
  return depo->depSum * pow(1.0 + depo->intRate / a, depo->depTerm / b);
}

double capital(deposit *depo) {
  char a = depo->frequency;
  double A = 0.0, B = 0.0;
  if (a == 'd') A = 36500, B = 1;
  else if (a == 'w') A = 5214.29, B = 7;
  else if (a == '1') A = 1200, B = 30.5;
  else if (a == 'q') A = 400, B = 91.35;
  else if (a == '6') A = 200, B = 182.5;
  else if (a == 'y') A = 100, B = 365;
  return capCount(depo, A, B);
}

int countPayments(char s, double days) {
  int res = 0;
  double months = days / 30.417;
  int m = (int)(months);
  if (s == '1') res = m;
  else if (s == '2') res = m / 2;
  else if (s == 'q') res = m / 3;
  else if (s == '4') res = m / 4;
  else if (s == '6') res = m / 6;
  else if (s == 'y') res = m / 12;
  return res;
}

int countCapitals(char c, double days) {
  int res = 0;
  if (c == 'd') res = days;
  else if (c == 'w') res = days / 7;
  else if (c == '1') res = days / 30.417;
  else if (c == 'q') res = days / (3 * 30.417);
  else if (c == '6') res = days / (6 * 30.417);
  else if (c == 'y') res = days / (12 * 30.417);
  return res;
}

void printDepo(deposit dep) {
  printf("depSum:%lf\ndeTerm:%lf\nintRate:%lf\ntaxRate:%lf\nrepSum:%lf\nremSum:%lf\nfrequency:%c\nreplanishm:%c\nwithdraw:%c\ncap:%d\n\n",
          dep.depSum, dep.depTerm, dep.intRate, dep.taxRate, dep.repSum, dep.remSum, dep.frequency, dep.replanishment, dep.withdrawals, dep.cap);
}
