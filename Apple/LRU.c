#include <stdio.h>
#include <stdlib.h>

typedef struct lru_cache{
    int key;
    int value;
    int stay_cnt;
    struct lru_cache *next;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *LRUCache_head;
    LRUCache *index_p;
    int index = 0;

    LRUCache_head = (LRUCache *)malloc(sizeof(LRUCache));
    LRUCache_head->key = -1;
    LRUCache_head->value = 0;
    LRUCache_head->stay_cnt = 0;
    LRUCache_head->next = NULL;

    index_p = LRUCache_head;

    while (index < capacity) {
        LRUCache *temp = (LRUCache *)malloc(sizeof(LRUCache));
        temp->key = -1;
        temp->value = 0;
        temp->stay_cnt = 0;
        temp->next = NULL;
        
        index_p->next = temp;
        index_p = index_p->next;
        index++;
    }

    return LRUCache_head;
}

void lRUCacheUpdate (LRUCache * update) {
    while (update != NULL) {
        if (update->key != -1) update->stay_cnt += 1;
        update = update->next;
    }
}

/* return value, return -2 if not found*/
int lRUCacheGet(LRUCache* obj, int key) {
    LRUCache *temp = obj->next;
    int found = 0;
    int value = 0;

    lRUCacheUpdate(temp);

    while (temp != NULL) {
        if (temp->key == key) {
            found = 1;
            temp->stay_cnt = 0;
            break;
        }
        temp = temp->next;
    }

    return (found == 0)? -1 : temp->value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    LRUCache *temp = obj->next;
    int max_stay_cnt = 0;

    lRUCacheUpdate(temp); 

    while (temp != NULL) {
        if (temp->key == -1 || temp->key == key) break;

        if (temp->stay_cnt > max_stay_cnt)
            max_stay_cnt = temp->stay_cnt;

        temp = temp->next;
    }

    if (temp == NULL) {
        temp = obj->next;
        while (temp != NULL) {
            if (temp->stay_cnt == max_stay_cnt) break;
            temp = temp->next;
        }
    }

    temp->key = key;
    temp->value = value;
    temp->stay_cnt = 0;
}

void lRUCacheFree(LRUCache* obj) {
    while(obj != NULL) {
        LRUCache *temp = obj;
        obj = obj->next;
        free(temp);
    }
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
/*

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2],        [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]
*/

/*
Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
*/

int main(void) {
    int index = 0;
    LRUCache *test1_obj = lRUCacheCreate(2);
    LRUCache *temp;

    temp = test1_obj->next;
    while (temp != NULL) {
        printf("key(%d), value(%d), stay_cnt(%d) \n", temp->key, temp->value, temp->stay_cnt);
        temp = temp->next;
    }
    printf("==============\n");
#if 0
    lRUCachePut(test1_obj, 1, 1);
    lRUCachePut(test1_obj, 2, 2);

    temp = test1_obj->next;
    while (temp != NULL) {
        printf("key(%d), value(%d), stay_cnt(%d) \n", temp->key, temp->value, temp->stay_cnt);
        temp = temp->next;
    }

    printf("Key 1, Value %d \n", lRUCacheGet(test1_obj, 1));

    lRUCacheFree (test1_obj);
#else
    /* Put Values */
    lRUCachePut(test1_obj, 1, 1);
    lRUCachePut(test1_obj, 2, 2);

    /* Get Value */
    printf("Key 1, Value %d \n", lRUCacheGet(test1_obj, 1));

    /* Put Value */
    lRUCachePut(test1_obj, 3, 3);

    /* Get Value */
    printf("Key 2, Value %d \n", lRUCacheGet(test1_obj, 2));

    /* Put Value */
    lRUCachePut(test1_obj, 4, 4);

    /* Get Values */
    printf("Key 1, Value %d \n", lRUCacheGet(test1_obj, 1));
    printf("Key 3, Value %d \n", lRUCacheGet(test1_obj, 3));
    printf("Key 4, Value %d \n", lRUCacheGet(test1_obj, 4));

    lRUCacheFree (test1_obj);
#endif
    return 0;
}