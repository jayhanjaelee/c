#include <stdio.h>

void print_byteorder() {
  unsigned int x = 1;
  char *c = (char*)&x;

  if (*c) {
    printf("Little Endian\n");
  } else {
    printf("Big Endian\n");
  }
}
