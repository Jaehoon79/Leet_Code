#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>


int romanToInt2(char * s) {
    int conv_val = 0;
    int index = 0, len_val = strlen(s);
    printf("val: %s, sizeof: %d\n", s, len_val);

    while (index < len_val) {
        if (s[index] == 'I') {
            if (s[index + 1] == 'V') { conv_val += 4; index++;}
            else if (s[index + 1] == 'X') { conv_val += 9; index++;}
            else conv_val += 1;
        }

        else if (s[index] == 'V') conv_val += 5;

        else if (s[index] == 'X') {
            if (s[index + 1] == 'L') { conv_val += 40; index++;}
            else if (s[index + 1] == 'C') { conv_val += 90; index++;}
            else conv_val += 10;
        }

        else if (s[index] == 'L') conv_val += 50;

        else if (s[index] == 'C') {
            if (s[index + 1] == 'D') { conv_val += 400; index++;}
            else if (s[index + 1] == 'M') { conv_val += 900; index++;}
            else conv_val += 100;
        }

        else if (s[index] == 'D') conv_val += 500;

        else if (s[index] == 'M') conv_val += 1000;
        
        printf("%d , index = %d\n", conv_val, index);
        index++;
    }
 
    return conv_val;
}

int romanToInt(char * s) {
    int conv_val = 0;
    int index = 0, len_val = strlen(s);
    printf("val: %s, sizeof: %d\n", s, len_val);

    while (index < len_val) {
        switch (s[index]) {
            case 'M':
                conv_val += 1000;
                break;
            case 'D':
                conv_val += 500;
                break;
            case 'L':
                conv_val += 50;
                break;
            case 'V':
                conv_val += 5;
                break;
            case 'I':
                if (s[index + 1] == 'V') { conv_val += 4; index++;}
                else if (s[index + 1] == 'X') { conv_val += 9; index++;}
                else conv_val += 1;
                break;
            case 'X':
                if (s[index + 1] == 'L') { conv_val += 40; index++;}
                else if (s[index + 1] == 'C') { conv_val += 90; index++;}
                else conv_val += 10;
                break;

            case 'C':
                if (s[index + 1] == 'D') { conv_val += 400; index++;}
                else if (s[index + 1] == 'M') { conv_val += 900; index++;}
                else conv_val += 100;
                break;
        }

        index++;
    }
    return conv_val;
}

int main (void) {
    char *input1 = "III";
    char *input2 = "LVIII";
    char *input3 = "MCMXCIV";

    //printf("output1: %d \n", romanToInt(input1));
    //printf("output2: %d \n", romanToInt(input2));
    printf("output3: %d \n", romanToInt(input3));

    return 0;
}