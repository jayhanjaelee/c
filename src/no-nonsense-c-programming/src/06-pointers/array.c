#include <stdio.h>
#include <string.h>

#define WIDTH 8

void modify_array(int array[]) {
    array[0] = 7;
    array[1] = 7;
    array[2] = 7;
}

void print_array(int array[]) {
    char *columns[] = {
        "value",
        "array to pointer",
        "adddress of array",
    };
    printf(
        "| %*s%s | %*s%s | %*s%s |\n",
        WIDTH-2, "",
        columns[0],
        WIDTH-5, "",
        columns[1],
        WIDTH-4, "",
        columns[2]
    );
    printf(
        "| %*sarray[0] = %d| %*sarray+0: %p| %*s&array[0]: %p|\n",
        0, "", *(array+0),
        0, "", array+0,
        0, "", &array[0]
    );
    printf(
        "| %*sarray[0] = %d| %*sarray+0: %p| %*s&array[0]: %p|\n",
        0, "", *(array+1),
        0, "", array+1,
        0, "", &array[1]
    );
    printf(
        "| %*sarray[0] = %d| %*sarray+0: %p| %*s&array[0]: %p|\n",
        0, "", *(array+2),
        0, "", array+2,
        0, "", &array[2]
    );
}

int main() {
    printf("Creating array...\n");
    int array[3] = {0,4,9};
    print_array(array);

    printf("\n");
    printf("Modifying array...\n");
    modify_array(array);
    print_array(array);
}
