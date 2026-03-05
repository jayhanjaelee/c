#include <stdio.h>

// https://www.youtube.com/watch?v=X4U6MzJkzr4
int main(int argc, char *argv[]) {
    // Hex number representation
    //             R G B A
    int Pixel = 0xFFAABB11;

    unsigned char r = (Pixel >> 24);
    unsigned char g = (Pixel >> 16);
    unsigned char b = (Pixel >> 8);
    unsigned char a = (Pixel);

    printf("r is : %d (%x)\n", r, r);
    printf("g is : %d (%x)\n", g, g);
    printf("b is : %d (%x)\n", b, b);
    printf("a is : %d (%x)\n", a, a);
    return 0;
}
