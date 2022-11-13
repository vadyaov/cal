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

char *depcalc(deposit *);
void initDeposit(deposit *);
size_t days(const char *, const char *);
int toNumber(const char *, int);
size_t yulian(int, int, int);
char chooseFrequency(const char *);

void calcDepo(deposit *, double *, double *, double *);
double daysFrequency(char);

#endif /*   _SRC_CALCLOGIC_DEPOSIT_H */
