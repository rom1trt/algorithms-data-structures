unsigned long facto(unsigned long n)
{
    if (n == 0)
    {
        return (unsigned long)1;
    }
    else
    {
        return n * facto(n - 1);
    }
}
