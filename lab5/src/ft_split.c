#include "libft.h"

static int count_words(char const *s, char c)
{
    int count;
    int i;
    
    count = 0;
    i = 0;
    while (s[i])
    {
        while (s[i] && s[i] == c)
            i++;
        if (s[i])
            count++;
        while (s[i] && s[i] != c)
            i++;
    }
    return (count);
}

static char *get_word(char const *s, char c, int *index)
{
    char *word;
    int start;
    int len;
    int i;
    
    while (s[*index] && s[*index] == c)
        (*index)++;
    start = *index;
    while (s[*index] && s[*index] != c)
        (*index)++;
    len = *index - start;
    word = malloc(len + 1);
    if (!word)
        return (NULL);
    i = 0;
    while (i < len)
    {
        word[i] = s[start + i];
        i++;
    }
    word[i] = '\0';
    return (word);
}

static void free_all(char **result, int pos)
{
    while (pos > 0)
    {
        pos--;
        free(result[pos]);
    }
    free(result);
}

char **ft_split(char const *s, char c)
{
    char **result;
    int words;
    int i;
    int index;
    
    if (!s)
        return (NULL);
    words = count_words(s, c);
    result = malloc((words + 1) * sizeof(char *));
    if (!result)
        return (NULL);
    i = 0;
    index = 0;
    while (i < words)
    {
        result[i] = get_word(s, c, &index);
        if (!result[i])
        {
            free_all(result, i);
            return (NULL);
        }
        i++;
    }
    result[i] = NULL;
    return (result);
}