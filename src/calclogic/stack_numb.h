#ifndef _SRC_STACK_H
#define _SRC_STACK_H

#include "stdlib.h"

struct stack_n {
  double number;
  struct stack_n *next;
};

void push_n(struct stack_n **, double);
double pop_n(struct stack_n **);

#endif /*   _SRC_STACK_H */
