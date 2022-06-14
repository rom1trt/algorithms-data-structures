#include <stdio.h>
#include "isqrt.h"

int main()
{
    for (unsigned long i = 0; i <= 200; i++)
    {
        printf("isqrt(%lu) = %lu \n", i, isqrt(i));
    }
    return 0;
}