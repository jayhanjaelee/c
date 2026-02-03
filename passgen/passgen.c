/**
 * @file passgen.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-03 23:17
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *random_stream = "/dev/random";

void generate_password(char *memory, int length)
{
    FILE *file = fopen(random_stream, "r");
    int c = fgetc(file);
    if (c == EOF)
    {
        printf("%s could not be read\n", random_stream);
        exit(-1);
    }

    int r;
    for(int i=0; i<length; i++)
    {
        r = fgetc(file);
        /*
         1. 126 - 33 = 93 → 출력 가능한 ASCII 문자의 개수
         2. r % 93 → r을 93으로 나눈 나머지 (0~92의 값)
         3. + 33 → ASCII 33('!')을 기준점으로 해서 범위를 33~125로 이동
         */
        r = (r % (126 - 33)) + 33;
        *(memory+i) = r;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2)
    {
        printf("Usage: passgen <num-of-chars>");
        return 0;
    }
    int length = atoi(argv[1]);
    // printf ("Generating password of %d bytes\n", length);

    char *password = (char *)malloc(length);
    for(int i=0; i<20; i++) {
        generate_password(password, length);
        printf("Generated password: %s\n", password);
    }
    free(password);
    return 0;
}

