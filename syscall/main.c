/**
 * @file main.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-07 11:52
 */

#include <stdio.h>
#include <unistd.h>

int main(void) {
    /*
    char buf[1024];
    int n;

    while ((n = read(0, buf, 1024)) > 0) {
        write(1, buf, n);
    }
    */
    printf("%d", BUFSIZ);
    return 0;
}

