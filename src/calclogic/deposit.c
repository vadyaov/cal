#include "deposit.h"

char *depcalc(deposit *depo) {
  double per = 0.0, tax = 0.0, all = 0.0;
  if (depo->cap) {
// i must implement the choose of function to use by using pointer to a function!!!!!!
    void (*foo)(deposit*, double*, double*, double*) = selectAction(depo);
    foo(depo, &per, &all, &tax);
    
  } else {
    per = (depo->depSum * depo->intRate * depo->depTerm) / 36500.0;
    all = depo->depSum;
    tax = per * depo->taxRate / 100.0;
  }
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

void everyDayCap(deposit *depo, double *per, double *all, double *tax) {
  *all = depo->depSum * pow(1.0 + depo->intRate / 36500, depo->depTerm);
  *per = *all - depo->depSum;
  *tax = *per * (depo->taxRate / 100);
}

void (*selectAction(deposit *dep))(deposit *, double *, double *, double *) {
  char capi = dep->frequency;
  void (*actions[])(deposit *depo, double *per, double *all, double *tax) = 
       { everyDayCap };
  switch (capi) {
    case 'd':
      return actions[0];
      break;
  }
  return NULL;
}

int main() {
  char date1[] = "04.11.2022";
  char date2[] = "04.08.2023";
  printf("%zu\n\n",days(date1, date2));
  deposit vklad;
  initDeposit(&vklad);
  vklad.depSum = 350000;
  vklad.depTerm = days(date1, date2);
  vklad.intRate = 4.7;
  vklad.taxRate = 13.0;
  vklad.cap = true;
  vklad.frequency = 'd';
  depcalc(&vklad);
  return 0;
}
