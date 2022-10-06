#include "polish.h"

char *polish(const char *input, int *err) {
  char *new_input = NULL, *input_start = NULL;
  char *output = NULL, *out_start = NULL;
  struct stack *root = NULL;
  if (input) {
    new_input = pretty_input(input, err);
    input_start = new_input;
    if (new_input) {
      int future_spaces = fspaces(new_input),
          future_symbol = fsymbol(new_input);
      output = calloc(future_spaces + future_symbol + 1, sizeof(char));
      out_start = output;
      if (output) {
        char a;
        while ((a = *new_input) != '\0' && !*err) {
          if (is_number(a)) {
            int i = 0;
            output = put_in_out(new_input, output, &i);
            new_input += i - 1;
            *output++ = ' ';
          } else if (is_function(a) || a == '(') {
            push(&root, a);
          } else if (a == ')') {
            while (!*err && peek(root) != '(') {
              if (!root)
                *err = 1;
              else {
                *output++ = pop(&root);
                *output++ = ' ';
              }
            }
            if (!*err) pop(&root);
          } else if (is_operator_not_bracket(a)) {
            print_stack(root);
            if (root) {
              char b = peek(root);
              int pr = give_priority(a);
              while (b && (is_function(b) || (is_operator_not_bracket(b) &&
                                              give_priority(b) >= pr))) {
                *output++ = pop(&root);
                *output++ = ' ';
                b = peek(root);
              }
            }
            push(&root, a);
          }
          new_input++;
        }
        free(input_start);
        while (root && !*err) {
          char b = peek(root);
          print_stack(root);
          if (is_operator_not_bracket(b) || is_function(b)) {
            *output++ = pop(&root);
            *output++ = ' ';
          } else {
            printf("Error!\n");
            *err = 1;
          }
        }
        *(--output) = '\0';
      } else {
        printf("Memory disaster.\n");
      }
    } else {
      printf("INPUT FAIL\n");
    }
  }
  if (*err) {
    destroy(&root);
    *err = 1;
  }
  return out_start;
}

char *pretty_input(const char *input, int *error) {
  size_t symbols_count = 0;
  const char symbols[] = "0123456789().+-/*^modxcsintaqrlg";
  const char *buf = input;
  char *perfect = NULL;
  char *no_del_input = NULL;
  int i = 0, j = 0, bad = 0;
  while (buf[i] != '\0' && !bad) {
    if (is_valid_symb(buf[i], symbols)) symbols_count++;
    if (is_bad_symb(buf[i], symbols)) bad = 1;
    i++;
  }
  if (!bad) {
    no_del_input = calloc(symbols_count + 1, sizeof(char));
    if (no_del_input) {
      for (i = 0; buf[i] != '\0'; i++) {
        if (is_valid_symb(buf[i], symbols)) {
          no_del_input[j] = buf[i];
          j++;
        }
      }
      no_del_input[j] = '\0';
      perfect = space_btw(no_del_input, error);
      free(no_del_input);
    } else {
      printf("Malloc memory error.\n");
    }
  } else {
    printf("Incorrect input\n");
  }
  return perfect;
}

int is_valid_symb(char c, const char *symbols) {
  int status = 0;
  if (strchr(symbols, c)) status = 1;
  return status;
}

int is_bad_symb(char c, const char *symbols) {
  int status = 0;
  if (!strchr(symbols, c) && c != ' ') status = 1;
  return status;
}

char hash(const char *src, int *n, int *replace) {
  char symb[] = "msctSCTqlg", out = 0;
  *replace = 0;
  char *functions[] = {"mod",  "sin",  "cos",  "tan", "acos",
                       "asin", "atan", "sqrt", "ln",  "log"};
  int i = 0, l = 0;
  for (; i < 10 && !out; i++) {
    l = strlen(functions[i]);
    if (!strncmp(src, functions[i], l)) {
      out = symb[i];
      *replace = l - 1;
    }
  }
  if (out) *n += l;
  return out;
}

int count_bracket(const char *src) {
  int n = 0;
  while (*src != '\0') {
    if (*src == '(' || *src == ')') n++;
    src++;
  }
  return n;
}

int is_number(char c) { return (c >= '0' && c <= '9'); }

int is_letter(char c) { return (c >= 'a' && c <= 'z'); }

int is_operator(char c) { return (strchr("()+-/*^", c) ? 1 : 0); }

int is_operator_not_bracket(char c) { return (strchr("m+-/*^", c) ? 1 : 0); };

int is_function(char c) { return (strchr("scrSCTqlg", c) ? 1 : 0); }

char *put_in_out(const char *number_pointer, char *output, int *i) {
  int pointflag = 0;
  while ((is_number(*number_pointer) || *number_pointer == '.') &&
         pointflag < 2 && *number_pointer != '\0') {
    *output = *number_pointer;
    if (*number_pointer == '.') pointflag++;
    number_pointer++;
    output++;
    *i += 1;
  }
  if (pointflag > 1) output = NULL;
  return output;
}

char *space_btw(char *src, int *error) {
  int length = strlen(src);
  char *out = NULL;
  char *buf = NULL;
  int probel = 0, replace = 0;
  for (int i = 0; src[i] != '\0' && !*error;) {
    int pointflag = 0;
    if (is_number(src[i])) {
      while ((is_number(src[i]) || src[i] == '.') && pointflag < 2 &&
             src[i] != '\0') {
        if (src[i] == '.') pointflag++;
        i++;
      }
      probel++;
    }
    if (is_letter(src[i])) {
      if (hash(src + i, &i, &replace) != '\0') {
        probel++;
        length -= replace;
      } else {
        *error = 1;
      }
    }
    if (is_operator(src[i]) && src[i] != '\0') {
      probel++;
    }
    if (src[i] != '\0') i++;
  }
  if (!*error) {
    out = calloc(length + probel, sizeof(char));
    buf = out;
    if (out) {
      int i = 0, j = 0;
      for (; src[i] != '\0';) {
        if (is_number(src[i])) {
          out = put_in_out(src + i, out, &i);
          if (src[i]) *out++ = ' ';
        } else if (is_operator(src[i]) && src[i] != '\0') {
          *out++ = src[i];
          *out++ = ' ';
          i++;
        } else if (is_letter(src[i])) {
          if (hash(src + i, &j, &replace)) {
            *out++ = hash(src + i, &i, &replace);
            *out++ = ' ';
          }
        }
        printf("%c\n", src[i]);
      }
      *(out - 1) = '\0';
    } else {
      printf("Malloc memory fail\n");
    }
  }
  return buf;
}

int fspaces(const char *src) {
  int spaces = 0;
  for (int i = 0; src[i] != '\0'; i++) {
    if (src[i] == ' ') spaces++;
    if ((src[i] == '(' || src[i] == ')') && src[i + 1] != '\0') i++;
    if ((src[i] == ')' || src[i] == '(') && src[i + 1] == '\0') spaces--;
  }
  return spaces;
}

int fsymbol(const char *src) {
  int symbols = 0;
  const char s[] = "sctSCTqlg+-/*^0123456789";
  for (int i = 0; src[i] != '\0'; i++) {
    if (strchr(s, src[i]) != NULL) symbols++;
  }
  return symbols;
}

int give_priority(char c) {
  int p = 0;
  if (c == '*' || c == '/' || c == 'm')
    p = 1;
  else if (c == '^')
    p = 2;
  return p;
}
