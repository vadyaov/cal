#ifndef _SRC_STACK_H
#define _SRC_STACK_H

#include "libs.h"

struct stack {
  double number;
  struct stack* next;
};

void push(struct stack** root, double num);
double pop(struct stack** root);
double peek(struct stack* root);
void destroy(struct stack** root);
void print_stack(struct stack* root);

#endif  // _SRC_STACK_H
