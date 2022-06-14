unsigned long isqrt(unsigned long n)
{
    unsigned long r = n;
    while (r * r > n)
    {
        r += n / r;
        r /= (unsigned long)2;
    }
    return r;
}