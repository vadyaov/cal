#ifndef _SRC_CALCLOGIC_DEPOSIT_H
#define _SRC_CALCLOGIC_DEPOSIT_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct depInfo {
  double depSum, depTerm, intRate, taxRate, repSum, remSum;
  char frequency, replanishment, withdrawals;
  bool cap;
} deposit;

char *depcalc(deposit *depo);
void initDeposit(deposit *depo);
size_t days(const char *startDate, const char *endDate);
int toNumber(const char *p, int n);
size_t yulian(int day, int month, int year);
char chooseFrequency(const char *str);

void calcDepo(deposit *depo, double *percents, double *tax, double *money);
double daysFrequency(char c);

#endif /*   _SRC_CALCLOGIC_DEPOSIT_H */
