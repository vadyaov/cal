#ifndef _SRC_STACK_H
#define _SRC_STACK_H

#include "libs.h"

struct stack {
  char c;
  struct stack* next;
};

void push(struct stack** root, char c);
char pop(struct stack** root);
void destroy(struct stack** root);
void print_stack(struct stack* root);

#endif  // _SRC_STACK_H
