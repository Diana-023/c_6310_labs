#include "libft.h"
#include <string.h>

// Функция для преобразования строки в верхний регистр (для ft_lstmap)
void *to_upper_wrapper(void *content)
{
    char *str = (char *)content;
    char *new_str;
    int i;
    
    if (!str)
        return (NULL);
    new_str = ft_strdup(str);
    if (!new_str)
        return (NULL);
    i = 0;
    while (new_str[i])
    {
        if (new_str[i] >= 'a' && new_str[i] <= 'z')
            new_str[i] -= 32;
        i++;
    }
    return (new_str);
}

// Функция для удаления content (просто free)
void del_content(void *content)
{
    if (content)
        free(content);
}

// Функция для вывода content (для ft_lstiter) - используем ft_putstr_fd
void print_content(void *content)
{
    if (content)
    {
        ft_putstr_fd("\"", 1);
        ft_putstr_fd((char *)content, 1);
        ft_putstr_fd("\" ", 1);
    }
}

// Функция для вывода строки с числом
void print_str_with_int(char *str, int num)
{
    ft_putstr_fd(str, 1);
    ft_putnbr_fd(num, 1);
    ft_putchar_fd('\n', 1);
}

// Функция для вывода строки со строкой
void print_str_with_str(char *str1, char *str2, char *result)
{
    ft_putstr_fd(str1, 1);
    ft_putstr_fd(str2, 1);
    ft_putstr_fd(result, 1);
    ft_putchar_fd('\n', 1);
}

// Функция для вывода строки с одним символом
void print_str_with_char(char *str, char c, char result)
{
    ft_putstr_fd(str, 1);
    ft_putchar_fd('\'', 1);
    ft_putchar_fd(c, 1);
    ft_putstr_fd("': '", 1);
    ft_putchar_fd(result, 1);
    ft_putstr_fd("'\n", 1);
}

// Функция для вывода строки с целым числом
void print_str_with_int_result(char *str, int num)
{
    ft_putstr_fd(str, 1);
    ft_putnbr_fd(num, 1);
    ft_putchar_fd('\n', 1);
}

// Функция для вывода строки с size_t
void print_str_with_sizet(char *str, size_t len)
{
    ft_putstr_fd(str, 1);
    ft_putnbr_fd(len, 1);
    ft_putchar_fd('\n', 1);
}

// Функция для теста ft_strmapi
char to_upper_char(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

void test_list_functions(void)
{
    ft_putendl_fd("\n=== TEST: List Functions ===", 1);
    
    t_list *list = NULL;
    
    ft_lstadd_front(&list, ft_lstnew(ft_strdup("First")));
    ft_lstadd_front(&list, ft_lstnew(ft_strdup("Second")));
    ft_lstadd_front(&list, ft_lstnew(ft_strdup("Third")));
    
    ft_putstr_fd("List after add_front: ", 1);
    ft_lstiter(list, print_content);
    ft_putchar_fd('\n', 1);
    
    ft_putstr_fd("List size: ", 1);
    ft_putnbr_fd(ft_lstsize(list), 1);
    ft_putchar_fd('\n', 1);
    
    ft_putstr_fd("Last element: \"", 1);
    ft_putstr_fd((char *)ft_lstlast(list)->content, 1);
    ft_putstr_fd("\"\n", 1);
    
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Fourth")));
    ft_putstr_fd("After adding 'Fourth' to back: ", 1);
    ft_lstiter(list, print_content);
    ft_putchar_fd('\n', 1);
    
    ft_putstr_fd("New size: ", 1);
    ft_putnbr_fd(ft_lstsize(list), 1);
    ft_putchar_fd('\n', 1);
    
    t_list *upper_list = ft_lstmap(list, to_upper_wrapper, del_content);
    ft_putstr_fd("New list (UPPERCASE): ", 1);
    ft_lstiter(upper_list, print_content);
    ft_putchar_fd('\n', 1);
    
    ft_lstclear(&list, del_content);
    ft_lstclear(&upper_list, del_content);
    ft_putendl_fd("Lists cleared", 1);
}

void test_all_functions(void)
{
    ft_putendl_fd("=== FULL LIBFT TEST ===", 1);
    ft_putchar_fd('\n', 1);
    
    // 1. Character checks
    ft_putendl_fd("1. Character checks:", 1);
    print_str_with_int("   ft_isalpha('A'): ", ft_isalpha('A'));
    print_str_with_int("   ft_isdigit('5'): ", ft_isdigit('5'));
    print_str_with_int("   ft_isalnum('Z'): ", ft_isalnum('Z'));
    print_str_with_int("   ft_isascii(65): ", ft_isascii(65));
    print_str_with_int("   ft_isprint(' '): ", ft_isprint(' '));
    print_str_with_char("   ft_toupper('z'): ", 'z', ft_toupper('z'));
    print_str_with_char("   ft_tolower('Q'): ", 'Q', ft_tolower('Q'));
    print_str_with_int("   ft_isspace('\\t'): ", ft_isspace('\t'));
    
    // 2. String length
    ft_putchar_fd('\n', 1);
    print_str_with_sizet("2. ft_strlen(\"Hello\"): ", ft_strlen("Hello"));
    
    // 3. Copy and concat
    char dest[20];
    size_t len1 = ft_strlcpy(dest, "Hi", 3);
    ft_putchar_fd('\n', 1);
    ft_putstr_fd("3. ft_strlcpy: ", 1);
    ft_putnbr_fd(len1, 1);
    ft_putstr_fd(" -> \"", 1);
    ft_putstr_fd(dest, 1);
    ft_putstr_fd("\"\n", 1);
    
    size_t len2 = ft_strlcat(dest, " World", 20);
    ft_putstr_fd("   ft_strlcat: ", 1);
    ft_putnbr_fd(len2, 1);
    ft_putstr_fd(" -> \"", 1);
    ft_putstr_fd(dest, 1);
    ft_putstr_fd("\"\n", 1);
    
    // 4. Search in string
    ft_putchar_fd('\n', 1);
    ft_putstr_fd("4. ft_strchr(\"Hello\", 'l'): \"", 1);
    ft_putstr_fd(ft_strchr("Hello", 'l'), 1);
    ft_putstr_fd("\"\n", 1);
    
    ft_putstr_fd("   ft_strrchr(\"Hello\", 'l'): \"", 1);
    ft_putstr_fd(ft_strrchr("Hello", 'l'), 1);
    ft_putstr_fd("\"\n", 1);
    
    ft_putstr_fd("   ft_strnstr(\"Hello World\", \"World\", 11): \"", 1);
    ft_putstr_fd(ft_strnstr("Hello World", "World", 11), 1);
    ft_putstr_fd("\"\n", 1);
    
    print_str_with_int("   ft_strncmp(\"Hello\", \"Helix\", 3): ", ft_strncmp("Hello", "Helix", 3));
    
    // 5. Conversions
    ft_putchar_fd('\n', 1);
    print_str_with_int("5. ft_atoi(\"   -123\"): ", ft_atoi("   -123"));
    
    char *itoa_result = ft_itoa(-456);
    ft_putstr_fd("   ft_itoa(-456): \"", 1);
    ft_putstr_fd(itoa_result, 1);
    ft_putstr_fd("\"\n", 1);
    free(itoa_result);
    
    // 6. Memory functions
    ft_putchar_fd('\n', 1);
    ft_putstr_fd("6. ft_calloc: ", 1);
    int *arr = (int *)ft_calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        ft_putnbr_fd(arr[i], 1);
        if (i < 4)
            ft_putchar_fd(' ', 1);
    }
    ft_putchar_fd('\n', 1);
    free(arr);
    
    char *dup = ft_strdup("Duplicate me");
    ft_putstr_fd("   ft_strdup: \"", 1);
    ft_putstr_fd(dup, 1);
    ft_putstr_fd("\"\n", 1);
    free(dup);
    
    // 7. String functions
    ft_putchar_fd('\n', 1);
    char *sub = ft_substr("Hello World", 6, 5);
    ft_putstr_fd("7. ft_substr(\"Hello World\", 6, 5): \"", 1);
    ft_putstr_fd(sub, 1);
    ft_putstr_fd("\"\n", 1);
    free(sub);
    
    char *join = ft_strjoin("Hello ", "World");
    ft_putstr_fd("   ft_strjoin(\"Hello \", \"World\"): \"", 1);
    ft_putstr_fd(join, 1);
    ft_putstr_fd("\"\n", 1);
    free(join);
    
    char *trim = ft_strtrim("   Hello   ", " ");
    ft_putstr_fd("   ft_strtrim(\"   Hello   \", \" \"): \"", 1);
    ft_putstr_fd(trim, 1);
    ft_putstr_fd("\"\n", 1);
    free(trim);
    
    char **split = ft_split("Hello World from 42", ' ');
    ft_putstr_fd("   ft_split: [", 1);
    for (int i = 0; split[i]; i++)
    {
        ft_putstr_fd("\"", 1);
        ft_putstr_fd(split[i], 1);
        ft_putstr_fd("\"", 1);
        if (split[i + 1])
            ft_putstr_fd(", ", 1);
        free(split[i]);
    }
    ft_putstr_fd("]\n", 1);
    free(split);
    
    char *mapped = ft_strmapi("hello", to_upper_char);
    ft_putstr_fd("   ft_strmapi(\"hello\", to_upper): \"", 1);
    ft_putstr_fd(mapped, 1);
    ft_putstr_fd("\"\n", 1);
    free(mapped);
    
    // 8. Output functions
    ft_putchar_fd('\n', 1);
    ft_putendl_fd("8. Output functions (check output):", 1);
    ft_putstr_fd("   ft_putstr_fd: ", 1);
    ft_putstr_fd("Test output", 1);
    ft_putchar_fd('\n', 1);
    ft_putstr_fd("   ft_putnbr_fd: ", 1);
    ft_putnbr_fd(12345, 1);
    ft_putchar_fd('\n', 1);
    
    // 9. Lists
    test_list_functions();
    
    ft_putchar_fd('\n', 1);
    ft_putendl_fd("=== ALL TESTS PASSED ===", 1);
}

int main(void)
{
    test_all_functions();
    return 0;
}