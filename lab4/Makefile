NAME = stats
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./inc

# Библиотека
LIBFT = libft.a

# Исходники программы (ТОЛЬКО main.c, т.к. остальное в библиотеке)
SRC_DIR = .
SRCS = main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

# Собираем исполняемый файл
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Библиотека уже собрана, но если нужно пересобрать:
$(LIBFT):
	@echo "Библиотека уже собрана. Если нужно пересобрать, запустите make re"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Проверка, что библиотека существует
check:
	@if [ ! -f $(LIBFT) ]; then \
		echo "Ошибка: $(LIBFT) не найден!"; \
		echo "Убедитесь, что вы скопировали библиотеку из 3-й лабы"; \
		exit 1; \
	fi

.PHONY: all clean fclean re check