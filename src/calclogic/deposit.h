#include <stdbool.h>
#include <stdio.h>

typedef struct depInfo {
  double depSum, depTerm, intRate, taxRate, repSum, remSum;
  char frequency, replanishment, withdrawals;
  bool cap;
} deposit;

char *depcalc(deposit *depo);
void initDeposit(deposit *depo);
