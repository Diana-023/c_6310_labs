#include "libft.h"

int ft_atoi(const char *nptr)
{
    int sign;
    long result;
    
    sign = 1;
    result = 0;
    while (ft_isspace(*nptr))
        nptr++;
    if (*nptr == '+' || *nptr == '-')
    {
        if (*nptr == '-')
            sign = -1;
        nptr++;
    }
    while (ft_isdigit(*nptr))
    {
        result = result * 10 + (*nptr - '0');
        nptr++;
    }
    return ((int)(result * sign));
}