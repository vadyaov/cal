#include "stack_symb.h"

void push_s(struct stack_s **root, char s) {
  struct stack_s *new = (struct stack_s *)malloc(sizeof(struct stack_s));
  if (new) {
    struct stack_s *tmp = *root;
    new->c = s;
    new->next = tmp;
    *root = new;
  }
}

char pop_s(struct stack_s **root) {
  struct stack_s *tmp = (*root)->next;
  struct stack_s *head = *root;
  char s = (*root)->c;
  free(head);
  (*root) = tmp;
  return s;
}

char peek_s(struct stack_s *root) {
  char c = 0;
  if (root) c = root->c;
  return c;
}

void destroy_s(struct stack_s **root) {
  struct stack_s *tmp = *root;
  struct stack_s *next;
  while (tmp) {
    next = tmp->next;
    free(tmp);
    tmp = next;
  }
  (*root) = NULL;
}

/*                                   *
 * GOOD STUFF BUT I DON'T NEED IT :( *
 *                                   *

void print_stack_s(struct stack_s *root) {
  struct stack_s *tmp = root;
  if (!tmp) printf("empty stack_s!\n");
  printf("STACK:\n");
  while (tmp) {
    printf("c = %c\n", tmp->c);
    tmp = tmp->next;
  }
  printf("\n");
}
*/
