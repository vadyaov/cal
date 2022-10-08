#include <string.h>

#include "stack_symb.h"

char *polish(const char *input, int *err);

char *pretty_input(const char *input, int *error);
int is_valid_symb(char c, const char *symbols);
int is_bad_symb(char c, const char *symbols);
char hash(const char *src, int *n, int *replace);
int count_bracket(const char *src);
int is_number(char c);
int is_letter(char c);
int is_operator(char c);
int is_operator_not_bracket(char c);
int is_function(char c);
char *put_in_out(const char *number_pointer, char *output, int *i);
char *space_btw(char *src, int *error);
int fspaces(const char *src);
int fsymbol(const char *src);
int give_priority(char c);
void find_unary(char *src);
