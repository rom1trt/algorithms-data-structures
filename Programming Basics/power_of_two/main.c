#include <stdio.h>
#include "power_of_two.h"

int main()
{
    for (unsigned char i = 0; i <= 63; i++)
    {
        printf("power_of_two(%d) = %lu \n", i, power_of_two(i));
    }
    return 0;
}