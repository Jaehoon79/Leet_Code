#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int myAtoi(char* s) {
    long result = 0; 
    int sign = 1, read_start = 0, index = 0;
    int length = strlen(s);

    while (index < length) {
        if (s[index] == '-') {
            if (read_start) break;
            sign = -1;
            read_start = 1;
        }

        else if (s[index] == '+' && read_start != 1) {
            if (read_start) break;
            sign = 1;
            read_start = 1;
        }

        else if (s[index] >= '0' && s[index] <= '9') {
            result *= 10;
            result += s[index] - 48;
            read_start = 1;
            //printf("%d\n", s[index] - 48);
        }
        else {
            if (read_start == 0 && s[index] != ' ') break;
            if (read_start == 1) break;
        }

        if (result > (pow(2,31) - 1) || result < (pow(2,31) * -1)) break;
        index++;
    }
    
    result = result * sign;
    result = (result > (pow(2,31) - 1))? (pow(2,31) - 1):result;
    result = (result < (pow(2,31) * -1))? (pow(2,31) * -1):result;
    return result;
}

int main (void) {
    char *input1 = "42";
    char *input2 = "   -42";
    char *input3 = "4193 with words";
    char *input4 = "words and 987";
    char *input5 = "-91283472332";
    char *input6 = "20000000000000000000";

    printf("output1: %d\n", myAtoi(input1));
    printf("output2: %d\n", myAtoi(input2));
    printf("output3: %d\n", myAtoi(input3));
    printf("output4: %d\n", myAtoi(input4));
    printf("output5: %d\n", myAtoi(input5));
    printf("output6: %d\n", myAtoi(input6));

    return 0;
}