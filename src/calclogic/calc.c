#include "calc.h"

double calc(char *polishString, info *info) {
  char *buf = polishString;
  //printf("polishString=%s\n", buf);
  struct stack_n *root = NULL;
  double res = 0.0;
  int i = 0, error = 0;
  char s = 0;
  while ((s = buf[i]) != '\0' && !error) {
    if (is_number(s) || s == 'x') {
      if (is_number(s)) push_n(&root, convert_to_double(buf + i, &i)); 
      else {
        push_n(&root, info->x);
        i++;
      }
    } else {
      if (is_operator_not_bracket(s))
        error = makeOperator(&root, s); 
      else if (is_function(s))
        error = makeFunction(&root, s);      
      i++;
    }
  }
  if (0 == error) {
    res = pop_n(&root);
    //printf("res = %lf\n", res);
  } else {
    printf("Calculation error!\n");
  }
  return res;
}

double convert_to_double(char *src, int *i) {
  double doubleNum = 0.0,
         integerPart = 0.0, fractionalPart = 0.0;
  char *buf = src, *end = NULL, *unknown = NULL; 
  int j = 0;
  while (*buf != '\0' && is_number(*buf)) buf++;
  unknown = buf--;
  while (buf >= src)
    integerPart += (double)(*buf-- - '0') * pow(10.0, j++);
  end = unknown;
  if (*unknown == '.') {
    int k = 0;
    buf = ++unknown;
    while (*unknown != '\0' && is_number(*unknown)) unknown++;   
    end = unknown--;
    while (unknown >= buf)
      fractionalPart += (double)(*unknown-- - '0') * pow(10.0, k++);
    fractionalPart /= pow(10.0, k);
  }
  doubleNum = integerPart + fractionalPart;
  //printf("doubleNumber = %lf\n", doubleNum);
  *i += end - src;
  return doubleNum;
}

int makeOperator(struct stack_n **root, char s) {
  double firstNum = 0.0, secondNum = 0.0;
  int error = 0; 
  if (s == '|' || s == '~')  {
   if (NULL != *root) {
     secondNum = pop_n(root);
     if (s == '~') secondNum = -secondNum;
     push_n(root, secondNum);
   } else {
     error = 1;
   }
  } else {
    double res = 0.0;
    if (NULL != *root) {
      secondNum = pop_n(root);
      if (NULL != *root) {
        firstNum = pop_n(root);
      } else {
        error = 1;
      }
    } else {
      error = 1;
    }
    if (0 == error) {
      if (s == 'm') {
        res = fmod(firstNum, secondNum); 
      } else if (s == '+') {
        res = firstNum + secondNum;
      } else if (s == '-') {
        res = firstNum - secondNum;
      } else if (s == '/') {
        res = firstNum / secondNum;
      } else if (s == '*') {
        res = firstNum * secondNum;
      } else if (s == '^') {
        res = pow(firstNum, secondNum);
      }
      push_n(root, res);
    }
  }
  return error;
}

int makeFunction(struct stack_n **root, char s) {
  double number = 0.0;
  int error = 0;
  if (NULL != *root) {
    number = pop_n(root);
  } else {
    error = 1;
  }
  if (0 == error) {
    double result = 0.0;
    if (s == 's') {
      result = sin(number); 
    } else if (s == 'c') {
      result = cos(number);
    } else if (s == 't') {
      result = tan(number);
    } else if (s == 'S') {
      result = asin(number);
    } else if (s == 'C') {
      result = acos(number);
    } else if (s == 'T') {
      result = atan(number);
    } else if (s == 'q') {
      result = sqrt(number);
    } else if (s == 'l') {
      result = log(number);
    } else if (s == 'g') {
      result = log10(number);
    }
    push_n(root, result);
  }
  return error;
}

