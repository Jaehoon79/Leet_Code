#if 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define null    (-1000)

/*Definition for a binary tree node.*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *makeBT(int* nums, int numsSize, int index);
void printList(int *nums, int numsSize);

typedef struct TreeCnt {
    struct TreeNode *node;
    int hlevel;
} TreeCnt;

typedef struct queue {
    int qcount;
    int front, rear;
    TreeCnt **lists;
} queue;

bool isEmpty(queue *q) {
    return (q->front == -1 && q->rear == -1);
}

queue *initQueue() {
    queue *newQ = (queue *)malloc(sizeof(queue));
    newQ->qcount = 0;
    newQ->front = newQ->rear = -1;
    newQ->lists = NULL;
    return newQ;
}

void Enqueue (queue *q, struct TreeNode *node, int hlevel) {
    q->qcount++;
    q->lists = (TreeCnt **)realloc(q->lists, sizeof(TreeCnt *) * q->qcount);
    q->lists[q->qcount -1] = (TreeCnt *)malloc(sizeof(TreeCnt));
    q->lists[q->qcount-1]->node = node;
    q->lists[q->qcount-1]->hlevel = hlevel;
    q->rear = q->qcount -1;

    if (q->front == -1)
        q->front = q->rear;
}

void Dequeue (queue *q) {
    if (isEmpty(q)) return;
    q->front++;

    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
}

int FrontTreeLevel (queue *q) {
    if(isEmpty(q)) return -1000;
    return q->lists[q->front]->hlevel;
}

struct TreeNode *FrontTreeNode (queue *q) {
    if(isEmpty(q)) return NULL;
    return q->lists[q->front]->node;
}

int FrontValue (queue *q) {
    if(isEmpty(q)) return -1000;
    return q->lists[q->front]->node->val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize) {
    int *ans = NULL;
    int prevLevel = 0;
    (*returnSize) = 0;

    if (root == NULL) return ans;

    queue *q = initQueue();
    Enqueue(q, root, 0);

    while (!isEmpty(q)) {
        int hlevel = FrontTreeLevel(q);
        struct TreeNode *current = FrontTreeNode(q);

        if (!hlevel || hlevel > prevLevel) {
            (*returnSize)++;
            ans = (int *)realloc(ans, sizeof(int) * (*returnSize));
            ans[(*returnSize)-1] = FrontValue(q);
            prevLevel = hlevel;
        }
        else
            ans[(*returnSize) -1] = FrontValue(q);

        Dequeue(q);

        if (current->left != NULL)
            Enqueue(q, current->left, hlevel + 1);
        if (current->right != NULL)
            Enqueue(q, current->right, hlevel + 1);
    }

    return ans;
}

int main () {
    int nums1[] = {1,2,3,null,5,null,4};
    struct TreeNode *root1 = makeBT(nums1, sizeof(nums1)/sizeof(nums1[0]), 0);
    int *ret1;
    int retSize1;

    ret1 = rightSideView(root1, &retSize1);
    printList(ret1, retSize1);

    return 0;
}

struct TreeNode *makeBT(int* nums, int numsSize, int index) {
    if (index >= numsSize || nums[index] == null) return NULL;
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->val = nums[index];
    newNode->left = makeBT(nums, numsSize, index*2+1);
    newNode->right = makeBT(nums, numsSize, index*2+2);
    return newNode;
}

void printList(int *nums, int numsSize) {
    printf("1.PrintList: \n");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}
#endif