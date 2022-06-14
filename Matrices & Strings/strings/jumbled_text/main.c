#include <stdio.h>
#include <stdlib.h>
#include "mix.h"
#include <err.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        char s[] = "Hello World!";
        printf("%s \n", s);
        mix(s);
        printf("\n");
    }
    else
    {
        mix(argv[1]);
        printf("\n");
    }
    return 0;
}
