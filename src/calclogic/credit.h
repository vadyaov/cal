#ifndef _SRC_CALCLOGIC_CREDIT_H
#define _SRC_CALCLOGIC_CREDIT_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct credit {
  double amount, time, rate;
  char type;
} creditInfo;

char *creditCalc(creditInfo *input);
void initCreditInfo(creditInfo *info);

#endif /*  _SRC_CALCLOGIC_CREDIT_H */
