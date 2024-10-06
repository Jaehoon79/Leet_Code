#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tribo_nums[38] = {0, 1, 1, 2, 0,};

int tribonacci(int n)
{
    if (n < 4)
        return tribo_nums[n];

    if (tribo_nums[n] == 0)
        tribo_nums[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    
    return tribo_nums[n];
}

//4 - 4
//25 - 1389537

int main()
{
    int input_1 = 4, input_2 = 25;
    int output_1 = 0, output_2 = 0;

    output_1 = tribonacci(input_1);
    output_2 = tribonacci(input_2);

    printf("TEST Result: output_1(%d), output_2(%d)\n", output_1, output_2);

    return 0;
}