#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 // Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode listnode;

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int index = 0;
    int count = 0;
    int cmp[10000] = {0,};
    listnode *ret;
    
    if (!listsSize) return NULL;

    for (index = 0; index < listsSize; index++) {
        listnode *tmp = lists[index];
        while (tmp != NULL) {
            printf("%d \n", tmp->val);
            cmp[count++] = tmp->val;
            tmp = tmp->next;
        }
    }
    qsort(cmp, count, sizeof(int), cmpfunc);

    ret = (listnode *)malloc(sizeof(listnode));
    listnode *tmp = ret;

    //printf("After Qsort \n");
    for (index = 0; index < count; index++) {
        //printf("%d \n", cmp[index]);
        tmp->next = (listnode *)malloc(sizeof(listnode));
        tmp->next->val = cmp[index];
        tmp = tmp->next;
        tmp->next = NULL;
    }

    return ret->next;
}

int main() {
    int lists[3][3] = {{1,4,5},{1,3,4},{2,6,-1}};
    int index, subindex;
    listnode *ret;

    listnode **Quest1 = (listnode **)malloc(sizeof(listnode)*3);
#if 0
    listnode *subQ1 = (listnode *)malloc(sizeof(listnode));
    listnode *subQ2 = (listnode *)malloc(sizeof(listnode));
    listnode *subQ3 = (listnode *)malloc(sizeof(listnode));
    subQ1->val = 1; subQ1->next = subQ2;
    subQ2->val = 4; subQ2->next = subQ3;
    subQ3->val = 5; subQ3->next = NULL;
    Quest1[0] = subQ1;
#endif

    for (index = 0; index < 3; index++) {
        listnode *org = (listnode *)malloc(sizeof(listnode));
        listnode *tmp = org;
        for (subindex = 0; subindex < 3; subindex++) {
            if (lists[index][subindex] == -1) continue;
            tmp->next = (listnode *)malloc(sizeof(listnode));
            tmp->next->val = lists[index][subindex];
            tmp = tmp->next;
        }
        Quest1[index] = org->next;
    }

    ret = mergeKLists(Quest1, 3);

    while (ret != NULL) {
        printf("%d \n", ret->val);
        ret = ret->next;
    }

#if 0
    for(index = 0; index < 3; index++) {
        listnode *tmp = Quest1[index];
        while (tmp != NULL) {
            printf("%d\n", tmp->val);
            tmp = tmp->next;
        }
    }
#endif

    return 0;
}