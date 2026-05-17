#include "txtfile.h"

static void	print_usage(void)
{
	ft_putendl_fd("Usage: ./replace_file <filename> <old> <new>", STDERR_FILENO);
}

int	main(int argc, char **argv)
{
	char	**lines;
	char	**result;

	if (argc != 4)
	{
		print_usage();
		return (1);
	}
	lines = read_file(argv[1]);
	if (!lines)
	{
		ft_putendl_fd("Error: Cannot read file", STDERR_FILENO);
		return (1);
	}
	ft_putendl_fd("Original content:", STDOUT_FILENO);
	print_lines(lines);
	result = replace_substr(lines, argv[2], argv[3]);
	if (!result)
	{
		ft_putendl_fd("Error: Failed to replace substring", STDERR_FILENO);
		free_lines(lines);
		return (1);
	}
	ft_putendl_fd("\nAfter replacement:", STDOUT_FILENO);
	print_lines(result);
	free_lines(lines);
	free_lines(result);
	return (0);
}