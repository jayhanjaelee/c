/**
 * @file restrict.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-05 19:31
 */

#include <stdio.h>
#include <stdlib.h>

// restrict -> 컴파일러에게 최적화 하게끔하는 키워드.
// type *restrict 와 같이 사용.
// restrict 로 선언된 변수는 그 포인터가 가르키는 객체는 다른 포인터가 가르키지 않는다.
int my_swap(int *restrict lhs, int *restrict rhs) {
    int temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
    return 0;
}

int main(void) {
    int a = 1;
    int b = 2;

    int *restrict tmp_a = &a;
    int *restrict tmp_b = &a;

    /*
    printf("before:\n");
    printf("a: %d b: %d\n", a, b);

    my_swap(&a, &b);

    printf("after:\n");
    printf("a: %d b: %d\n", a, b);
    */
    return 0;
}
