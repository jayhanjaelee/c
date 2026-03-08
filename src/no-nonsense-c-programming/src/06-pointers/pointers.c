#include <stdio.h>

int square(int *number)
{
    printf("a inside square: %p\n", number);
    *number = *number * *number;
    printf("Inside the function: Number = %d\n", *number);
    return *number;
}

int square_working(int *number) {
    printf("[DBG] number: %p\n", number);
    *number = (*number) * (*number);
    printf("Inside the working funciton: Number = %d\n", *number);
    return 0;
}

int main()
{
    int number = 6;
    int *memory_address = &number;
    printf("[DBG] memory_address: %p\n", memory_address);
    square_working(memory_address);
    return 0;
}
