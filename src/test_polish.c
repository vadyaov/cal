#include "polish.h"
#include "calc.h"

int main() {
  const char input[] = "-223.123 + (16.1/4.0)/( 1.0023/2.05)";
  char *output = NULL;
  int err = 0;
  printf("input = %s\n", input);
  output = polish(input, &err);
  if (!err) printf("output = %s\n", output);
  calc(output);
  if (output) free((char *)output);
  return 0;
}
