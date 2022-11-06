#include "deposit.h"

char *depcalc(deposit *depo) {
  double per = 0.0, tax = 0.0, all = 0.0;
  char *res;
  char r = depo->replanishment, c = depo->frequency, m = depo->withdrawals;
  int paymInPer = 0, captInPer = 0, remInPer = 0;
  addrem ar = {0};
  if (depo->replanishment || depo->withdrawals) {
    paymInPer = countPayments(r, depo->depTerm);
    captInPer = countCapitals(c, depo->depTerm);
    remInPer = countPayments(m, depo->depTerm);
    ar.repPeriod = paymInPer ? (depo->depTerm / paymInPer) : 0;
    ar.remPeriod = remInPer ? (depo->depTerm / remInPer) : 0;
    ar.capPeriod = captInPer ? (depo->depTerm / captInPer) : 0;
  }
      printf("number of addings: %d\n", paymInPer);
      printf("number of removes: %d\n", remInPer);
      printf("number of capital: %d\n", captInPer);
      printf("1 period of ADD= %lf\n", ar.repPeriod);
      printf("1 period of REM= %lf\n", ar.remPeriod);
      printf("1 period of CAP= %lf\n", ar.capPeriod);
      
  if (depo->cap) {
    double sum = depo->depSum;
    all = capital(depo, &ar);
    if (!depo->replanishment && !depo->withdrawals)
      per = all - depo->depSum;
    else per = depo->depSum - sum - (paymInPer  + 1) * depo->repSum;
  } else {
      for (int i = 0, j = 1, k = 1; i < (int)depo->depTerm; i++) {
        per += round(depo->depSum * depo->intRate / 36500.0);
        if (depo->replanishment && i >= ((int)ar.repPeriod - 1) * j) {
          depo->depSum += depo->repSum;
          j++;
        }
        if (depo->withdrawals && i >= ((int)ar.remPeriod - 1) * k) {
          depo->depSum -= depo->remSum;
          k++;
        }
      }
    all = depo->depSum;
  }
  tax = per * depo->taxRate / 100.0;
  asprintf(&res, "Percents: %.2lf\nDeposit:  %.2lf\nYourTax:  %.2lf\n", per, all, tax);
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

void _capCount_(deposit *depo, addrem *a) {
  double p = 0.0;
  for (int i = 0, j = 1, k = 1, z = 1; i < depo->depTerm; i++) {
    p += depo->depSum * depo->intRate / 36500.0;
    if (i >= (a->capPeriod - 1) * z) {
      depo->depSum += p;
      z++;
      p = 0.0;
    }
    if (depo->replanishment && i >= (int)(a->repPeriod - 1) * j) {
      depo->depSum += depo->repSum;
      j++;
    }
    if (depo->withdrawals && i >= (int)(a->remPeriod - 1) * k) {
      depo->depSum -= depo->remSum;
      k++;
    }
  }
  depo->depSum += p;
}

double capital(deposit *depo, addrem *a) {
  double result = 0.0;
  char c = depo->frequency;
  double A = 0.0, B = 0.0;
  if (c == 'd') A = 36500, B = 1;
  else if (c == 'w') A = 5214.29, B = 7;
  else if (c == '1') A = 1200, B = 30.5;
  else if (c == 'q') A = 400, B = 91.35;
  else if (c == '6') A = 200, B = 182.5;
  else if (c == 'y') A = 100, B = 365;
  if (depo->replanishment || depo->withdrawals) {
    _capCount_(depo, a);
    result = depo->depSum;
  } else {
    result = capCount(depo, A, B);
  }
  return result;
}

int countPayments(char s, double days) {
  int res = 0;
  double months = floor(days / 30.417);
  int m = (int)(months);
  if (s == '1') res = m;
  else if (s == '2') res = m / 2;
  else if (s == 'q') res = m / 3;
  else if (s == '4') res = m / 4;
  else if (s == '6') res = m / 6;
  else if (s == 'y') res = m / 12;
  res -= 1;
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
