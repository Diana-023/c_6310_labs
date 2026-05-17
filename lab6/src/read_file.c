#include "txtfile.h"
#include <fcntl.h>
#include <unistd.h>

static int	count_lines(int fd)
{
	char	buffer[1024];
	int		bytes_read;
	int		line_count;
	int		i;
	int		has_content;

	line_count = 0;
	has_content = 0;
	while (1)
	{
		bytes_read = read(fd, buffer, 1024);
		if (bytes_read <= 0)
			break ;
		has_content = 1;
		i = 0;
		while (i < bytes_read)
		{
			if (buffer[i] == '\n')
				line_count++;
			i++;
		}
	}
	// Если файл не пустой и не заканчивается на \n, добавляем последнюю строку
	if (has_content && line_count == 0)
		return (1);
	// Если последний символ не \n, добавляем 1
	// Для этого нужно проверить последний байт файла
	return (line_count);
}

static int	file_ends_with_newline(int fd)
{
	char	last_char;
	int		bytes_read;
	int		offset;

	// Сохраняем текущую позицию
	offset = lseek(fd, 0, SEEK_CUR);
	// Идем к концу файла
	if (lseek(fd, -1, SEEK_END) < 0)
	{
		lseek(fd, offset, SEEK_SET);
		return (1); // Предполагаем, что заканчивается на \n при ошибке
	}
	bytes_read = read(fd, &last_char, 1);
	lseek(fd, offset, SEEK_SET);
	if (bytes_read != 1)
		return (1);
	return (last_char == '\n');
}

static char	*read_line(int fd)
{
	char	*line;
	char	ch;
	int		len;
	char	*new_line;

	line = NULL;
	len = 0;
	while (read(fd, &ch, 1) > 0)
	{
		if (ch == '\n')
			break ;
		new_line = (char *)malloc(len + 2);
		if (!new_line)
		{
			free(line);
			return (NULL);
		}
		if (line)
		{
			ft_memcpy(new_line, line, len);
			free(line);
		}
		line = new_line;
		line[len++] = ch;
	}
	// Если достигли конца файла и есть прочитанные символы
	if (len > 0)
	{
		if (!line)
			line = (char *)malloc(1);
		if (line)
			line[len] = '\0';
		return (line);
	}
	free(line);
	return (NULL);
}

char	**read_file(const char *filename)
{
	int		fd;
	char	**lines;
	int		i;
	int		line_count;
	int		ends_with_nl;

	if (!filename)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line_count = count_lines(fd);
	ends_with_nl = file_ends_with_newline(fd);
	// Если файл не заканчивается на \n, добавляем строку
	if (!ends_with_nl && line_count > 0)
		line_count++;
	close(fd);
	
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	
	lines = (char **)ft_calloc(line_count + 1, sizeof(char *));
	if (!lines)
	{
		close(fd);
		return (NULL);
	}
	
	i = 0;
	while (i < line_count)
	{
		lines[i] = read_line(fd);
		if (!lines[i])
		{
			free_lines(lines);
			close(fd);
			return (NULL);
		}
		i++;
	}
	close(fd);
	return (lines);
}