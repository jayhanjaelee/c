/**
 * @file printf.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-05 21:13
 */

#include <stdio.h>

int main()
{
    const char *str = "A whole line of text.\n";
    fputs(str, stdout);

    return 0;
}

