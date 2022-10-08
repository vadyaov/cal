#include "stack_numb.h"

int main() {
  struct stack *Head = NULL; // list is empy
  push(&Head, 13.25);
  push(&Head, 11.1);
  push(&Head, 0.0);
  double t = pop(&Head);
  printf("t = %lf\n", t);
  print_stack(Head);
  destroy(&Head);
  print_stack(Head);
  return 0;
}

