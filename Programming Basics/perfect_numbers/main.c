#include <stdio.h>
#include "divisor_sum.h"
#include "is_perfect_number.h"

int main()
{
    if (is_perfect_number(6) == 1)
        printf("%d \n", 6);
    if (is_perfect_number(28) == 1)
        printf("%d \n", 28);
    if (is_perfect_number(496) == 1)
        printf("%d \n", 496);
    if (is_perfect_number(8128) == 1)
        printf("%d \n", 8128);
    return 0;
}