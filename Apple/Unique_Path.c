#include <stdio.h>
#include <string.h>

int uniquePaths(int m, int n) {
    int dp_path[m][n];
    int ind_m = 0, ind_n = 0;

    memset(dp_path, 0, m*n*sizeof(int));

    for (ind_m = 0; ind_m < m; ind_m++) {
        for (ind_n = 0; ind_n < n; ind_n++) {
            if ((ind_m == 0) || (ind_n == 0)) dp_path[ind_m][ind_n] = 1;
            else dp_path[ind_m][ind_n] = dp_path[ind_m-1][ind_n] + dp_path[ind_m][ind_n-1];
        }
    }
    return dp_path[m-1][n-1];
}


int main (void) {
    int input1_m = 3, input1_n = 7;
    int input2_m = 3, input2_n = 2;

    printf("1. output : %d \n", uniquePaths(input1_m, input1_n));
    printf("2. output : %d \n", uniquePaths(input2_m, input2_n));

    return 0;
}