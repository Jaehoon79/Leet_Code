#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX(X, Y)  ((X > Y)? (X) : (Y))

int check_palidromic(char *s, int left, int right) {
    if (s == NULL || left > right) return 0;

    while (left >= 0 && right < strlen (s) && s[left] == s[right]) {
        left--;
        right++;
    }

    return ((right - 1) - (left + 1)) + 1;
}

char* longestPalindrome(char* s) {
    int str_len = strlen(s);
    int index = 0;
    int len1, len2;
    int max_len;
    int start = 0, end = 0;
    char *ret = (char *)malloc(1001 * sizeof(char));

    for (index = 0; index < str_len; index++) {
        len1 = check_palidromic(s, index, index);
        len2 = check_palidromic(s, index, index + 1);
        max_len = MAX(len1, len2);

        if (max_len > (end - start) + 1) {
            start = index - (max_len - 1) / 2;
            end = index + (max_len) / 2;
        }
    }
    printf("start: %d, end: %d, max_len: %d\n", start, end, max_len);

    strncpy(ret, &s[start], (end - start) + 1);
    ret[end-start+1] = '\0';

    return ret;
}

int main (void) {
    char *s0 = "babad";
    char *s1 = "bb";
    char *s2 = "racecar";

    printf("output 1: %s \n", longestPalindrome(s0));
    printf("output 2: %s \n", longestPalindrome(s1));
    printf("output 3: %s \n", longestPalindrome(s2));

    return 0;
}