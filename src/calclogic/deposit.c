#include "deposit.h"

char *depcalc(deposit *depo) {
  double per = 0.0, tax = 0.0, all = 0.0;
  char *res = NULL;
  char buf[256] = {'\0'};
  calcDepo(depo, &per, &tax, &all);
  sprintf(buf, "Percents: %.2lf\nDeposit:  %.2lf\nYourTax:  %.2lf\n", per, all,
          tax);
  res = calloc(strlen(buf) + 1, sizeof(char));
  if (res) strcpy(res, buf);
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
  int startDay = toNumber(startDate, 2),
      startMonth = toNumber(startDate + 3, 2),
      startYear = toNumber(startDate + 6, 4), endDay = toNumber(endDate, 2),
      endMonth = toNumber(endDate + 3, 2), endYear = toNumber(endDate + 6, 4);
  size_t u1 = yulian(startDay, startMonth, startYear),
         u2 = yulian(endDay, endMonth, endYear);
  return u2 - u1;
}

int toNumber(const char *p, int n) {
  int res = 0, i = 0, size = n;
  while (i < n) res += (p[i++] - '0') * pow(10, size-- - 1);
  return res;
}

size_t yulian(int day, int month, int year) {
  int a = (14 - month) / 12, y = year + 4800 - a, m = month + 12 * a - 3;
  size_t JDN =
      day + ((153 * m + 2) / 5) + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
  return JDN;
}

char chooseFrequency(const char *str) {
  char res = 0;
  if (strstr(str, "day"))
    res = 'd';
  else if (strstr(str, "week"))
    res = 'w';
  else if (strchr(str, '2'))
    res = '2';
  else if (strchr(str, '4'))
    res = '4';
  else if (strchr(str, '6'))
    res = '6';
  else if (strstr(str, "month"))
    res = '1';
  else if (strstr(str, "quarter"))
    res = 'q';
  else if (strstr(str, "year"))
    res = 'y';
  return res;
}

void calcDepo(deposit *depo, double *percents, double *tax, double *money) {
  int i = 0, ii = 1, jj = 1, kk = 1;
  double p = 0.0;
  double dayPer = depo->intRate / 36500.0,
         capPeriod = daysFrequency(depo->frequency),
         addPeriod = daysFrequency(depo->replanishment),
         remPeriod = daysFrequency(depo->withdrawals);
  while (i < depo->depTerm) {
    p += depo->depSum * dayPer;
    if (depo->cap && i == (int)(capPeriod * ii)) {
      depo->depSum += p;
      *percents += p;
      p = 0.0;
      ii++;
    }
    if (depo->replanishment && i == (int)(addPeriod * jj)) {
      if (jj++ <= (int)(depo->depTerm / addPeriod))
        depo->depSum += depo->repSum;
    }
    if (depo->withdrawals && i == (int)(remPeriod * kk)) {
      if (kk++ <= (int)(depo->depTerm / remPeriod))
        depo->depSum -= depo->remSum;
    }
    i++;
  }
  if (i == depo->depTerm && depo->cap) depo->depSum += p;
  *percents += p;
  *percents = round(*percents);
  *money = round(depo->depSum);
  *tax = round(*percents * depo->taxRate / 100.0);
}

double daysFrequency(char c) {
  int i = 0;
  const char f[] = "dw12q46y";
  const double daysInMonth = 30.4167;
  const double r[] = {1.0,
                      7.0,
                      daysInMonth,
                      daysInMonth * 2,
                      daysInMonth * 3,
                      daysInMonth * 4,
                      daysInMonth * 6,
                      daysInMonth * 12};
  while (f[i] && f[i] != c) i++;
  return r[i];
}
