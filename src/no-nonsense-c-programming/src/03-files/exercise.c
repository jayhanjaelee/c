#include <stdio.h>

void read_and_print_bytes() {
    /*
     * 1 character 씩 읽기
     * 1. 파일 읽기.
     * 2. 파일 바이트 수 저장.
     * 3. 저장된 바이트 수 출력.
     * */

    int total_filesize = 0;
    FILE *file = fopen("./src/03-files/input.txt", "r");
    char c;
    while ( (c = getc(file)) != EOF) {
        // 1.
        // unsigned int size = sizeof(c);
        // total_filesize += size;

        // 2.
        // char 는 1바이트 이기 때문에 1씩 추가.
        total_filesize += 1;
    }

    printf("total filesize: %d\n", total_filesize);
}

void read_line_and_print_bytes() {
    /* 
     * 2. 한줄씩 일기
     * 1. 파일 사이즈 출력.
     * */
    FILE *file = fopen("./src/03-files/input.txt", "r");
    char *line = NULL;
    size_t linecap = 0;
    ssize_t linelen;

    size_t total_fielsize = 0;
    // getline 은 오류 발생시 -1 리턴한다.
    // 정상 실행시 바이트수를 리턴.
    while ((linelen = getline(&line, &linecap, file)) > 0) {
        total_fielsize += linelen;
    }

    printf("total fielsize: %zu\n", total_fielsize);
}

int main(void) {
    read_and_print_bytes();
    // read_line_and_print_bytes();

    return 0;
}
