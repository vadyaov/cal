#include "polish.h"
#include "calc.h"

int main() {
  const char input[] = "(1/2)*sin(30)";
  char *output = NULL;
  int err = 0;
  printf("input = %s\n", input);
  output = polish(input, &err);
  if (!err) printf("output = %s\n", output);
  calc(output);
  if (output) free((char *)output);
  printf("[%lf]", 0.5 * sin(30));
  return 0;
}
