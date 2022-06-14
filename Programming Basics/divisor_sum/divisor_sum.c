unsigned long divisor_sum(unsigned long n)
{
    unsigned long sum_ = 1;

    if (n == 1)
    {
        return 0;
    }

    for (unsigned long j = 2; j * j <= n; j++)
    {
        if (n % j == 0)
        {
            sum_ += j;
            sum_ += n / j;
        }
    }
    return sum_;
}