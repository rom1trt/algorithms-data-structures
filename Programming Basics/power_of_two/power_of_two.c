unsigned long power_of_two(unsigned char n)
{
    int i = 0;
    unsigned long res = 1;

    if (n == 0)
    {
        return (unsigned long)1;
    }

    while (i < n)
    {
        res *= (unsigned long)2;
        i++;
    }
    return res;
}