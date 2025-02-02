#include "sandpiles.h"
#include <stdio.h>

void print_grid(int grid[3][3]);

int main(void)
{
    int grid1[3][3] = {
        {1, 3, 1},
        {3, 3, 3},
        {1, 3, 1}
    };

    int grid2[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    printf("Initial grid1:\n");
    print_grid(grid1);

    printf("Initial grid2:\n");
    print_grid(grid2);

    printf("\nComputing sandpiles_sum...\n");
    sandpiles_sum(grid1, grid2);

    printf("\nFinal stable grid:\n");
    print_grid(grid1);

    return (0);
}

void print_grid(int grid[3][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}
