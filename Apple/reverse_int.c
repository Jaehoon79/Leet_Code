#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int reverse(int x) {
    int index = 0;
    long reverse = 0, temp = 0;
    int is_minus = 1;

    temp = x;

    if (temp < 0) is_minus = -1;
    
    temp *= is_minus;

    while ((temp/10) > 0) {
        reverse *= 10;
        reverse += (temp % 10);
        temp /= 10;

        //printf("reverse :%ld, x = %d\n", reverse, x);
    }

    reverse = ((reverse * 10) + temp) * is_minus;
    //printf("result : %ld \n", reverse);
    if ( (reverse > (pow(2,31) - 1)) || reverse < (pow(2, 31) * -1)) return 0;
    //return ((reverse * 10)+ x) * is_minus;
    return reverse;
}

int main (void) {
    int input1 = 123;
    int input2 = -123;
    int input3 = 1534236469;

    printf("output1: %d\n", reverse(input1));
    printf("output2: %d\n", reverse(input2));
    printf("output3: %d\n", reverse(input3));

    return 0;
}