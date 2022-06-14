unsigned char digit_count(unsigned long n)
{
    unsigned char res = 0;

    while (n > (unsigned long)0)
    {
        res = res + 1;
        n = n / 10;
    }
    return res;
}