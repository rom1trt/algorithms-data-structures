#include <stdio.h>

// Insertion using the plain algorithm.
void array_insert(int *begin, int *end, int x)
{
    while (end > begin && x < *(end - 1))
    {
        *end = *(end - 1);
        end--;
    }
    *end = x;
}

int *__binarySearch(int *begin, int *end, int x)
{
    int len = (end - begin) / 2;
    int *middle = begin + len;
    while (begin <= end)
    {
        if (*middle < x)
            begin = middle + 1;
        else if (*middle == x)
        {
            return middle;
        }
        else
            end = middle - 1;
        len = (end - begin) / 2;
        middle = begin + len;
    }

    return middle;
}

// Insertion using the binary-search algorithm.
void array_insert_bin(int *begin, int *end, int x)
{
    int *i = __binarySearch(begin, end, x);
    while (i < end)
    {
        *end = *(end - 1);
        end--;
    }
    *(i) = x;
}

// Insertion sort using plain method.
void array_insert_sort(int *begin, int *end)
{
    for (int *p = begin; p < end; p++)
    {
        array_insert(begin, p, *p);
    }
}

// Insertion sort using binary search.
void array_insert_sort_bin(int *begin, int *end)
{
    for (int *p = begin; p < end; p++)
    {
        array_insert_bin(begin, p, *p);
    }
}

