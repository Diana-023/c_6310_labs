#include "txtfile.h"

int	main(int argc, char **argv)
{
	char	**lines;
	char	**result;

	if (argc != 4)
	{
		ft_putendl_fd("Usage: ./txtfile <filename> <old> <new>", 2);
		return (1);
	}
	lines = read_file(argv[1]);
	if (!lines)
	{
		ft_putendl_fd("Error: Cannot read file", 2);
		return (1);
	}
	ft_putendl_fd("Original content:", 1);
	print_lines(lines);
	result = replace_substr(lines, argv[2], argv[3]);
	if (!result)
	{
		ft_putendl_fd("Error: Memory allocation failed", 2);
		free_lines(lines);
		return (1);
	}
	ft_putendl_fd("\nAfter replacement:", 1);
	print_lines(result);
	free_lines(lines);
	free_lines(result);
	return (0);
}