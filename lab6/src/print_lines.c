#include "txtfile.h"

void	print_lines(char **lines)
{
	int	i;

	if (!lines)
		return ;
	i = 0;
	while (lines[i])
	{
		ft_putstr_fd(lines[i], 1);
		if (lines[i + 1])
			ft_putchar_fd('\n', 1);
		i++;
	}
}