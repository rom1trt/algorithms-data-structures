#include <stdio.h>
#include <string.h>

int is_separator(char c);
int string_len(char s[]);

void mix(char s[])
{
    int len_of_s = string_len(s);
    int i = 0;
    char tmp;

    for (int j = 0; j < len_of_s; j++)
    {
        if (is_separator(s[j]) == 1)
        {
            if (j - i > 3)
            {
                for (int k = i + 1; k < j - 2; k += 2)
                {
                    tmp = s[k];
                    s[k] = s[k + 1];
                    s[k + 1] = tmp;
                }
            }
            i = j + 1;
        }
    }
    printf("%s ", s);
}

int string_len(char s[])
{
    int c = 0;
    while (s[c] != '\0')
        c++;
    return c;
}

int is_separator(char c)
{
    char separator[] = " ,;:!?./\%*$=+)@_-('&1234567890\"\r\n";

    for (int i = 0; i < string_len(separator); i++)
    {
        if (c == separator[i])
        {
            return 1;
        }
    }

    return 0;
}
