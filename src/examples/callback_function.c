#include <stdio.h>
#include <math.h>

float cb_square(int num) {
    return num * num;
}

float cb_cube(int num) {
    return num * num * num;
}

float cb_square_root(int num) {
    return sqrt(num);
}

// function pointer looks like -> float (*op)(int) 
float calc(int num, float (*op)(int)) {
    return op(num);
}

int main(void) {
    printf("square:\t%.2f\n", calc(5, cb_square));
    printf("cube:\t%.2f\n", calc(5, cb_cube));
    printf("sqrt:\t%.2f\n", calc(5, cb_square_root));

    return 0;
}
