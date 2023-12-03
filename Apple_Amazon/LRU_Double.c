#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_KEY (10000)

typedef struct lRUpage {
    int value;
    int key;
    struct lRUpage *next, *prev;
} LRUPage;

typedef struct lRUhead {
    int capacity;
    int used_cnt;
    LRUPage *front, *rear;
} LRUCache;

LRUPage **gLRUHash;

void lRUCacheFree(LRUCache* obj) {
    LRUPage *page_holder = obj->front;
    LRUPage *page_tmp;

    /* Free LRUPage */
    while (page_holder != NULL) {
        page_tmp = page_holder;
        page_holder = page_holder->next;
        free(page_tmp);
    }

    /* Free LRUCache */
    free(obj);
}

void lRUHashCreate (void) {
    int index = 0;
    gLRUHash = (LRUPage **)malloc(sizeof(LRUPage *) * MAX_KEY);
    
    for (index = 0; index < MAX_KEY; index++) {
        gLRUHash[index] = NULL;
    }
}

LRUPage* lRUPageCreate (void) {
    LRUPage *page = (LRUPage *)malloc(sizeof(LRUPage));
    page->prev = page->next = NULL;
    page->key = 0;
    page->value = 0;
    return page;
}

bool is_lRUCache_full (LRUCache * cache) {
    return (cache->capacity == cache->used_cnt);
}

bool is_lRUCache_empty (LRUCache * cache) {
    return (cache->used_cnt == 0);
}

void lRUCacheArrange(LRUCache *obj, LRUPage *page) {
    /* page is already in the first or there is only one page in obj */
    if ((obj->front == page) || (obj->used_cnt == 1))
        return;

    /* Detach: Page is in the rear of obj */
    if (obj->rear == page) {
        page->prev->next = NULL;
        obj->rear = page->prev;
    }
    /* Detach: page is in the middle of obj */
    else {
        page->prev->next = page->next;
        page->next->prev = page->prev;
    }
    
    /* Attach: Add page at the first of obj */
    page->next = obj->front;
    obj->front->prev = page;
    obj->front = page;
    page->prev = NULL;
}

int lRUCacheGet(LRUCache* obj, int key) {
    LRUPage *page_temp;
    /* Cache and Hash status pre-checking */
    if ((is_lRUCache_empty(obj)) || (gLRUHash[key] == NULL)) return -1;

    page_temp = gLRUHash[key];
    
    lRUCacheArrange(obj, page_temp);

    return gLRUHash[key]->value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    LRUPage *page_tmp;

    /* update existing page with new value */
    if (gLRUHash[key] != NULL) {
        gLRUHash[key]->value = value;
        lRUCacheArrange(obj, gLRUHash[key]);
    }
    else {
        page_tmp = lRUPageCreate();
        page_tmp->key = key;
        page_tmp->value = value;

        /* 1st: Check LRUCache if it is empty */
        if (is_lRUCache_empty(obj)) {
            obj->front = obj->rear = page_tmp;
            obj->used_cnt += 1;
            gLRUHash[key] = page_tmp;
            return;
        }
        /* 2nd: Check LRUCache if it is full */
        else if(is_lRUCache_full(obj)) {
            LRUPage *remove_temp = obj->rear;

            if (obj->used_cnt == 1)
                obj->front = obj->rear = page_tmp;
            else {
                page_tmp->prev = obj->rear->prev;
                obj->rear = page_tmp;
            }
            
            gLRUHash[page_tmp->key] = page_tmp;
            gLRUHash[remove_temp->key] = NULL;
            free(remove_temp);
            lRUCacheArrange(obj, page_tmp);
            return;
        }
        /* 3rd: Add new page at the first of obj */
        else {
            page_tmp->next = obj->front;
            obj->front->prev = page_tmp;
            obj->front = page_tmp;

            gLRUHash[page_tmp->key] = page_tmp;
            obj->used_cnt += 1;
        }
    }
}

LRUCache* lRUCacheCreate(int capacity) {
    int index = 0;
    LRUCache *cache_tmp = (LRUCache *)malloc(sizeof(LRUCache));

    cache_tmp->front = cache_tmp->rear = NULL;

    cache_tmp->capacity = capacity;
    cache_tmp->used_cnt = 0;

    /* Create Hash Table */
    lRUHashCreate();

    return cache_tmp;
}

/*
["LRUCache","put","put","put","put","get","get"]
[[2],[2,1],[1,1],[2,3],[4,1],[1],[2]]
*/
#if 0
int main (void) {
    LRUCache *obj = lRUCacheCreate(2);
    LRUPage *temp;
    /* Put Values */
    lRUCachePut(obj, 2, 1);
    lRUCachePut(obj, 1, 1);
        temp = obj->front;
    while (temp != NULL) {
        printf("key(%d), value(%d)\n", temp->key, temp->value);
        temp = temp->next;
    }
    lRUCachePut(obj, 2, 3);
        temp = obj->front;
    while (temp != NULL) {
        printf("key(%d), value(%d)\n", temp->key, temp->value);
        temp = temp->next;
    }
    lRUCachePut(obj, 4, 1);

    temp = obj->front;
    while (temp != NULL) {
        printf("key(%d), value(%d)\n", temp->key, temp->value);
        temp = temp->next;
    }


    printf("Key 1, Value %d \n", lRUCacheGet(obj, 1));
    printf("Key 2, Value %d \n", lRUCacheGet(obj, 2));

    lRUCacheFree(obj);
    return 0;
}

#else
int main (void) {
    LRUCache *obj = lRUCacheCreate(3);
    LRUPage *temp;
    /* Put Values */
    lRUCachePut(obj, 1, 1);
    lRUCachePut(obj, 2, 2);
    
    /* Get Value */
    printf("Key 1, Value %d \n", lRUCacheGet(obj, 1));

    /* Put Value */
    lRUCachePut(obj, 3, 3);

    /* Get Value */
    printf("Key 2, Value %d \n", lRUCacheGet(obj, 2));
    temp = obj->front;
    while (temp != NULL) {
        printf("value(%d)\n", temp->value);
        temp = temp->next;
    }

    /* Put Value */
   lRUCachePut(obj, 4, 4);

    temp = obj->front;
    while (temp != NULL) {
        printf("value(%d)\n", temp->value);
        temp = temp->next;
    }

    /* Get Values */
    printf("Key 1, Value %d \n", lRUCacheGet(obj, 1));
    printf("Key 3, Value %d \n", lRUCacheGet(obj, 3));
    printf("Key 4, Value %d \n", lRUCacheGet(obj, 4));

    lRUCacheFree(obj);
    return 0;
}
#endif