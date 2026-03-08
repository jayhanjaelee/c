/**
 * @file main.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-01-30 00:38
 */

#include <stdio.h>

typedef void(*callback_func_t)(void);

void hello(void(*callbackfun)(void)) {
    printf("do something!\n");
    callbackfun();
}

void hi(callback_func_t callback) {
    printf("do something!\n");
    callback();
}

void foo() {
    printf("foo\n");
}

void bar() {
    printf("bar!\n");
}

int main(void) {
    hello(foo);
    hi(bar);
    return 0;
}

