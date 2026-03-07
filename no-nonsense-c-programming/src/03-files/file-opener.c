#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3)
    {
        printf("Usage: %s <in-file> <out-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // FILE *file = fopen("/Users/jay/Desktop/c/no-nonsense-c-programming/src/03-files/input.txt", "r");
    FILE *in_file = fopen(argv[1], "r");
    FILE *out_file = fopen(argv[2], "w");

    int c;
    while ( (c = getc(in_file)) != EOF )
    {
        putc(c, out_file);
    }

    fclose(in_file);
    fclose(out_file);

    printf("%s was wrote!\n", argv[2]);
    return 0;
}
