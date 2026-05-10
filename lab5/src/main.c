#include "matrix.h"
#include "libft.h"

int	main(void)
{
	matrix_t	*A;
	matrix_t	*B;
	matrix_t	*C;

	ft_putstr_fd("Creating matrix A (2x3):\n", 1);
	A = create_matrix(2, 3);
	if (!A)
		return (1);
	A->matrix[0][0] = 1;
	A->matrix[0][1] = 2;
	A->matrix[0][2] = 3;
	A->matrix[1][0] = 4;
	A->matrix[1][1] = 5;
	A->matrix[1][2] = 6;
	print_matrix(A);

	ft_putstr_fd("\nCreating matrix B (3x2):\n", 1);
	B = create_matrix(3, 2);
	if (!B)
	{
		remove_matrix(A);
		return (1);
	}
	B->matrix[0][0] = 7;
	B->matrix[0][1] = 8;
	B->matrix[1][0] = 9;
	B->matrix[1][1] = 10;
	B->matrix[2][0] = 11;
	B->matrix[2][1] = 12;
	print_matrix(B);

	ft_putstr_fd("\nMultiplying A x B:\n", 1);
	C = mult_matrix(A, B);
	if (!C)
		ft_putstr_fd("Error: incompatible matrices\n", 2);
	else
		print_matrix(C);

	remove_matrix(A);
	remove_matrix(B);
	remove_matrix(C);
	return (0);
}