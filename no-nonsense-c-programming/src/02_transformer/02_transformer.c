#include <stddef.h>
#include <stdio.h>
#include <strings.h>

int encryption_key = 42;

/**
 * my_to_upper
 *
 * @param char c 
 * @return int
 */
int my_to_upper(char c) {
    if (c == '\n') return 0;
    return c - 32;
}

int main(int argc, char *argv[]) {
    char c = '\0';

    if (argc == 1) {
        printf("Usage: 02_transformer [--default] [--uppercase] [-U]\n");
        return 0;
    }

    // simple encryption using XOR.
    if ((strcmp(argv[1],"--default") == 0)) {
        while ((c = getc(stdin)) != EOF) {
            putc(c ^ encryption_key, stdout);
        }
    }

    // set stdinput string to uppercase.
    if (strcmp(argv[1],"--uppercase") == 0 || 
        strcmp(argv[1],"-U") == 0) {

        char input[BUFSIZ];
        fgets(input, sizeof(input), stdin);
        printf("older: %s", input);
        printf("newer: ");
        for (size_t i=0; i<strlen(input); i++) {
            putc(my_to_upper(input[i]), stdout);
        }
        printf("\n");
    }

    return 0;
}
