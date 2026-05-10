#include "matrix.h"
#include "libft.h"

void	remove_matrix(matrix_t *A)
{
	int	i;

	if (!A)
		return ;
	i = 0;
	while (i < A->rows)
	{
		free(A->matrix[i]);
		i++;
	}
	free(A->matrix);
	free(A);
}