#include "stack.h"

void push(struct stack **root, char s) {
  struct stack *new = (struct stack *)malloc(sizeof(struct stack));
  struct stack *tmp = *root;
  new->c = s;
  new->next = tmp;
  *root = new;
}

char pop(struct stack **root) {
  struct stack *tmp = (*root)->next;
  struct stack *head = *root;
  char s = (*root)->c;
  free(head);
  (*root) = tmp;
  return s;
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
    printf("c = %c\n", tmp->c);
    tmp = tmp->next;
  }
  printf("\n");
}
