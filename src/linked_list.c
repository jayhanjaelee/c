/**
 * @file linked_list.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-01-21 22:01
 */

#include <stdio.h>
#include <stdlib.h>

// 1. 노드 구조체 정의
struct Node {
    int data;           // 데이터를 저장할 변수
    struct Node *next;  // 다음 노드의 주소를 가리키는 포인터
};

int main() {
    struct Node *head = NULL;
    struct Node *curr = NULL;
    struct Node *prev = NULL;

    // 2. 반복문을 사용하여 노드 5개 생성
    for (int i = 1; i <= 5; i++) {
        // 메모리 동적 할당
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = i * 10; // 10, 20, 30, 40, 50 저장
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode; // 첫 번째 노드라면 head로 지정
        } else {
            prev->next = newNode; // 이전 노드와 현재 노드를 연결
        }
        prev = newNode; // 현재 노드를 이전 노드 포인터에 저장
    }

    // 3. 반복문을 사용하여 링크드리스트 출력
    printf("링크드리스트 출력: ");
    curr = head; // 시작점(head)부터 탐색 시작
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next; // 다음 노드로 이동
    }
    printf("NULL\n");

    // 4. 메모리 해제 (중요!)
    curr = head;
    while (curr != NULL) {
        struct Node *temp = curr;
        curr = curr->next;
        free(temp);
    }

    return 0;
}
