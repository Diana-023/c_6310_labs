NAME = replace_file
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./inc

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/read_file.c \
       $(SRC_DIR)/free_lines.c \
       $(SRC_DIR)/print_lines.c \
       $(SRC_DIR)/replace_substr.c

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

# Собираем старую библиотеку libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Собираем нашу программу
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re