/**
 * @file test.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-24 22:17
 */

#include <stdio.h>      /* printf 등 표준 입출력 함수 사용을 위한 헤더 */
#include "greatest.h"    /* greatest 단위 테스트 프레임워크 헤더 (헤더 온리 라이브러리) */

/* 테스트 러너의 main 파일에 필요한 전역 변수/함수 정의를 삽입하는 매크로 */
GREATEST_MAIN_DEFS();

/* TEST 매크로: 테스트 함수를 정의. 반환형은 enum greatest_test_res */
TEST x_should_equal_1(void) {
    int x = 1;                                    /* 테스트 대상 변수 x를 1로 초기화 */
    ASSERT_EQ(1, x);                              /* 1과 x가 같은지 비교. 실패 시 "1 != x" 메시지 자동 출력 */
    ASSERT_EQm("Yikes, x doesn't equal 1", 1, x); /* 1과 x 비교. 실패 시 사용자 정의 메시지 출력 */
    ASSERT_EQ_FMT(1, x, "%d");                    /* 1과 x 비교. 실패 시 printf 포맷(%d)으로 기대값/실제값 출력 */
    PASS();                                        /* 모든 단언 통과 시 테스트 성공을 반환 */
}

// 성공
TEST add_should_equal_1(void) {
    ASSERT_EQ(1, 1);
    PASS();
}

TEST add_should_equal_2(void) {
    ASSERT_EQ(1, 2);
    PASS();
}

SUITE(arithmetic_tests) {
    RUN_TEST(add_should_equal_1);
    // RUN_TEST(add_should_equal_2);
}

/* SUITE 매크로: 관련 테스트들을 하나의 스위트(그룹)로 묶음 */
SUITE(the_suite) {
    RUN_TEST(x_should_equal_1);  /* 스위트 내에서 x_should_equal_1 테스트를 실행 */
}

SUITE(foo) {
    printf("here");  /* 테스트 없이 "here"만 출력하는 스위트 (데모/디버깅 용도) */
}


/* 테스트 러너의 진입점 */
int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();      /* 커맨드라인 옵션 파싱 및 테스트 환경 초기화 */

    RUN_SUITE(arithmetic_tests);
    /* RUN_TEST(x_should_equal_1); */  /* 스위트 밖에서 개별 테스트를 직접 실행할 수도 있음 (현재 주석 처리) */

    // RUN_SUITE(the_suite);       /* the_suite 스위트에 포함된 모든 테스트 실행 */
    // RUN_SUITE(foo);             /* foo 스위트 실행 */

    // GREATEST_MAIN_END();        /* 테스트 결과 집계 및 출력, 종료 코드 반환 */
}
