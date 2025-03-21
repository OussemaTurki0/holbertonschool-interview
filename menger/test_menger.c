#include <stdio.h>
#include "menger.h"

int main(void)
{
    int level;

    printf("Enter the Menger Sponge level: ");
    scanf("%d", &level);

    printf("Drawing Menger Sponge of level %d:\n", level);
    draw_menger_sponge(level);

    return 0;
}
