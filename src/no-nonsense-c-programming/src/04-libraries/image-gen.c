#include <stdio.h> // inside /usr/local
#include <stdint.h>
#include <stdbool.h>
#include "TinyPngOut.h" // inside current directory

#define WIDTH 400
#define HEIGHT 400

struct Person {
    char *name;
    int age;
    int birthMonth;
};

/**
 * struct field vim 으로 출력 손쉽게하는법.
 * 1.struct fields visual mode 로 전부 복사.
 * 2.출력할 구문에 복사.
 * 3.visual selection
 * 4.:s/\v(\w+\s)(*?\w+)/printf("\2: %d\n", struct.\2);
 * */
void printPerson(struct Person *p) {
    printf("newer : %p\n", p);
    printf("*name: %s\n", p->name);
    printf("age: %d\n", p->age);
    printf("birthMonth: %d\n", p->birthMonth);
}

int main() {
    printf("Generating image...\n");

    // do some image generation here
    struct TinyPngOut pngWriter;
    FILE *out_file = fopen("out.png", "w");
    TinyPngOut_init(&pngWriter, WIDTH, HEIGHT, out_file);

    uint8_t mint_pixel[] = {48,176,120};
    uint8_t red_pixel[] = {255,0,0};
    bool in = false;
    for (int y=0; y<HEIGHT; y++) {
        /* 
         * 10 번째 줄 마다 토글.
         * */
        if (y % 10 == 0) {
            in = !in;
        }
        for (int x=0; x<HEIGHT; x++) {
            if (in) {
                // 첫줄에 mint color 로 draw.
                TinyPngOut_write(&pngWriter, mint_pixel, 1);
            }
            else {
                // 토글되면 red color 로 draw.
                TinyPngOut_write(&pngWriter, red_pixel, 1);
            }
        }
    }

    fclose(out_file);

    printf("Done.\n");
    return 0;
}
