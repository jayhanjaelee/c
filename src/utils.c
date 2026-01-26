#include <stdio.h>

void print_byteorder() {
  unsigned int value = 1; // 0x00000001
  unsigned char *byte_ptr = (unsigned char *)&value;

  if (*byte_ptr) {
    printf("Little Endian\n");
  } else {
    printf("Big Endian\n");
  }
}
