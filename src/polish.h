#include <string.h>

#include "stack.h"

char *polish(const char *input);

const char *pretty_input(const char *input);
int is_valid_symb(char c, const char *symbols);
int is_bad_symb(char c, const char *symbols);
char hash(const char *src, int *n, int *replace);
int count_bracket(const char *src);
int is_number(char c);
int is_letter(char c);
int is_operator(char c);
char *put_in_out(const char *number_pointer, char *output, int *i);
const char *space_btw(char *src);
int fspaces(const char *src);
int fsymbol(const char *src);
