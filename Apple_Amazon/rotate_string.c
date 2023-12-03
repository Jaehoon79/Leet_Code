#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool rotateString(char* s, char* goal) {
    int index = 0, cpy_length = 0;
    bool ret = false;
    int length = strlen(s);
    char *tmp = (char *)malloc(length * sizeof(char));

    if(!strncmp(s, goal, length)) return true;

    for (index = 0; index < (length - 1); index++) {
        cpy_length = length - (index + 1);
        /*printf ("cpy_length : %d    ", cpy_length);*/

        strncpy (tmp, &(s[index + 1]), cpy_length);
        strncpy (&(tmp[cpy_length]), s, length - cpy_length);

        if (!strncmp(tmp, goal, length)) {
            ret = true;
            break;
        }
        /*printf ("Left Shift: %s \n", tmp);*/
    }

    return ret;    
}  

int main (void) {
    char *input1 = "abcde";
    char *input2 = "abcde";
    char *goal1 = "cdeab";
    char *goal2 = "abced";

    /* Ex.1 */
    printf("output_1: %d \n", rotateString(input1, goal1));
    //printf("output_2: %d \n", rotateString(input2, goal2));

    return 0;
}