#include "stack_numb.h"

void push_n(struct stack_n **root, double num) {
  struct stack_n *new = (struct stack_n *)malloc(sizeof(struct stack_n));
  if (new) {
    struct stack_n *tmp = *root;
    new->number = num;
    new->next = tmp;
    *root = new;
  } else {
    printf("Malloc memory fail.\n");
  }
}

double pop_n(struct stack_n **root) {
  struct stack_n *tmp = (*root)->next;
  struct stack_n *head = *root;
  double num = (*root)->number;
  free(head);
  (*root) = tmp;
  return num;
}

double peek_n(struct stack_n* root) {
  double num = 0;
  if (root) num = root->number;
  return num;
}

void destroy_n(struct stack_n **root) {
  struct stack_n *tmp = *root;
  struct stack_n *next;
  while (tmp) {
    next = tmp->next;
    free(tmp);
    tmp = next;
  }
  (*root) = NULL;
}

void print_stack_n(struct stack_n *root) {
  struct stack_n *tmp = root;
  if (!tmp) printf("empty stack_n!\n");
  printf("STACK:\n");
  while (tmp) {
    printf("c = %lf\n", tmp->number);
    tmp = tmp->next;
  }
  printf("\n");
}
