# include <stdio.h>

unsigned long sum_of_divisors(unsigned long n, size_t *count)
{
    unsigned long sum_ = 0;
    unsigned long i = 1;
    unsigned long c = 0;
    while (i <= n / 2)
    {
	if (n % i == 0)
	{
		sum_ += i;
		c += 1;
	}
	i++;

    }
    *count = c;
    return sum_;
}

int main()
{
    unsigned long x;
    unsigned long sum;
    size_t count;

    x = 28;
    sum = sum_of_divisors(x, &count);
    printf("x = %lu\n", x);
    printf("sum   = %lu\n", sum);
    printf("count = %zu\n\n", count);

    x = 100;
    sum = sum_of_divisors(x, &count);
    printf("x = %lu\n", x);
    printf("sum   = %lu\n", sum);
    printf("count = %zu\n", count);
}
