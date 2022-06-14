#include <stdio.h>
#include "digit_count.h"

int main()
{
    unsigned long i = 1;
    unsigned long j = 1;
    printf("digit_count(0)) = 1 \n");
    printf("digit_count(1)) = 1 \n");
    while (i <= (unsigned long)63)
    {
        j *= 2;
        printf("digit_count(%lu) = %d \n", j, digit_count(j));
        i++;
    }
    return 0;
}