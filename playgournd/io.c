/**
 * @file io.c
 * @brief 표준 입력을 한 줄씩 읽어 그대로 출력하는 프로그램
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-01-25
 */

#include <stdio.h>  // stdio: standard input/output

int main(void) {
    char line[256];  // char: character, 한 줄 저장 버퍼

    while (fgets(line, sizeof(line), stdin) != NULL) {
        fputs(line, stdout);
    }

    return 0;
}
