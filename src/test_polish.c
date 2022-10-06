#include "polish.h"

int main() {
  const char input[] = "5 / sin(1/2) * cos(1/3) + tan(30) + 1mod2";
  const char *output = NULL;
  int err = 0;
  printf("input = %s\n", input);
  output = polish(input, &err);
  if (!err) printf("output = %s\n", output);
  if (output) free((char *)output);
  return 0;
}
