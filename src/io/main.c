/**
 * @file main.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-05 00:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// How to handle standard input and output in c.

int main(int argc, char *argv[]) {
    // 1.scanf
    // int a, b;
    // printf("a:");
    // scanf("%d", &a);
    // printf("b:");
    // scanf("%d", &b);

    // int c;
    // printf("c:");
    // fscanf(stdin, "%d", &c);

    // printf("a: %d b: %d\n", a, b);
    // printf("c: %d\n", c);

    // 2.getc
    // printf("getting character:");
    // int ch = getc(stdin);
    // printf("ch: %c\n", ch);

    // 3. getline()
    // char *line = NULL;   // Pointer to the buffer, initialized to NULL
    // size_t len = 0;      // Size of the buffer, initialized to 0
    // ssize_t read;        // Number of characters read

    // printf("Enter a line: ");

    // // Use getline to read a line from standard input (stdin)
    // read = getline(&line, &len, stdin);

    // if (read != -1) {
    //     printf("You entered: %s", line);
    //     printf("Characters read: %zd\\n", read); // Use %zd for ssize_t
    // } else {
    //     printf("Error reading input or EOF encountered.\\n");
    // }

    // Free the allocated memory
    // free(line);
    // 4. fgets - read a line with whitespace.
    // char ch_buffer[100] = NULL;
    // fgets(ch_buffer, sizeof(ch_buffer), stdin);
    char *line = (char *)malloc(sizeof(char)*6);

    printf("Enter a sentence: ");
    // fgets(buffer_name, size, stream);
    fgets(line, sizeof(char)*6, stdin);

    printf("line size: %zd\n", sizeof(char)*6);

    printf("You entered: %s\n", line);

    // fgets() keeps the newline character '\n' at the end of the input.
    // You can remove it if needed.
    line[strcspn(line, "\n")] = '\0';
    printf("Without newline: %s\n", line);

    free(line);
    // printf("origin: %p, newer: %p\n", ch_buffer, return_ptr);

    return 0;
}

