#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct credit {
  double amount, time, rate;
  char type;
} creditInfo;

char *creditCalc(creditInfo *input);
void initCreditInfo(creditInfo *info);
void printCreditStruct(creditInfo *inf);
