#include "matrix.h"
#include "libft.h"

matrix_t	*create_matrix(int rows, int cols)
{
	matrix_t	*mat;
	int			i;

	if (rows <= 0 || cols <= 0)
		return (NULL);
	mat = (matrix_t *)malloc(sizeof(matrix_t));
	if (!mat)
		return (NULL);
	mat->rows = rows;
	mat->columns = cols;
	mat->matrix = (int **)malloc(rows * sizeof(int *));
	if (!mat->matrix)
	{
		free(mat);
		return (NULL);
	}
	i = 0;
	while (i < rows)
	{
		mat->matrix[i] = (int *)malloc(cols * sizeof(int));
		if (!mat->matrix[i])
		{
			while (--i >= 0)
				free(mat->matrix[i]);
			free(mat->matrix);
			free(mat);
			return (NULL);
		}
		i++;
	}
	return (mat);
}