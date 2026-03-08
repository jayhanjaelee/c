/**
 * @file main.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-06 21:53
 */

#include <stdio.h>
#include "mymath.h" // Include your custom library's header

int main() {
    int sum = add(5, 3);
    int difference = subtract(5, 3);

    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", difference);

    return 0;
}
