#include <stdio.h>

#include "math.h"
#include "utils.h"

int main(void) {
  /*
  78 56 34 12 (Little Endian)
  12 34 56 78 (Big Endian)
  */
  int n = 0x12345678;

  /*
  Exception:
  61 62 63 00 ( Little & Big Endian is same. )
  문자열일땐  byte order 에 상관없이 문자열 순서 그대로 저장된다.
  */
  char *ch = "abc";

  printf("n: 0x%x\n", n);
  printf("ch: %s\n", ch);

  print_byteorder();

  return 0;
}
