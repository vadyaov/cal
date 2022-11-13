#ifndef _SRC_CALCLOGIC_CALC_H
#define _SRC_CALCLOGIC_CALC_H

#include <math.h>

#include "polish.h"
#include "stack_numb.h"

typedef struct xinfo {
  double x;
  int err;
} info;

double calc(const char *, info *);
double convert_to_double(char *, int *);
int makeOperator(struct stack_n **, char);
int makeFunction(struct stack_n **, char);
void initInfo(info *);

#endif /* _SRC_CALCLOGIC_CALC_H */
