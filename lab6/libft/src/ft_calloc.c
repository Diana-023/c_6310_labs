#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    void *ptr;
    size_t total;
    
    total = nmemb * size;
    if (nmemb && size && total / nmemb != size)
        return (NULL);
    ptr = malloc(total);
    if (!ptr)
        return (NULL);
    ft_bzero(ptr, total);
    return (ptr);
}