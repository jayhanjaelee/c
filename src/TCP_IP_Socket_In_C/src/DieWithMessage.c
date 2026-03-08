/**
 * @file DieWithMessage.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-08 14:46
 */

#include <stdio.h>
#include <stdlib.h>

void DieWithUserMessage(const char *msg, const char *detail) {
    fputs(msg, stderr);
    fputs(": ", stderr);
    fputs(detail, stderr);
    fputc('\n', stderr);
    exit(1);
}

void DieWithSystemMessage(const char *msg) {
    perror(msg);
    exit(1);
}

