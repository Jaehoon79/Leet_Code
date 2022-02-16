#include <stdio.h>

int memo_wayofup[46] = {1,1,0,};

/* This is framework of DP(especially Top-Bottom - Memorization) */
int climbStairs(int n) {
    if (memo_wayofup[n] != 0)
        return memo_wayofup[n];
    
    memo_wayofup[n] = climbStairs(n-1) + climbStairs(n-2);

    return memo_wayofup[n];
}

int main ()
{
    int input_stairs = 3;

    printf("Result : %d \n", climbStairs(input_stairs));

    return 0;
}