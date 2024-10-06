#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int calculate(char* s) {
    int index = strlen(s);
    int *calist = (int *)malloc(sizeof(int) * (index +1));
    int loop = 0;
    int caindex = 0;
    int total = 0;
    int num = 0;
    char pre_op = '+';
    memset(calist, 0, sizeof(int) * (index +1));
    //printf("length: %lu, input: %s \n", strlen(s), s);

    for (loop = 0; loop <= index; loop++) {
        if (s[loop] == ' ') continue;
        if (isdigit(s[loop]))
            num = (num * 10) + (s[loop] - '0'); 
        else {
            if (pre_op == '+')
                calist[caindex++] = num;
            else if (pre_op == '-')
                calist[caindex++] = num * -1;
            else if (pre_op == '*') {
                printf("prenum: %d \n", calist[caindex - 1]);
                calist[caindex -1] = calist[caindex -1] * num;
            }
            else if (pre_op == '/')
                calist[caindex -1] = (int)(calist[caindex -1] / num);
            
            num = 0;
            pre_op = s[loop];
        }
    }

    for (loop = 0; loop <= caindex; loop++) {
        printf("%d \n", calist[loop]);
        total += calist[loop];
    }

    return total;
}

int main() {
    char *s_1 = "3+2*2";
    char *s_2 = " 3/2 ";
    char *s_3 = " 3+5 / 2 ";
    char *s_4 = "42";

    printf("1.Answer of 1st-Q: %d \n", calculate(s_1));
    printf("2.Answer of 2nd-Q: %d \n", calculate(s_2));
    printf("3.Answer of 3rd-Q: %d \n", calculate(s_3));
    printf("4.Answer of 4th-Q: %d \n", calculate(s_4));

    return 0;
}