#include <stdio.h>

typedef struct StagesCompleted {
    char level1Completed:1;
    char level2Completed:1;
    char level3Completed:1;
    char level4Completed:1;
    char level5Completed:1;
    char level6Completed:1;
    char level7Completed:1;
    char level8Completed:1;
} StagesCompleted_t;

int main(int argc, char *argv[]) {
    printf("sizeof(StagesCompleted_t)=%ld\n",
           sizeof(StagesCompleted_t));
    return 0;
}
