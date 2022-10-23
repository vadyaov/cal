#include <math.h>

#include "polish.h"
#include "stack_numb.h"

typedef struct xinfo {
  double x;
  int err;
} info;

double calc(const char *polishString, info *info);
double convert_to_double(char *src, int *i);
int makeOperator(struct stack_n **root, char s);
int makeFunction(struct stack_n **root, char s);
