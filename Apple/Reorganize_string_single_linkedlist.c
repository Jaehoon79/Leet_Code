/* With Single Linked List for Priority Queue */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ChaCnt {
    char ch;
    int cnt;
    struct ChaCnt * next;
} ChaCnts;

void printQ (ChaCnts *header);

int enqueue_chars (ChaCnts *header, char en_char) {
    ChaCnts *tmp = (ChaCnts *)malloc(sizeof(ChaCnts));
    int ret_cnt = 0;

    /* Checking First Char */
    if (header->next == NULL) {
        tmp->ch = en_char;
        tmp->cnt = ret_cnt = 1;
        tmp->next = NULL;
        header->next = tmp;
    } else {
        tmp = header->next;
        while (tmp != NULL) {
            if (tmp->ch == en_char) {
                tmp->cnt++;
                ret_cnt = tmp->cnt;
                break;
            }
            if (tmp->next == NULL) {
                ChaCnts *add_char = (ChaCnts *)malloc(sizeof(ChaCnts));
                add_char->ch = en_char;
                add_char->cnt = ret_cnt = 1;
                add_char->next = NULL;
                tmp->next = add_char;
                tmp = tmp->next;
            }
            tmp = tmp->next;
        }
    }

    return ret_cnt;
}

char dequeue_char (ChaCnts *header, char pre_cha) {
    ChaCnts *schar = (ChaCnts *)malloc(sizeof(ChaCnts));
    ChaCnts *fchar = (ChaCnts *)malloc(sizeof(ChaCnts));
    int max_cnt = 0;

    schar = header->next;
    while (schar != NULL) {
        if ((schar->cnt > max_cnt) && (schar->ch != pre_cha)) {
            max_cnt = schar->cnt;
            fchar = schar;
        }
        schar = schar->next;
    }

    fchar->cnt--;
    return fchar->ch;
}

void free_ChaCnts (ChaCnts * header) {
    ChaCnts *tmp = header->next;

    while (tmp != NULL) {
        ChaCnts *rm_tmp = tmp;
        tmp = tmp->next;
        free(rm_tmp);
    }
    free(header);
}

char* reorganizeString(char* s) {
    ChaCnts *Header = (ChaCnts *)malloc(sizeof(ChaCnts));
    int length = strlen(s);
    int index = 0;
    int max_cnt = 0;

    Header->ch = 'H';
    Header->cnt = 0;
    Header->next = NULL;

    for (index = 0; index < length; index++) {
        int tmp_cnt = enqueue_chars(Header, s[index]);
        if (tmp_cnt > max_cnt) max_cnt = tmp_cnt; 
    }

    if (max_cnt > (length + 1)/2) return "";

    for (index = 0; index < length; index++)
        s[index] = dequeue_char(Header, (index == 0)?' ':s[index-1]);


    //printQ(Header);
    free_ChaCnts(Header);
    return s;
}

int main (void) {
    char input_1[] = {'a','a','b','\0'};
    char input_2[] = {'a','a','a','b','\0'};

    printf("1. result = %s \n", reorganizeString(input_1));
    printf("2. result = %s \n", reorganizeString(input_2));

    return 0;
}

void printQ (ChaCnts *header) {
    ChaCnts *tmp = (ChaCnts *)malloc(sizeof(ChaCnts));

    printf("==== Print Queued value and data ==== \n");

    if (header->next == NULL) {
        printf("Queue is empty \n");
        return;
    }
    tmp = header->next;

    while (tmp != NULL) {
        printf("Queued_ch: %c, count: %d \n", tmp->ch, tmp->cnt);
        tmp = tmp->next;
    }
    printf("===================================== \n");
}