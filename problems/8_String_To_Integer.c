#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int main() {
    char s_1[] = "42";
    char s_2[] = "   -42";
    char s_3[] = "4193 with words";
    char s_4[] = "words and 987";

    printf("1.Answer of 1-Q: %d \n", myAtoi(s_1));
    printf("2.Answer of 2-Q: %d \n", myAtoi(s_2));
    printf("3.Answer of 3-Q: %d \n", myAtoi(s_3));
    printf("4.Answer of 4-Q: %d \n", myAtoi(s_4));

    return 0; 
}