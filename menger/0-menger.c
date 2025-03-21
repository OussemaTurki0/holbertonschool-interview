#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * should_be_empty - Checks if the current cell should be empty
 * @r: The current row of the cell
 * @c: The current column of the cell
 *
 * Return: 1 if the cell should be empty, 0 otherwise
 */
int should_be_empty(int r, int c)
{
    while (r > 0 && c > 0)
    {
        if (r % 3 == 1 && c % 3 == 1)
            return (1);
        r /= 3;
        c /= 3;
    }
    return (0);
}

/**
 * draw_menger_sponge - Renders a 2D Menger Sponge of a given level
 * @n: The level of the Menger Sponge to be drawn
 */
void draw_menger_sponge(int n)
{
    int size, i, j;

    if (n < 0)
        return;

    size = pow(3, n);

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (should_be_empty(i, j))
                putchar(' ');
            else
                putchar('#');
        }
        putchar('\n');
    }
}
