#include "txtfile.h"

static int	count_occurrences(const char *str, const char *sub)
{
	int	count;
	int	sub_len;
	int	i;

	if (!str || !sub || !*sub)
		return (0);
	count = 0;
	sub_len = ft_strlen(sub);
	i = 0;
	while (str[i])
	{
		if (ft_strncmp(str + i, sub, sub_len) == 0)
		{
			count++;
			i += sub_len;
		}
		else
			i++;
	}
	return (count);
}

static char	*replace_in_string(const char *str, const char *old, const char *new_str)
{
	char	*result;
	int		occ;
	int		old_len;
	int		new_len;
	int		i;
	int		j;

	occ = count_occurrences(str, old);
	if (occ == 0)
		return (ft_strdup(str));
	old_len = ft_strlen(old);
	new_len = ft_strlen(new_str);
	result = (char *)malloc(sizeof(char) * (ft_strlen(str) + occ * (new_len - old_len) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_strncmp(str + i, old, old_len) == 0)
		{
			ft_memcpy(result + j, new_str, new_len);
			j += new_len;
			i += old_len;
		}
		else
		{
			result[j] = str[i];
			j++;
			i++;
		}
	}
	result[j] = '\0';
	return (result);
}

char	**replace_substr(char **lines, const char *old, const char *new_str)
{
	char	**new_lines;
	int		line_count;
	int		i;

	if (!lines || !old || !new_str)
		return (NULL);
	line_count = 0;
	while (lines[line_count])
		line_count++;
	new_lines = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!new_lines)
		return (NULL);
	i = 0;
	while (i < line_count)
	{
		new_lines[i] = replace_in_string(lines[i], old, new_str);
		if (!new_lines[i])
		{
			while (--i >= 0)
				free(new_lines[i]);
			free(new_lines);
			return (NULL);
		}
		i++;
	}
	new_lines[i] = NULL;
	return (new_lines);
}