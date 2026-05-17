#include "txtfile.h"

static char	*replace_in_string(const char *str, const char *old, const char *new_str)
{
	char	*result;
	char	*pos;
	char	*temp;
	int		old_len;
	int		new_len;
	int		count;
	char	*find_pos;

	if (!str || !old || !new_str)
		return (NULL);
	old_len = ft_strlen(old);
	new_len = ft_strlen(new_str);
	if (old_len == 0)
		return (ft_strdup(str));
	// Подсчитываем количество вхождений
	count = 0;
	pos = (char *)str;
	while (1)
	{
		find_pos = ft_strnstr(pos, old, ft_strlen(pos));
		if (!find_pos)
			break ;
		count++;
		pos = find_pos + old_len;
	}
	// Выделяем память под результат
	result = (char *)malloc(ft_strlen(str) + count * (new_len - old_len) + 1);
	if (!result)
		return (NULL);
	// Выполняем замену
	pos = (char *)str;
	temp = result;
	while (*pos)
	{
		find_pos = ft_strnstr(pos, old, ft_strlen(pos));
		if (find_pos == pos)
		{
			ft_memcpy(temp, new_str, new_len);
			temp += new_len;
			pos += old_len;
		}
		else
		{
			*temp = *pos;
			temp++;
			pos++;
		}
	}
	*temp = '\0';
	return (result);
}

char	**replace_substr(char **lines, const char *old, const char *new_str)
{
	char	**new_lines;
	int		i;
	int		count;

	if (!lines || !old || !new_str)
		return (NULL);
	count = 0;
	while (lines[count])
		count++;
	new_lines = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!new_lines)
		return (NULL);
	i = 0;
	while (lines[i])
	{
		new_lines[i] = replace_in_string(lines[i], old, new_str);
		if (!new_lines[i])
		{
			free_lines(new_lines);
			return (NULL);
		}
		i++;
	}
	return (new_lines);
}