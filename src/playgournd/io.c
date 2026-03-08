/**
 * @file io.c
 * @brief 표준 입력을 한 줄씩 읽어 그대로 출력하는 프로그램
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-01-25
 */

#include <stdio.h>  // stdio: standard input/output

#include <string.h>

int get_a_line_from_stdin() {
    char *filename = "out.txt";

    // read line.
    char buf[1024];
    FILE *fp;
    fp = fopen(filename, "a");
    while (fgets(buf, sizeof buf, stdin)) {
        fwrite(buf, sizeof(char), strlen(buf), fp);
        fflush(fp);  // ← 버퍼를 즉시 디스크에 플러시
    }
    fclose(fp);

    return 0;
}

void get_a_char() {
    char line[256];  // char: character, 한 줄 저장 버퍼

    while (fgets(line, sizeof(line), stdin) != NULL) {
        fputs(line, stdout);

    }
}

int main(void) {
    return 0;
}
