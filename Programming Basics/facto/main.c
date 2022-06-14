#include <stdio.h>
#include "facto.h"

int main()
{
    for (unsigned long i = 0; i <= (unsigned long)20; i++)
    {
        printf("facto(%lu) = %lu \n", i, facto(i));
    }
    return 0;
}