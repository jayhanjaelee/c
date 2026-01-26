#include <stdio.h>

int main(int argc, char *argv[]) {
  /*
  n byte representation is like 0b00000000_00000000_00000001_00000000
  */
  int n = 256;
  void *np = &n;

  for (int i = 0; i < sizeof(int); i++) {
    printf("%d\n", *(unsigned char *)np);
    np++;
  }

  return 0;
}
