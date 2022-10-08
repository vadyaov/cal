#include "stack_numb.h"

void push(struct stack **root, double num) {
  struct stack *new = (struct stack *)malloc(sizeof(struct stack));
  if (new) {
    struct stack *tmp = *root;
    new->number = num;
    new->next = tmp;
    *root = new;
  } else {
    printf("Malloc memory fail.\n");
  }
}

double pop(struct stack **root) {
  struct stack *tmp = (*root)->next;
  struct stack *head = *root;
  double num = (*root)->number;
  free(head);
  (*root) = tmp;
  return num;
}

double peek(struct stack* root) {
  double num = 0;
  if (root) num = root->number;
  return num;
}

void destroy(struct stack **root) {
  struct stack *tmp = *root;
  struct stack *next;
  while (tmp) {
    next = tmp->next;
    free(tmp);
    tmp = next;
  }
  (*root) = NULL;
}

void print_stack(struct stack *root) {
  struct stack *tmp = root;
  if (!tmp) printf("empty stack!\n");
  printf("STACK:\n");
  while (tmp) {
    printf("c = %lf\n", tmp->number);
    tmp = tmp->next;
  }
  printf("\n");
}
