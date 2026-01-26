#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *num = (int *)malloc(sizeof(int));

    int year = 2026;
    num = &year;

    printf("num:\t%d\n", *num);

    // free(num);

    return 0;
}
