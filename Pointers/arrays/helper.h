#ifndef _HELPER_H
#define _HELPER_H

#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b);
void array_print(int *begin, int *end);
int array_is_sorted(int *begin, int *end);
void array_sorted_fill(int *begin, int *end);
void array_random_fill(int *begin, int *end);

static inline double time_gdiff(struct timespec t0, struct timespec t1)
{
  double s = t1.tv_sec - t0.tv_sec;
  return s + (t1.tv_nsec - t0.tv_nsec) * 1e-9;
}

typedef void (*sort_fun)(int *, int *);

void bench_sort(int *begin, int *end, sort_fun sort, const char *msg);
int array_min(int *begin, int *end);
size_t array_count_occurences(int *begin, int *end, int x);
int array_sum(int *begin, int *end);
void array_reverse(int *begin, int *end);
void array_merge(int *dst, int *a1, int *a2, int *e1, int *e2);

#endif
