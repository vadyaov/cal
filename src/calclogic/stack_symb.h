#ifndef _SRC_STACK_H
#define _SRC_STACK_H

#include "stdlib.h"

struct stack_s {
  char c;
  struct stack_s* next;
};

void push_s(struct stack_s** root, char c);
char pop_s(struct stack_s** root);
char peek_s(struct stack_s* root);
void destroy_s(struct stack_s** root);
void print_stack_s(struct stack_s* root);

#endif /*  _SRC_STACK_H */
