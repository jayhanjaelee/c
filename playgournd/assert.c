/**
 * @file assert.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-25 20:40
 */

// #define NDEBUG

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/*
# C언어 `assert` 사용 장점 3가지

코드 7줄에 assert 1글자 정도 적당. (From Pope Kim)

clang -DNDEBUG 혹은 #define NDEBUG 로 assert 비활성화 가능.

1. **디버깅 효율화** — 조건이 거짓일 때 파일명, 라인 번호, 실패한 표현식을 자동 출력하므로 버그 위치를 즉시 파악할 수 있다.

2. **릴리스 시 오버헤드 제거** — `#define NDEBUG`만 선언하면 모든 assert가 컴파일 시 제거되어, 배포 빌드에서 성능 비용이 0이다.

3. **전제 조건 명시화** — 함수 진입부에 `assert(ptr != NULL)` 같은 선언을 두면, 코드 자체가 "이 조건은 반드시 참이어야 한다"는 문서 역할을 한다.
*/

void print_string(char *string);

int main(int argc, char *argv[]) {
    char *string = (char *)malloc(sizeof(char *)*4);
    strcpy(string, "abc");
    string = NULL;
    // free(string);
    print_string(string);
    return 0;
}

void print_string(char *s) {
    assert(s != NULL);
    printf("@@@%s@@@\n", s);
    return;
}
