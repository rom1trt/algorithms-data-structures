#include <stdio.h>
#include <stdlib.h>
#include <err.h>

int isSubstring(char s1[], char s2[]);
int string_len(char s[]);

int main(int argc, char **argv)
{

    if (argc != 3)
    {
        errx(EXIT_FAILURE, "main: Usage: str1 str2");
    }
    else
    {
        int res = isSubstring(argv[1], argv[2]);
        if (res == -1)
        {
            printf("Not found! \n");
        }
        else
        {
            printf("%s \n", argv[1]);
            for (int k = 0; k < res; k++)
            {
                printf(" ");
            }
            printf("^ \n");
        }
    }

    return 0;
}

int isSubstring(char s1[], char s2[])
{
    int len_s1 = string_len(s1);
    int len_s2 = string_len(s2);

    for (int i = 0; i <= len_s1 - len_s2; i++)
    {
        int j;

        for (j = 0; j < len_s2; j++)
            if (s1[i + j] != s2[j])
                break;

        if (j == len_s2)
            return i;
    }

    return -1;
}

int string_len(char s[])
{
    int c = 0;
    while (s[c] != '\0')
        c++;
    return c;
}

void array_rot(int array[], size_t len, size_t offset)
{
    int *nums = calloc(offset, sizeof(int));
    for (size_t i = 0; i < offset; i++)
    {
        nums[i] = array[i + len - offset];
    }
    for (int i = len - offset; i > 0; i--)
    {
        array[i + offset - 1] = array[i - 1];
    }
    for (size_t i = 0; i < offset; i++)
    {
        array[i] = nums[i];
    }
    free(nums);
}