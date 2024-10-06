#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_S   (128)

int lengthOfLongestSubstring(char* s) {
    int *hash_map = (int *)malloc(MAX_S * sizeof(int));
    int cnt = 0, index = 0, sub_index = 0;;
    int str_len = strlen(s);
    int max_cnt = 0;

    if ((!str_len) || (str_len == 1)) return str_len;

    for (index = 0; index < str_len - 1; index++) {
        int cnt = 1;
        memset(hash_map, 0, sizeof(int) * MAX_S);

        hash_map[(int)s[index]] += 1;
        if(cnt > max_cnt) max_cnt = cnt;

        for (sub_index = index + 1; sub_index < str_len; sub_index++) {
            if (!hash_map[(int)s[sub_index]])  {
                hash_map[(int)s[sub_index]] += 1;
                cnt++;
                if (cnt > max_cnt) max_cnt = cnt;
            }
            else break;
        }
    }

    return max_cnt;
}

int main (void) {
    char *s = "abcabcbb";
    printf("strcnt : %d \n", lengthOfLongestSubstring(s));
    printf("ascii: %d \n", (int)' ');
    return 0;
}