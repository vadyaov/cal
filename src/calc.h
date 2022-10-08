#include <math.h>
#include "stack_numb.h"
#include "polish.h"

double calc(char *polishString);
double convert_to_double(char *src, int *i);
int makeOperator(struct stack_n **root, char s);
