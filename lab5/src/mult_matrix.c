#include "matrix.h"
#include "libft.h"

matrix_t	*mult_matrix(matrix_t *A, matrix_t *B)
{
	matrix_t	*C;
	int			i;
	int			j;
	int			k;

	if (!A || !B || A->columns != B->rows)
		return (NULL);
	C = create_matrix(A->rows, B->columns);
	if (!C)
		return (NULL);
	i = 0;
	while (i < A->rows)
	{
		j = 0;
		while (j < B->columns)
		{
			C->matrix[i][j] = 0;
			k = 0;
			while (k < A->columns)
			{
				C->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (C);
}