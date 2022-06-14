#include "divisor_sum.h"

int is_perfect_number(unsigned long n)
{
    unsigned long divisorSum = divisor_sum(n);
    if (divisorSum == n)
    {
        return 1;
    }
    return 0;
}