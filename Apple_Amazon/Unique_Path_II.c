#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    unsigned long dp_path[obstacleGridSize][*(obstacleGridColSize)];
    int ind_m, ind_n;
    int col_size = 0;

    /* there is no way to go target */
    if (obstacleGrid[0][0] == 1) return 0;

    memset(dp_path, 0, obstacleGridSize * (*obstacleGridColSize) * sizeof(int));

    for (ind_m = 0; ind_m < obstacleGridSize; ind_m++)
        for (ind_n = 0; ind_n < *(obstacleGridColSize); ind_n++) {
            if(obstacleGrid[ind_m][ind_n] == 1) {
                dp_path[ind_m][ind_n] = 0;
                continue;
            }
            else {
                if(ind_m == 0 && ind_n == 0)
                    dp_path[ind_m][ind_n] = 10;
                else if (ind_m == 0 && ind_n != 0)
                    dp_path[ind_m][ind_n] = dp_path[ind_m][ind_n -1];
                else if (ind_n == 0 && ind_m != 0)
                    dp_path[ind_m][ind_n] = dp_path[ind_m-1][ind_n];
                else
                    dp_path[ind_m][ind_n] = dp_path[ind_m-1][ind_n] + dp_path[ind_m][ind_n-1];
            }
        }

    return (int)(dp_path[ind_m-1][ind_n-1] / 10);
}

int main (void) {
    int index = 0;
    int **obstacleGrid_1 = (int **)malloc(3 * sizeof(int *));
    int **obstacleGrid_2 = (int **)malloc(3 * sizeof(int *)); 
    
    for (index = 0; index < 3; index++) {
        obstacleGrid_1[index] = (int *)malloc(3 * sizeof(int));
        memset(obstacleGrid_1[index], 0, 3 * sizeof(int));
    }

    for (index = 0; index < 3; index++) {
        obstacleGrid_2[index] = (int *)malloc(2 * sizeof(int));
        memset(obstacleGrid_2[index], 0, 2 * sizeof(int));
    }

    printf("ddddd\n");
    obstacleGrid_1[1][1] = 1;
    obstacleGrid_2[1][0] = 1;
    obstacleGrid_2[1][1] = 1;

    int sizecol = 3;
    int size = 3;
 
    printf("1. output : %d \n", uniquePathsWithObstacles(obstacleGrid_1, size, &sizecol));
    
    sizecol = 2;
    size = 3;
    printf("2. output : %d \n", uniquePathsWithObstacles(obstacleGrid_2, size, &sizecol));

    return 0;
}