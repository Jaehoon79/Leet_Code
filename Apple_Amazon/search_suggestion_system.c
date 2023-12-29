#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc (const void *a, const void *b) {
    return strcmp(*(const char**)a, *(const char **)b);
}

#define LIMIT_PROD  (3)

char*** suggestedProducts(char** products, int productsSize, char* searchWord, int* returnSize, int** returnColumnSizes) {
    char ***sugString = (char ***)malloc(sizeof(char **) * strlen(searchWord));
    int index = 0, ind_prod;

    (*returnColumnSizes) = (int *)malloc(sizeof(int) * productsSize * 3);
    (*returnSize) = 0;

    /* sorting input lexicographically */
    qsort(products, productsSize, sizeof(char *), cmpfunc);
    printf("\n");
    for (index = 0; index < strlen(searchWord); index++) {
        sugString[index] = (char **)malloc(LIMIT_PROD  * sizeof(char *));

        for (ind_prod = 0; ind_prod < productsSize; ind_prod++) {
            if(!strncmp(searchWord, products[ind_prod], index + 1)) {
                sugString[index][(*returnColumnSizes)[(*returnSize)]] = (char *)malloc(strlen(products[index]) * sizeof(char));
                strcpy(sugString[index][(*returnColumnSizes)[(*returnSize)]], products[ind_prod]);
                printf("aa: %d, count: %d ", index, (*returnColumnSizes)[(*returnSize)]);
                printf("%s \n", sugString[index][(*returnColumnSizes)[(*returnSize)]]);
                (*returnColumnSizes)[(*returnSize)] += 1;
                if ((*returnColumnSizes)[(*returnSize)] == LIMIT_PROD) break;
            }
        }
        (*returnSize)++;
        (*returnColumnSizes)[(*returnSize)] = 0;
    }

#if 0
    printf("\n\n\n Q-Sorting (in function)\n\n\n\n");            
    for(index = 0; index < 5; index++) {
        printf("%s \n", products[index]);
    }
#endif

    printf("########## returnSize: %d \n", (*returnSize));
    return sugString;
}

int main (void) {
    char ***ret_string;
    int *returnSize = (int *)malloc(sizeof(int));
    int **returnColumnSizes = (int **)malloc(sizeof(int *));

    char **products = (char **)malloc(5 *sizeof(char *));
    char *input1[] = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    char *searchWord = (char *)malloc(5*sizeof(char));
    int index = 0, index_2 = 0;

    for(index = 0; index < 5; index++) {
        products[index] = (char *)malloc(strlen(input1[index]) * sizeof(char));
        strcpy(products[index], input1[index]);
        printf("%s \n", products[index]);
    }
    strcpy (searchWord, "mouse");

    ret_string = suggestedProducts(products, 5, searchWord, returnSize, returnColumnSizes);

#if 1
    for (index = 0; index < strlen(searchWord); index++) {
        for (index_2 = 0; index_2 < (*returnColumnSizes)[index]; index_2++)
            printf("%s, ", ret_string[index][index_2]);

        printf("\n");
    }
    
#endif
    return 0;
}