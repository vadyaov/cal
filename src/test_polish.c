#include "polish.h"

int main() {
  const char input[] = "2 * sin ( 15 ) / ( 3 + 2 )"; 
  const char *output = NULL;
  printf("input = %s\n", input);
  output = polish(input);
  printf("output = %s\n", output);
  free((char *)output);
  return 0;
}
