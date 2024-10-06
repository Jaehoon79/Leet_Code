#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**  Definition for singly-linked list. **/
struct ListNode {
      int val;
      struct ListNode *next;
 };

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *ret, *tmp_node;
    int num_cnt = 1;
    int l1_l2_sum = 0;
    int l1_l2_carry = 0;

    ret = (struct ListNode *)malloc(sizeof(struct ListNode));
    ret->val = (l1->val + l2->val) % 10;
    l1_l2_carry = (l1->val + l2->val) / 10;

    tmp_node = ret;

    while ((l1->next != NULL) || (l2->next != NULL)) {
        tmp_node->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        tmp_node = tmp_node->next;

        if ((l1->next != NULL) && (l2->next != NULL)) {
            l1 = l1->next;
            l2 = l2->next;
            l1_l2_sum = l1->val + l2->val + l1_l2_carry;
        }
        else if ((l1->next == NULL) && (l2->next != NULL)) {
            l2 = l2->next;
            l1_l2_sum = l2->val + l1_l2_carry;
        }
        else {
            l1 = l1->next;
            l1_l2_sum = l1->val + l1_l2_carry;
        }

        tmp_node->val = l1_l2_sum % 10;
        l1_l2_carry = l1_l2_sum / 10;
        printf("sum: %d, carry: %d, val: %d\n", l1_l2_sum, l1_l2_carry, tmp_node->val);
    }

    if (l1_l2_carry > 0) {
        tmp_node->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        tmp_node = tmp_node->next;
        tmp_node->val = l1_l2_carry;
    }
    tmp_node->next = NULL;
    return ret;
}

#define INPUT   (3)
int main (void) {
    struct ListNode *input1_0 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *input1_1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *input1_2 = (struct ListNode *)malloc(sizeof(struct ListNode));

    struct ListNode *input2_0 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *input2_1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *input2_2 = (struct ListNode *)malloc(sizeof(struct ListNode));

    struct ListNode *ret = (struct ListNode *)malloc(sizeof(struct ListNode));
    int index = 0;

    input1_0->val = 2;
    input1_1->val = 4;
    input1_2->val = 3;
    input1_0->next = input1_1;
    input1_1->next = input1_2;
    input1_2->next = NULL;

    input2_0->val = 5;
    input2_1->val = 6;
    input2_2->val = 4;
    input2_0->next = input2_1;
    input2_1->next = input2_2;
    input2_2->next = NULL;

    ret = addTwoNumbers(input1_0, input2_0);

    while (ret != NULL) {
        printf("%d \n", ret->val);
        ret = ret->next;
    }

    return 0;
}