#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct items {
    int val;
    int priority;
    struct items *next;
} items;

typedef struct Queue {
    int Qcnt;
    items *front;
} Queue;

//define: initQ, peek, enqueue, dequeue, isEmpty, creatItems
Queue *initQueue () {
    Queue *newQ = (Queue *)malloc(sizeof(Queue));
    newQ->front =  NULL;
    newQ->Qcnt = 0;
    return newQ;
}

items *creatItems(int val, int pri) {
    items *newItem = (items *)malloc(sizeof(items));
    newItem->priority = pri;
    newItem->val = val;
    newItem->next = NULL;
    return newItem;
}

bool isEmpty(Queue *q) {
    return (q->Qcnt == 0);
}

items * peek(Queue *q) {
    if(isEmpty(q)) {
        printf("Queue is Empty! \n");
        return NULL;
    }
    return q->front;
}

void enQueue(Queue *q, int val, int pri) {
    items *addItem = creatItems(val, pri);

    if (isEmpty(q)) {
        q->front = addItem;
        q->Qcnt++;
        return;
    } 

    if (addItem->priority > q->front->priority) {
        addItem->next = q->front;
        q->front = addItem;
    } else {
        items *low = q->front;
        while (low->next != NULL && low->next->priority >= addItem->priority)
            low = low->next;
        addItem->next = low->next;
        low->next = addItem;
    }
    q->Qcnt++;
}

void deQueue(Queue *q) {
    if(isEmpty(q)) {
        printf("Queue is Empty!\n");
        return;
    }

    items *rmItem = q->front;
    q->front = q->front->next;
    q->Qcnt--;
    free(rmItem);
}

int main () {
    Queue *testQ = initQueue();
    printf("isEmpty?: %d \n", isEmpty(testQ));
    enQueue(testQ, 10, 10);
    enQueue(testQ, 20, 100);
    enQueue(testQ, 30, 5);
    printf("high->val: %d, high->pri: %d\n", peek(testQ)->val, peek(testQ)->priority);
    deQueue(testQ);
    printf("high->val: %d, high->pri: %d\n", peek(testQ)->val, peek(testQ)->priority);
    deQueue(testQ);
    printf("high->val: %d, high->pri: %d\n", peek(testQ)->val, peek(testQ)->priority);
    deQueue(testQ);
    printf("isEmpty?: %d \n", isEmpty(testQ));
    return 0;
}