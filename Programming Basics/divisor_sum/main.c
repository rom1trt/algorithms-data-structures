#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include "divisor_sum.h"

int main(int argc, char **argv)
{
    unsigned long param = strtoul(argv[1], NULL, 10);
    if (argc != 2)
    {
        errx(1, "The number of arguments is not valid");
    }
    if (param == 0)
    {
        errx(1, "The parameter is not valid");
    }
    printf("divisor_sum(%lu) = %lu \n", param, divisor_sum(param));
    return 0;
}
