#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int gMaxCount = 0;

typedef struct string_Q {
    char value;
    int count;
    struct string_Q *prev, *next;
} str_Q;

typedef struct {
    struct string_Q *front;
} Q_HEAD;

void printQ (Q_HEAD *header);

void enqueue (Q_HEAD *header, char input_ch) {
    str_Q *tmp = (str_Q *)malloc(sizeof(str_Q));

    /* For empty header of queue */
    if(header->front == NULL) {
        tmp->count = 1;
        tmp->value = input_ch;
        header->front = tmp;
        tmp->prev = NULL;
        tmp->next = NULL;
        gMaxCount = 1;
    } else {
        tmp = header->front;
        /* serch a node of queue has same value */
        while (tmp != NULL) {
            /* update count on existing node */
            if (tmp->value == input_ch) {
                tmp->count++;
                if (tmp->count > gMaxCount)
                    gMaxCount = tmp->count;
                break;
            }
            /* Add new node to header */
            if (tmp->next == NULL) {
                str_Q *add_tmp = (str_Q *)malloc(sizeof(str_Q));
                add_tmp->count = 1;
                add_tmp->value = input_ch;
                add_tmp->next = NULL;
                add_tmp->prev = tmp;
                tmp->next = add_tmp;
                tmp = tmp->next;
            }
            tmp = tmp->next;
        }
    }
}

void rearrange_Q(Q_HEAD *header, str_Q *target) {
    if (target->next != NULL) {
        if (header->front == target) {
            header->front = target->next;
            target->next->prev = NULL;
        }
        else {
            target->prev->next = target->next;
            target->next->prev = target->prev;
        }
    }
    else {
        if (header->front == target)
            header->front = NULL;
        else
            target->prev->next = NULL;
    }

    free(target);
}

char dequeue (Q_HEAD *header, char prev_ch) {
    str_Q *tmp = header->front;
    str_Q *target = NULL;
    int maxcnt = 0;
    char ret;

    while (tmp != NULL) {
        if ((tmp->value != prev_ch) && (tmp->count > maxcnt)) {
            maxcnt = tmp->count;
            target = tmp;
        }
        tmp = tmp->next;
    }

    target->count--;
    ret = target->value;

    if (!target->count) rearrange_Q(header, target);

    return ret;
}

char* reorganizeString(char* s) {
    Q_HEAD *Q_mgnt = (Q_HEAD *)malloc(sizeof(Q_HEAD));
    int str_length = strlen(s);
    int index = 0;

    /* init Q_mgnt header */
    Q_mgnt->front = NULL;
 
    /* counting input string */
    for (index = 0; index < str_length; index++)
        enqueue(Q_mgnt, s[index]); 

    /* Check impossible reoganization input */
    if (gMaxCount > (str_length +1)/2) return "";

    for (index = 0; index < str_length; index++)
        s[index] = dequeue(Q_mgnt, (index == 0)?' ':s[index -1]);

    return s;
}

int main (void) {
    char input_1[] = {'a','a','b'};
    char input_2[] = {'a','a','a','b'};

    printf("1. result = %s \n", reorganizeString(input_1));
    printf("2. result = %s \n", reorganizeString(input_2));

    return 0;
}

/* Retrive queue to print value and count for each item */
void printQ (Q_HEAD *header) {
    str_Q *tmp = (str_Q *)malloc(sizeof(str_Q));

    printf("==== Print Queued value and data ==== \n");

    if (header->front == NULL) {
        printf("Queue is empty \n");
        return;
    }
    tmp = header->front;

    while (tmp != NULL) {
        printf("Queued_ch: %c, count: %d \n", tmp->value, tmp->count);
        tmp = tmp->next;
    }
    printf("===================================== \n");
}