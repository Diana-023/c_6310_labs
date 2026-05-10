#include "libft.h"
#include <stdarg.h>

// Коды метрик
#define METRIC_MIN 0
#define METRIC_MAX 1
#define METRIC_SUM 2
#define METRIC_AVG 3

// Тип для указателя на функцию
typedef int (*t_metric_func)(int count, ...);

// Функция для подсчёта минимума
int min_metric(int count, ...) {
    va_list args;
    va_start(args, count);
    
    if (count == 0) {
        va_end(args);
        return 0;
    }
    
    int min = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int num = va_arg(args, int);
        if (num < min)
            min = num;
    }
    
    va_end(args);
    return min;
}

// Функция для подсчёта максимума
int max_metric(int count, ...) {
    va_list args;
    va_start(args, count);
    
    if (count == 0) {
        va_end(args);
        return 0;
    }
    
    int max = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int num = va_arg(args, int);
        if (num > max)
            max = num;
    }
    
    va_end(args);
    return max;
}

// Функция для подсчёта суммы
int sum_metric(int count, ...) {
    va_list args;
    va_start(args, count);
    
    int sum = 0;
    for (int i = 0; i < count; i++)
        sum += va_arg(args, int);
    
    va_end(args);
    return sum;
}

// Функция для подсчёта среднего
int avg_metric(int count, ...) {
    va_list args;
    va_start(args, count);
    
    if (count == 0) {
        va_end(args);
        return 0;
    }
    
    int sum = 0;
    for (int i = 0; i < count; i++)
        sum += va_arg(args, int);
    
    va_end(args);
    return sum / count;  // Целочисленное деление (округление вниз)
}

// Функция для выбора метрики по имени
int get_metric_code(char *name) {
    if (ft_strncmp(name, "min", 4) == 0)
        return METRIC_MIN;
    if (ft_strncmp(name, "max", 4) == 0)
        return METRIC_MAX;
    if (ft_strncmp(name, "sum", 4) == 0)
        return METRIC_SUM;
    if (ft_strncmp(name, "avg", 4) == 0)
        return METRIC_AVG;
    return -1;
}

// Главная вариативная функция compute
int compute(int metric, int count, ...) {
    va_list args;
    va_start(args, count);
    
    int result = 0;
    
    if (metric == METRIC_MIN)
        result = min_metric(count, args);
    else if (metric == METRIC_MAX)
        result = max_metric(count, args);
    else if (metric == METRIC_SUM)
        result = sum_metric(count, args);
    else if (metric == METRIC_AVG)
        result = avg_metric(count, args);
    
    va_end(args);
    return result;
}

int main(int argc, char **argv) {
    // Проверка количества аргументов
    if (argc < 3) {
        ft_putstr_fd("Ошибка: недостаточно аргументов\n", 2);
        ft_putstr_fd("Использование: ./stats <метрика> [числа...]\n", 2);
        ft_putstr_fd("Метрики: min, max, sum, avg\n", 2);
        return 1;
    }
    
    // Получаем код метрики
    int metric_code = get_metric_code(argv[1]);
    if (metric_code == -1) {
        ft_putstr_fd("Ошибка: неизвестная метрика\n", 2);
        ft_putstr_fd("Доступные метрики: min, max, sum, avg\n", 2);
        return 1;
    }
    
    // Количество чисел
    int count = argc - 2;
    if (count == 0) {
        ft_putstr_fd("Ошибка: список чисел пуст\n", 2);
        return 1;
    }
    
    // Создаём массив чисел (опционально, можно передавать напрямую в compute)
    // Но для вариативной функции нужно передавать числа по одному
    // Используем массив указателей на функции для демонстрации
    t_metric_func metrics[] = {min_metric, max_metric, sum_metric, avg_metric};
    
    // Преобразуем строки в числа и сохраняем в массив
    int *numbers = (int *)ft_calloc(count + 1, sizeof(int));
    if (!numbers) {
        ft_putstr_fd("Ошибка: не удалось выделить память\n", 2);
        return 1;
    }
    
    for (int i = 0; i < count; i++) {
        numbers[i] = ft_atoi(argv[i + 2]);
    }
    
    // Вызываем нужную функцию через указатель
    int result;
    if (metric_code == METRIC_MIN)
        result = metrics[METRIC_MIN](count, numbers[0], numbers[1], numbers[2], 
                                      numbers[3], numbers[4], numbers[5], numbers[6], 
                                      numbers[7], numbers[8], numbers[9]);
    else if (metric_code == METRIC_MAX)
        result = metrics[METRIC_MAX](count, numbers[0], numbers[1], numbers[2], 
                                      numbers[3], numbers[4], numbers[5], numbers[6], 
                                      numbers[7], numbers[8], numbers[9]);
    else if (metric_code == METRIC_SUM)
        result = metrics[METRIC_SUM](count, numbers[0], numbers[1], numbers[2], 
                                      numbers[3], numbers[4], numbers[5], numbers[6], 
                                      numbers[7], numbers[8], numbers[9]);
    else
        result = metrics[METRIC_AVG](count, numbers[0], numbers[1], numbers[2], 
                                      numbers[3], numbers[4], numbers[5], numbers[6], 
                                      numbers[7], numbers[8], numbers[9]);
    
    // Выводим результат
    ft_putnbr_fd(result, 1);
    ft_putchar_fd('\n', 1);
    
    // Освобождаем память
    free(numbers);
    
    return 0;
}