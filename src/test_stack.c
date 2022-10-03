#include "libs.h"
#include "stack.h"

int main() {
  struct stack *Head = NULL; // list is empy
  push(&Head, 'A');
  push(&Head, 'B');
  push(&Head, 't');
  char t = pop(&Head);
  printf("t = %c\n", t);
  print_stack(Head);
  destroy(&Head);
  print_stack(Head);
  return 0;
}

