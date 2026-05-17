#include "libft.h"

static int count_digits(int n)
{
    int count;
    long num;
    
    count = 0;
    num = n;
    if (num <= 0)
        count = 1;
    while (num != 0)
    {
        count++;
        num /= 10;
    }
    return (count);
}

char *ft_itoa(int n)
{
    char *str;
    int len;
    long num;
    
    len = count_digits(n);
    str = malloc(len + 1);
    if (!str)
        return (NULL);
    num = n;
    if (num < 0)
        num = -num;
    str[len] = '\0';
    len--;
    while (len >= 0)
    {
        str[len] = (num % 10) + '0';
        num /= 10;
        len--;
    }
    if (n < 0)
        str[0] = '-';
    return (str);
}