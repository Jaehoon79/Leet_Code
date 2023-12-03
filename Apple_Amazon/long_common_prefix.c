#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int index = 0, sb_index = 0, comp_res = 0;
    int min_leng = 200, tmp = 0;
    char* prefix_str;
    char comp_char;

    //printf("length: %d, strs[0] size: %lu, string:%s\n", strsSize, strlen(strs[0]), strs[0]);

    if (strsSize == 1) return strs[0];

    for(index = 0; index < strsSize; index++) {
        tmp =  strlen(strs[index]);
        if (min_leng > tmp) min_leng = tmp;
    }

    prefix_str = (char *)malloc((min_leng+1) * sizeof(char));

    for (sb_index = 0; sb_index < min_leng; sb_index++) {
        comp_char = strs[0][sb_index];
        comp_res = 0;

        for (index = 1; index < strsSize; index++) {
            if (strs[index][sb_index] != comp_char) comp_res = -1;
        }

        if(comp_res < 0) break;
        prefix_str[sb_index] = comp_char;
    }

    prefix_str[sb_index] = '\0';
    //printf ("common prefix leng: %d, min_length : %d \n", sb_index, min_leng);
    return prefix_str;
}

int main (void) {
    //char *strs1[] = {"flower","flow","flight"};
    char *strs2[] = {"ab","a"};

    //printf("output1: %s \n", longestCommonPrefix(strs1, sizeof(strs1)/sizeof(char *)));
    printf("output2: %s \n", longestCommonPrefix(strs2, sizeof(strs2)/sizeof(char *)));
}