#ifndef _SRC_CALCLOGIC_POLISH_H
#define _SRC_CALCLOGIC_POLISH_H

#include <stdlib.h>
#include <string.h>

char *polish(const char *, int *);

char *pretty_input(const char *, int *);
int is_valid_symb(char, const char *);
int is_bad_symb(char, const char *);
char hash(const char *, int *, int *);
int count_bracket(const char *);
int is_number(char);
int is_letter(char);
int is_operator(char);
int is_operator_not_bracket(char);
int is_function(char);
char *put_in_out(const char *, char *, int *, int *);
char *space_btw(char *, int *);
int fspaces(const char *);
int fsymbol(const char *);
int give_priority(char);
void find_unary(char *);

#endif /* _SRC_CALCLOGIC_POLISH_H */
