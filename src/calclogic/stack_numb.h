#ifndef _SRC_STACK_H
#define _SRC_STACK_H

#include "stdlib.h"

struct stack_n {
  double number;
  struct stack_n* next;
};

void push_n(struct stack_n** root, double num);
double pop_n(struct stack_n** root);

/*

double peek_n(struct stack_n* root);
void destroy_n(struct stack_n** root);
void print_stack_n(struct stack_n* root);

*/

#endif  // _SRC_STACK_H
