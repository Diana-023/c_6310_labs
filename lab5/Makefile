NAME = matrix_program
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./inc

LIBFT_SRC = $(wildcard src/ft_*.c)
MATRIX_SRC = src/create_matrix.c src/remove_matrix.c src/print_matrix.c src/mult_matrix.c
MAIN_SRC = src/main.c

SRCS = $(MAIN_SRC) $(MATRIX_SRC) $(LIBFT_SRC)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re