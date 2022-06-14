#include <stdio.h>
#include "fibo.h"

int main()
{
    for (unsigned long i = 0; i <= 90; i++)
    {
        printf("fibo(%lu) = %lu \n", i, fibo(i));
    }
    return 0;
}