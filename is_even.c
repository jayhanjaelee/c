#include <stdio.h>

#define TRUE 1;
#define FALSE 0;

typedef int bool;

bool isEvenXor(int n) {
  if ((n ^ 1) == (n + 1)) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

bool isEvenAnd(int n) {
  return (!(n & 1));
}

bool isEvenOr(int n) {
  if ((n | 1) > n) {
    return TRUE;
  } else {
    return FALSE;
  }
}

bool isEven(int n) {
  return n % 2 == 0;
}

int main(void) {
  // printf("isEvenXor : %d\n", isEvenXor(1));
  // printf("isEvenAnd: %d\n", isEvenAnd(2));
  // printf("isEvenOr: %d\n", isEvenOr(1));
  printf("isEven: %d\n", isEven(2));

  return 0;
}
