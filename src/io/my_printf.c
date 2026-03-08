/**
 * @file my_printf.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-05 19:51
 */
#include <stdio.h>
#include <stdarg.h>

void my_printf(char *format, ...) {
    printf("%ld\n", sizeof(format));
}

int sum(int max, ...) {
    va_list nums; // 가변 인수 리스트 정의.

    int total = 0;

    va_start(nums, max); // 가변인자 처리를 시작하는 매크로.

    for(int i=0; i<max; i++) {
        int num = va_arg(nums, int); // 가변인자 목록 nums 에서 int 타입의 데이터를 가져온다.
        total += num;
    }

    va_end(nums); // 가변인자 처리를 끝내는 매크로.
    return total;
}

int main(void)
{
    const char *a = "hello";

    char *b = "a";
    a = b;
    //my_printf("hello");
}
