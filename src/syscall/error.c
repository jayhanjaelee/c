/**
 * @file error.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-07 12:07
 */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/*
printf 는 argument 로 인자를 하나씩 받지만
vfprintf 는 argument 로 va_list 를 받는데에 차이가 있음.
*/
void error(char *fmt, ...) {
    va_list args;

    va_start(args, fmt); // first argument must be a pointer for va_list, second must last argument of the function.
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}

int main(void) {
    error("%s %s", "testing", "error");
    return 0;
}

