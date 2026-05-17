#include "txtfile.h"

void	print_lines(char **lines)
{
	int	i;

	if (!lines)
		return ;
	i = 0;
	while (lines[i])
	{
		ft_putendl_fd(lines[i], STDOUT_FILENO);
		i++;
	}
}