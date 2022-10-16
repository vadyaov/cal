#include <math.h>
#include "stack_numb.h"
#include "polish.h"

typedef struct xinfo {
  double x;
} info;

double calc(char *polishString, info *info);
double convert_to_double(char *src, int *i);
int makeOperator(struct stack_n **root, char s);
int makeFunction(struct stack_n **root, char s);
