#include "deposit.h"

char *depcalc(deposit *depo) {
  double per = 0.0, tax = 0.0, all = 0.0;
  if (depo->cap) {
    void (*foo)(deposit*, double*) = selectAction(depo->frequency);
    foo(depo, &all);
    per = all - depo->depSum;
  } else {
    per = (depo->depSum * depo->intRate * depo->depTerm) / 36500.0;
    all = depo->depSum;
  }
  tax = per * depo->taxRate / 100.0;
  printf("percents:%lf\nall:%lf\ntax:%lf\n", per, all, tax);
  return NULL;
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

size_t days(char *startDate, char *endDate) {
  // days = endDate - startDate
  int startDay = toNumber(startDate, 2), startMonth = toNumber(startDate + 3, 2),
      startYear = toNumber(startDate + 6, 4),
      endDay = toNumber(endDate, 2), endMonth = toNumber(endDate + 3, 2),
      endYear = toNumber(endDate + 6, 4);
  size_t u1 = yulian(startDay, startMonth, startYear),
         u2 = yulian(endDay, endMonth, endYear);
  return u2 - u1;
}

int toNumber(char *p, int n) {
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

char chooseFrequency(char *str) {
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

void everyDayCap(deposit *depo, double *all) {
  *all = depo->depSum * pow(1.0 + depo->intRate / 36500, depo->depTerm);
}

void everyWeekCap(deposit *depo, double *all) {
  *all = depo->depSum * pow(1.0 + depo->intRate / 5214.29, depo->depTerm / 7.0);
}

void everyMonthCap(deposit *depo, double *all) {
  *all = depo->depSum * pow(1.0 + depo->intRate / 1200, depo->depTerm / 30.5);
}

void everyQuarterCap(deposit *depo, double *all) {
  *all = depo->depSum * pow(1.0 + depo->intRate / 400, depo->depTerm / 91.35);
}

void everyHalfYearCap(deposit *depo, double *all) {
  *all = depo->depSum * pow(1.0 + depo->intRate / 200, depo->depTerm / 182.5);
}

void everyYearCap(deposit *depo, double *all) {
  *all = depo->depSum * pow(1.0 + depo->intRate / 100, depo->depTerm / 365.0);
}

double capCount(double *all, double a, double b) {
  return depo->depSum * pow(1.0 + depo->intRate / a, depo->depTerm / b);
}

void (*selectAction(char a))(deposit *, double *) {
  void (*returnAction)(deposit *, double *) = NULL;
  void (*actions[])(deposit *, double *) = {everyDayCap, everyWeekCap, 
        everyMonthCap, everyQuarterCap, everyHalfYearCap, everyYearCap};
  if (a == 'd') returnAction = actions[0];
  else if (a == 'w') returnAction = actions[1];
  else if (a == '1') returnAction = actions[2];
  else if (a == 'q') returnAction = actions[3];
  else if (a == '6') returnAction = actions[4];
  else if (a == 'y') returnAction = actions[5];
  return returnAction;
}

int main() {
  char date1[] = "04.11.2022";
  char date2[] = "04.08.2023";
  deposit vklad;
  initDeposit(&vklad);
  vklad.depSum = 350000;
  vklad.depTerm = days(date1, date2);
  vklad.intRate = 4.78;
  vklad.taxRate = 13.0;
  vklad.cap = true;
  vklad.frequency = 'd';
  depcalc(&vklad);
  return 0;
}
