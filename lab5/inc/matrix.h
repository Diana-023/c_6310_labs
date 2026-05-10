#ifndef MATRIX_H
# define MATRIX_H

typedef struct matrix_struct
{
	int **matrix;
	int rows;
	int columns;
}	matrix_t;

matrix_t	*create_matrix(int rows, int cols);
void		remove_matrix(matrix_t *A);
void		print_matrix(matrix_t *A);
matrix_t	*mult_matrix(matrix_t *A, matrix_t *B);

#endif