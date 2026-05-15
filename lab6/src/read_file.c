#include "txtfile.h"
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

static char	*read_whole_file(int fd)
{
	char	*buffer;
	char	*content;
	char	*temp;
	int		bytes_read;

	content = ft_strdup("");
	if (!content)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(content);
		return (NULL);
	}
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(content, buffer);
		free(content);
		if (!temp)
		{
			free(buffer);
			return (NULL);
		}
		content = temp;
	}
	free(buffer);
	if (ft_strlen(content) == 0)
	{
		free(content);
		return (NULL);
	}
	return (content);
}

static int	count_lines_in_content(const char *content)
{
	int	count;
	int	i;

	if (!content || !*content)
		return (0);
	count = 0;
	i = 0;
	while (content[i])
	{
		if (content[i] == '\n')
			count++;
		i++;
	}
	/* Если последний символ не \n, добавляем ещё одну строку */
	if (content[i - 1] != '\n')
		count++;
	return (count);
}

static char	**split_content_to_lines(const char *content, int line_count)
{
	char	**lines;
	int		i;
	int		start;
	int		line_idx;

	lines = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!lines)
		return (NULL);
	i = 0;
	line_idx = 0;
	while (line_idx < line_count && content[i])
	{
		start = i;
		while (content[i] && content[i] != '\n')
			i++;
		lines[line_idx] = ft_substr(content, start, i - start);
		if (!lines[line_idx])
		{
			while (--line_idx >= 0)
				free(lines[line_idx]);
			free(lines);
			return (NULL);
		}
		if (content[i] == '\n')
			i++;
		line_idx++;
	}
	lines[line_count] = NULL;
	return (lines);
}

char	**read_file(const char *filename)
{
	int		fd;
	char	*content;
	char	**lines;
	int		line_count;

	if (!filename)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = read_whole_file(fd);
	close(fd);
	if (!content)
		return (NULL);
	line_count = count_lines_in_content(content);
	if (line_count == 0)
	{
		free(content);
		lines = (char **)malloc(sizeof(char *));
		if (lines)
			lines[0] = NULL;
		return (lines);
	}
	lines = split_content_to_lines(content, line_count);
	free(content);
	return (lines);
}