#ifndef TXTFILE_H
# define TXTFILE_H

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>

/* Обязательные функции */
char	**read_file(const char *filename);
void	free_lines(char **lines);
void	print_lines(char **lines);

/* Функция варианта 3 */
char	**replace_substr(char **lines, const char *old, const char *new_str);

#endif