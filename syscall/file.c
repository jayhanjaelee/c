/**
 * @file file.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-07 12:16
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#define PERM 0666
#define BUFSIZ 1024

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

    int fd;
    char *filename = "a.txt";
    fd = open(filename, O_RDWR, PERM);
    if (fd == -1) {
        if (creat(filename, PERM) == -1) {
            error("can't create file %s\n", filename);
            return 1;
        }

        printf("file %s was created\n", filename);
    }

    char buf[BUFSIZ];
    int n;

    printf("what is current fd:%d\n", fd);
    char path[256];
    fcntl(fd, F_GETPATH, path);  // macOS specific
    printf("File path: %s\n", path);

    lseek(fd, 0L, 0);
    /*
       세번째 파라미터 0,1,2
       0 -> 파일의 시작 위치
       1 -> 파일 현재 커서가 있는 위치
       2 -> 파일의 끝 위치
       */

    while (( n = read(0, buf, BUFSIZ) ) > 0) {
        write(fd, buf, n);
    }

    return 0;
}

