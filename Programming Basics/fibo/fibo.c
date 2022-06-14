unsigned long fibo(unsigned long n)
{
    unsigned long fibo_1 = 0;
    unsigned long fibo_2 = 1;
    unsigned long res = fibo_1 + fibo_2;

    for (unsigned long i = 0; i <= n; i++)
    {
        if (i <= 1)
            res = i;
        else
        {
            res = fibo_1 + fibo_2;
            fibo_1 = fibo_2;
            fibo_2 = res;
        }
    }
    return res;
}