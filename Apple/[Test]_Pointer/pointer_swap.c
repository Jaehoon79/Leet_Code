#include <stdio.h>

void swap (int *a, int *b) {
    printf("pre: %d, %d\n", *a, *b);
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    printf("post: %d, %d\n", *a, *b);
}

int main (void) {
    int input[] = {-1, -1};

    swap(&input[0], &input[1]);

    printf("index_0: %d, index_1: %d \n", input[0], input[1]);

    return 0;
}