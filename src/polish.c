#include "polish.h"

char *polish(const char *input) {
  const char *new_input = NULL;
  char *output = NULL;
  char *out_start = NULL;
  if (input) {
    new_input = pretty_input(input);
    int future_spaces = fspaces(new_input),
        furure_symbol = fsymbol(new_input);
    printf("perfectline:%s\n", new_input);
    if (new_input) {
      int brackets = count_bracket(new_input);
      output = malloc(future_spaces + future_symbol - brackets + 1);
      out_start = output;
      if (output) {
        
        struct stack *root = NULL;
        int i = 0, j = 0;
        for (; new_input[i] != '\0'; i++) {

        }
      } else {
        printf("Memory disaster.\n");
      }
    }
  }
  return out_start;
}

const char *pretty_input(const char *input) {
  size_t symbols_count = 0;
  const char symbols[] = "0123456789().+-/*^modxcsintaqrlg";
  const char *buf = input;
  const char *perfect = NULL;
  char *no_del_input = NULL;
  int i = 0, j = 0, bad = 0;
  while (buf[i] != '\0' && !bad) {
    if (is_valid_symb(buf[i], symbols)) symbols_count++; 
    if (is_bad_symb(buf[i], symbols)) bad = 1;
    i++;
  }
  if (!bad) {
    no_del_input = malloc(symbols_count + 1);
    for (i = 0; buf[i] != '\0'; i++) {
      if (is_valid_symb(buf[i], symbols)) {
        no_del_input[j] = buf[i];
        j++;
      }
    }
    no_del_input[j] = '\0';
    perfect = space_btw(no_del_input);
    printf("perfect:%s\n", perfect);
    free(no_del_input);
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
  char symb[] = "sctSCTqlg", out = 0;
  *replace = 0;
  char *functions[] = {"sin", "cos", "tan", "acos", "asin",
                       "atan", "sqrt", "ln", "log"};
  int i = 0, l = 0;
  for (; i < 9 && !out; i++) {
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

int is_number(char c) {return (c >= '0' && c <= '9');}

int is_letter(char c) {return (c >= 'a' && c <= 'z');}

int is_operator(char c) {return (strchr("()+-/*^", c) ? 1 : 0);}

char *put_in_out(const char *number_pointer, char *output, int *i) {
  int pointflag = 0;
  while ((is_number(*number_pointer) || *number_pointer == '.')
          && pointflag < 2 && *number_pointer != '\0') {
    *output = *number_pointer;
    if (*number_pointer == '.') pointflag++;
    number_pointer++;
    output++;
    *i += 1;
  }
  if (pointflag > 1) output = NULL;
  return output;
}

const char *space_btw(char *src) {
  //printf("S:%s\n%zu\n", src, strlen(src));
  int length= strlen(src);
  char *out = NULL;
  char *buf = NULL;
  int probel = 0, replace = 0;
  for (int i = 0; src[i] != '\0'; i++) {
    int pointflag = 0;
    if (is_number(src[i])) {
      while ((is_number(src[i]) || src[i] == '.')
              && pointflag < 2 && src[i] != '\0') {
        if (src[i] == '.') pointflag++;
        i++;
      }
      probel++;
    }
    if (hash(src + i, &i, &replace) != '\0') {
      probel++;
     length -= replace;
    }
    if (is_operator(src[i]) && src[i] != '\0') {
      probel++;
    }
  }
  //printf("probel + length = %d\n", probel + length);
  out = malloc(length + probel);
  buf = out;
  int i = 0, j = 0;
  for (; src[i] != '\0';) {
    if (is_number(src[i])) {
      out = put_in_out(src + i, out, &i);
      *out++ = ' ';
    }
    if (is_operator(src[i]) && src[i] != '\0') {
      *out++ = src[i];
      *out++ = ' ';
      i++;
    }
    if (hash(src + i, &j, &replace)) {
      *out++ = hash(src + i, &i, &replace);
      *out++ = ' ';
    }
  }
  *(--out) = '\0';
  return buf;
}

int fspaces(const char *src) {
  int spaces = 0;
  for (int i = 0; src[i] != '\0'; i++) {
    if (src[i] == ' ') spaces++;
    if ((src[i] == '(' || src[i] == ')') && src[i + 1] != '\0') i++;
    if ((src[i] == ')' || src[i] == '(') && src[i + 1] == '\0') spaces--;
  }
  printf("spaces = %d\n", spaces);
  return spaces;
}

int fsymbol(const char *src) {
  int symbols = 0;
  const char s[] = "sctSCTqlg+-/*^0123456789";
  for (int i = 0; src[i] != '\0'; i++) {
    if (strchr(s, src[i]) != NULL) symbols++;
  }
  printf("symb = %d\n", symbols);
}
