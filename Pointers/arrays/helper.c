#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "helper.h"

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

// Print an array.
void array_print(int *begin, int *end)
{
    for (int line = 0; begin != end; ++begin)
    {
        if (line > 72)
        {
            printf("|`|\n");
            line = 0;
        }

        line += printf("| %4d ", *begin);
    }

    printf("|\n");
}

// Test if an array is sorted.
// If the array is sorted, return true (1).
// Otherwise, return false (0).
int array_is_sorted(int *begin, int *end)
{
    int tmp = *begin;
    for (int *p = begin + 1; p < end; p++)
    {
        if (tmp > *p)
        {
            return 0;
        }
    }
    return 1;
}

// Fill an array with sorted values.
void array_sorted_fill(int *begin, int *end)
{
    for (int i = 0; begin != end; ++begin, ++i)
        *begin = i;
}

// Fill an array with random values.
void array_random_fill(int *begin, int *end)
{
    for (; begin != end; ++begin)
        *begin = random() % 10000;
}

// Benchmark an algorithm.
void bench_sort(int *begin, int *end, sort_fun sort, const char *msg)
{
    struct timespec t0, t1;

    clock_gettime(CLOCK_MONOTONIC, &t0);
    sort(begin, end);
    clock_gettime(CLOCK_MONOTONIC, &t1);

    printf("%s:    \t%g\n", msg, time_gdiff(t0, t1));
    assert(array_is_sorted(begin, end));
}

// #include <assert.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// #include "helper.h"

// // Swap the contents of two variables.
// void swap(int *a, int *b)
// {
//     int tmp;
//     tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

// // Print an array.
// void array_print(int *begin, int *end)
// {
//     for (int line = 0; begin != end; ++begin)
//     {
//         if (line > 72)
//         {
//             printf("|`|\n");
//             line = 0;
//         }

//         line += printf("| %4d ", *begin);
//     }

//     printf("|\n");
// }

// // Test if an array is sorted.
// // If the array is sorted, return true (1).
// // Otherwise, return false (0).
// int array_is_sorted(int *begin, int *end)
// {
//     while (begin + 1 < end && *begin <= *(begin + 1))
//     {
//         begin++;
//     }
//     if (begin == end - 1)
//     {
//         return 1;
//     }
//     return 0;
// }

// // Fill an array with sorted values.
// void array_sorted_fill(int *begin, int *end)
// {
//     for (int i = 0; begin != end; ++begin, ++i)
//         *begin = i;
// }

// // Fill an array with random values.
// void array_random_fill(int *begin, int *end)
// {
//     for (; begin != end; ++begin)
//         *begin = random() % 10000;
// }

// // Benchmark an algorithm.
// void bench_sort(int *begin, int *end, sort_fun sort, const char *msg)
// {
//     struct timespec t0, t1;

//     clock_gettime(CLOCK_MONOTONIC, &t0);
//     sort(begin, end);
//     clock_gettime(CLOCK_MONOTONIC, &t1);

//     printf("%s:    \t%g\n", msg, time_gdiff(t0, t1));
//     assert(array_is_sorted(begin, end));
// }

int array_min(int *begin, int *end)
{
    int *min = begin;
    for (int *p = begin + 1; p < end; p++)
    {
        if (*p < *min)
            min = p;
    }
    return *min;
}

size_t array_count_occurences(int *begin, int *end, int x)
{
    size_t res = 0;
    for (int *p = begin; p < end; p++)
    {
        if (*p == x)
        {
            res += 1;
        }
    }
    return res;
}

int array_sum(int *begin, int *end)
{
    int res = 0;
    for (int *p = begin; p < end; p++)
    {
        res += *p;
    }
    return res;
}

void array_reverse(int *begin, int *end)
{
    while (begin < end)
    {
        swap(begin, end - 1);
        begin++;
        end--;
    }
}

void array_merge(int *dst, int *a1, int *a2, int *e1, int *e2)
{
    int len = 0;
    for (; a1 < e1 && a2 < e2; len++)
    {
        if (*a1 <= *a2)
        {
            dst[len] = *a1;
            a1++;
        }
        else
        {
            dst[len] = *a2;
            a2++;
        }
    }

    for (; a1 < e1; len++, a1++)
    {
        dst[len] = *a1;
    }
    for (; a2 < e2; len++, a2++)
    {
        dst[len] = *a2;
    }
}