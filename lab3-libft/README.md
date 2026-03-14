# Лабораторная работа №3: Реализация библиотеки libft

## Цель работы
Создать собственную библиотеку функций, повторяющую поведение стандартных функций языка C, а также реализовать дополнительные полезные функции для работы со строками, памятью и списками.

---

## Теоретическая справка

### Что такое libft?
В школе 42 студенты начинают с проекта libft — они пишут свою собственную библиотеку функций, многие из которых дублируют стандартные, а также добавляют новые полезные функции. Это позволяет:

- Глубоко понять, как работают стандартные функции
- Научиться работать с указателями и памятью
- Создать инструмент, который пригодится во всех следующих проектах

### Структура библиотеки
Библиотека состоит из:

- Заголовочного файла libft.h — объявления всех функций
- Файлов реализации (по одной функции на файл или логическими группами)
- Makefile для автоматической компиляции

---

## Структура работы

### Варианты заданий

Работа разбита на 4 варианта. Каждый студент выполняет один вариант. В сумме все варианты покрывают полную библиотеку libft.

| Вариант | Номера функций | Что делает |
|---------|----------------|------------|
| 1 | 01-12 | Проверка символов и строки |
| 2 | 13-24 | Работа с памятью и преобразования |
| 3 | 25-36 | Работа со списками и продвинутые строки |
| 4 | 37-42 | Дополнительные функции и бонусы |

Номер варианта = (ваш_номер_студента % 4) + 1 (если остаток 0, то вариант 4).

---

## Список функций по вариантам

### Вариант 1: Проверка символов и строки (функции 01-12)

01. ft_isalpha — int ft_isalpha(int c); — Проверяет, является ли символ буквой
02. ft_isdigit — int ft_isdigit(int c); — Проверяет, является ли символ цифрой
03. ft_isalnum — int ft_isalnum(int c); — Проверяет, является ли символ буквой или цифрой
04. ft_isascii — int ft_isascii(int c); — Проверяет, принадлежит ли символ ASCII
05. ft_isprint — int ft_isprint(int c); — Проверяет, является ли символ печатным
06. ft_toupper — int ft_toupper(int c); — Преобразует символ в верхний регистр
07. ft_tolower — int ft_tolower(int c); — Преобразует символ в нижний регистр
08. ft_strlen — size_t ft_strlen(const char *s); — Возвращает длину строки
09. ft_strchr — char *ft_strchr(const char *s, int c); — Ищет символ в строке (слева)
10. ft_strrchr — char *ft_strrchr(const char *s, int c); — Ищет символ в строке (справа)
11. ft_strnstr — char *ft_strnstr(const char *big, const char *little, size_t len); — Ищет подстроку в строке с ограничением
12. ft_strncmp — int ft_strncmp(const char *s1, const char *s2, size_t n); — Сравнивает строки с ограничением

### Вариант 2: Работа с памятью и преобразования (функции 13-24)

13. ft_atoi — int ft_atoi(const char *nptr); — Преобразует строку в целое число
14. ft_calloc — void *ft_calloc(size_t nmemb, size_t size); — Выделяет и обнуляет память
15. ft_strdup — char *ft_strdup(const char *s); — Дублирует строку
16. ft_substr — char *ft_substr(char const *s, unsigned int start, size_t len); — Выделяет подстроку
17. ft_strjoin — char *ft_strjoin(char const *s1, char const *s2); — Объединяет две строки
18. ft_strtrim — char *ft_strtrim(char const *s1, char const *set); — Обрезает символы из set с концов строки
19. ft_split — char **ft_split(char const *s, char c); — Разбивает строку по разделителю
20. ft_itoa — char *ft_itoa(int n); — Преобразует число в строку
21. ft_strmapi — char *ft_strmapi(char const *s, char (*f)(unsigned int, char)); — Применяет функцию к каждому символу
22. ft_striteri — void ft_striteri(char *s, void (*f)(unsigned int, char*)); — Применяет функцию к каждому символу (in-place)
23. ft_putchar_fd — void ft_putchar_fd(char c, int fd); — Выводит символ в файловый дескриптор
24. ft_putstr_fd — void ft_putstr_fd(char *s, int fd); — Выводит строку в файловый дескриптор

### Вариант 3: Работа со списками и продвинутые строки (функции 25-36)

25. ft_putendl_fd — void ft_putendl_fd(char *s, int fd); — Выводит строку с переводом строки
26. ft_putnbr_fd — void ft_putnbr_fd(int n, int fd); — Выводит число в файловый дескриптор
27. ft_lstnew — t_list *ft_lstnew(void *content); — Создаёт новый элемент списка
28. ft_lstadd_front — void ft_lstadd_front(t_list **lst, t_list *new); — Добавляет элемент в начало списка
29. ft_lstsize — int ft_lstsize(t_list *lst); — Возвращает размер списка
30. ft_lstlast — t_list *ft_lstlast(t_list *lst); — Возвращает последний элемент списка
31. ft_lstadd_back — void ft_lstadd_back(t_list **lst, t_list *new); — Добавляет элемент в конец списка
32. ft_lstdelone — void ft_lstdelone(t_list *lst, void (*del)(void*)); — Удаляет один элемент списка
33. ft_lstclear — void ft_lstclear(t_list **lst, void (*del)(void*)); — Удаляет все элементы списка
34. ft_lstiter — void ft_lstiter(t_list *lst, void (*f)(void *)); — Применяет функцию ко всем элементам
35. ft_lstmap — t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)); — Создаёт новый список, применяя функцию
36. ft_isspace — int ft_isspace(int c); — Проверяет пробельный символ

### Вариант 4: Дополнительные функции и бонусы (функции 37-42)

37. ft_strlcpy — size_t ft_strlcpy(char *dst, const char *src, size_t size); — Безопасное копирование строки
38. ft_strlcat — size_t ft_strlcat(char *dst, const char *src, size_t size); — Безопасная конкатенация строк
39. ft_memset — void *ft_memset(void *s, int c, size_t n); — Заполняет память байтом
40. ft_bzero — void ft_bzero(void *s, size_t n); — Обнуляет память
41. ft_memcpy — void *ft_memcpy(void *dest, const void *src, size_t n); — Копирует память
42. ft_memmove — void *ft_memmove(void *dest, const void *src, size_t n); — Копирует память с учётом перекрытия

---

## Структура библиотеки

### Заголовочный файл libft.h

#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_toupper(int c);
int ft_tolower(int c);
size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
char *ft_strnstr(const char *big, const char *little, size_t len);
int ft_strncmp(const char *s1, const char *s2, size_t n);
int ft_atoi(const char *nptr);
void *ft_calloc(size_t nmemb, size_t size);
char *ft_strdup(const char *s);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strtrim(char const *s1, char const *set);
char **ft_split(char const *s, char c);
char *ft_itoa(int n);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void ft_striteri(char *s, void (*f)(unsigned int, char*));
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putendl_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);
t_list *ft_lstnew(void *content);
void ft_lstadd_front(t_list **lst, t_list *new);
int ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstdelone(t_list *lst, void (*del)(void*));
void ft_lstclear(t_list **lst, void (*del)(void*));
void ft_lstiter(t_list *lst, void (*f)(void *));
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int ft_isspace(int c);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
size_t ft_strlcat(char *dst, const char *src, size_t size);
void *ft_memset(void *s, int c, size_t n);
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);

#endif

---

## Требования к реализации

### Общие требования
- Каждая функция должна быть в отдельном файле .c (например, ft_strlen.c, ft_atoi.c)
- Все функции должны компилироваться с флагами -Wall -Wextra -Werror
- Запрещено использовать стандартные функции, которые вы реализуете (кроме write для вывода)
- Для функций с выделением памяти всегда проверять возвращаемое значение malloc
- Все указатели должны проверяться на NULL (если это имеет смысл для функции)

### Специальные требования
- ft_split: должна возвращать массив строк, заканчивающийся NULL-указателем
- ft_itoa: должна обрабатывать INT_MIN корректно
- ft_atoi: должна игнорировать пробелы в начале и обрабатывать знаки +/-
- Работа со списками: все функции должны корректно обрабатывать NULL-указатели

### Бонус
- Код должен соответствовать нормам школы 42 (google norminette)
---

## Порядок выполнения

### 1. Создайте структуру проекта

lab42-libft/
├── inc/
│   └── libft.h
├── src/
│   ├── ft_strlen.c
│   ├── ft_atoi.c
│   └── ... (ваши файлы)
├── Makefile
└── main.c (для тестирования)

### 2. Реализуйте функции своего варианта

Для каждой функции:
- Изучите поведение оригинальной функции (man-страницы)
- Напишите свою реализацию
- Протестируйте на различных входных данных

### 3. Создайте Makefile

Makefile должен поддерживать:
- make all — компиляция библиотеки
- make clean — удаление объектных файлов
- make fclean — удаление объектных файлов и библиотеки
- make re — пересборка
- make bonus — компиляция с бонусными функциями (для варианта 3)

---

## Пример Makefile

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./inc
SRC_DIR = src
OBJ_DIR = obj

SRCS = ft_strlen.c ft_atoi.c ... (добавьте свои файлы)

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME)

.PHONY: all clean fclean re bonus

---

## Тестирование

### Напишите свою тестовую программу

#include "libft.h"
#include <stdio.h>
#include <string.h>

void test_ft_strlen(void)
{
    char *test1 = "Hello, world!";
    char *test2 = "";
    char *test3 = "42";
    
    printf("ft_strlen(\"%s\") = %zu (оригинал: %zu)\n", 
           test1, ft_strlen(test1), strlen(test1));
    printf("ft_strlen(\"%s\") = %zu (оригинал: %zu)\n", 
           test2, ft_strlen(test2), strlen(test2));
    printf("ft_strlen(\"%s\") = %zu (оригинал: %zu)\n", 
           test3, ft_strlen(test3), strlen(test3));
}

int main(void)
{
    printf("=== Тестирование libft ===\n\n");
    
    test_ft_strlen();
    
    return 0;
}

### Компиляция и запуск тестов

Сборка библиотеки:

make

Компиляция тестовой программы:

gcc -Wall -Wextra -Werror -I./inc main.c -L. -lft -o test_program

Запуск:

./test_program

---

## Критерии оценивания

### Базовые требования (максимум 4 балла)
- 1 балл — Makefile работает корректно, библиотека компилируется
- 1 балл — все функции варианта реализованы
- 1 балл — функции проходят базовые тесты
- 1 балл — код соответствует стилю (нет глобальных переменных, проверки NULL, обработка ошибок)

### Дополнительные баллы
- +0.5 балла — реализованы функции из других вариантов (каждые 3 функции)
- +1 балл — реализованы все функции списков (для любого варианта)
- +0.5 балла — тестовая программа покрывает все краевые случаи

### Штрафы
- -1 балл — утечки памяти (проверять valgrind)
- -1 балл — использование запрещённых функций
- -0.5 балла — отсутствие проверок на NULL
- -0.5 балла — некорректная работа с памятью (выход за границы)

---

## Чек-лист для самопроверки

- [ ] Все файлы .c компилируются без ошибок и предупреждений
- [ ] Makefile создаёт библиотеку libft.a
- [ ] Заголовочный файл защищён от повторного включения
- [ ] Каждая функция делает ровно то, что описано
- [ ] Нет утечек памяти (valgrind не показывает потерь)
- [ ] Корректная обработка краевых случаев (пустые строки, NULL, INT_MIN)
- [ ] Код соответствует нормам (не более 25 строк на функцию)
- [ ] Есть тестовая программа, демонстрирующая работу

---

## Сроки сдачи

| Этап | Дата |
|------|------|
| Дата выдачи | 10.03.2026 |
| Дедлайн сдачи (PR создан) | 24.03.2026 23:59 |
| Период ревью | 24.03.2026 - 31.03.2026 |

---

Удачи в реализации! Эта библиотека станет вашим верным помощником во всех следующих проектах.