#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

bool isPalindrome2 (int x) {
    int length = 0;
    int index = 0;
    char *palindrome = (char *)malloc(10);

    if (x < 0) return false;

    length = sprintf(palindrome, "%d", x);

    while (index <= (length/2)) {
        //printf("%c, %c \n", palindrome[index], palindrome[(length-1) - index]);
        if (palindrome[index] != palindrome[(length-1) - index]) return false;
        index++;
    }
    return true;
}
bool isPalindrome (int x) {
    int temp = x, rev = 0;

    while (temp > 0) {
        rev = (rev * 10) + (temp % 10);
        temp = temp / 10;
    }
    printf ("x = %d, rev = %d \n", x, rev);
    if (rev == x) return true;
    else return false;
}

int main (void) {
    int test1 = 121;
    int test2 = -121;
    int test3 = 10;

    printf("answer1: %d \n", isPalindrome(test1));
    //printf("answer2: %d \n", isPalindrome(test2));
    //printf("answer3: %d \n", isPalindrome(test3));

    return 0;
}