#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    return a + b;
}

int multifly(int a, int b) {
    return a * b;
}

int main(int argc, char *argv[]) {
    srand(0);
    unsigned int randn = rand() % 2 + 1;
    printf("randn :%d\n", randn);

    int (* function_ptr)(int, int) = NULL;
    if (randn == 1) {
        printf("here\n");
        function_ptr = add;
    } else {
        printf("there\n");
        function_ptr = multifly;
    }

    printf("function_ptr's address: %p\n", &function_ptr);
    printf("address of add :%p\n", add);
    printf("address of multifly :%p\n", multifly);
    printf("return of funciton_ptr call:%d\n", function_ptr(2,2));

    return 0;
}
