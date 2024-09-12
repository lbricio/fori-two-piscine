#include "ft_abs.h"
#include <stdio.h>

int main()
{
    int x = 5;
    int y = -3;
    printf("%i\n", ABS(1));
    printf("%i\n", ABS(0));
    printf("%i\n", ABS(-1));
    printf("%i\n", ABS(x - 3));
    printf("%i\n", ABS(y - 3));
    printf("%i\n", ABS(x - y));
    printf("%i\n", ABS((x * y) + (2 * y)));
}