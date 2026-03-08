/* This is a multi-line comment 
 * Across multiple lines
 *
 * standard input 으로 영문자 알파벳의 빈도수를 계산,
 * 출력하는 프로그램.
 */
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define COUNT 256

void printAllCharacterCounts(int *character_counts) 
{
    int frequency;
    // loop index를 char i 로 선언해도 무방함.
    for (int i=32; i<126; i++)
    {
        frequency = character_counts[i];
        if (frequency != 0) {
            printf("%c -> %d\n", i, character_counts[i]);
        }
    }
}

// A simple character frequency analyzer
int main() {
    /* 
     * 메모리는 이전 다른 프로그램에서 사용했을 가능성이 있어서
     * 초기화 하지않으면 garbage 값이 들어가 있을 수 있음.
     */

    /* 
     * 모든 array elements 0 으로 초기화 하는 방법 세가지.
     * 1.
     * int count[COUNT] = {0};
     * for (int i=0; i<COUNT; i++) {
     *     count[i] = 0;
     * }
     *
     * 2.
     * int count[COUNT];
     * memset(count, 0, COUNT);
     *
     * 3.
     * int count[COUNT] = {0};
     * */

    /* how to get elment size.
     * sizeof(int), sizeof(arr[0])
     * */
    int character_counts[COUNT];
    memset(character_counts, 0, COUNT*sizeof(int));

    int c;
    while ( (c = getc(stdin)) != EOF ) {
        // do something with the character
        character_counts[c] += 1;
    }

    printAllCharacterCounts(character_counts);
}
