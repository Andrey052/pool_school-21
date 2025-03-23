#include <stdio.h>
#include <stdlib.h>

// Функция для проверки, существует ли число в массиве
int contains(int *arr, int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return 1; // Число уже существует
        }
    }
    return 0; // Число не существует
}

int main(void)
{
    int capacity = 10;                                     // Начальная емкость динамического массива
    int size = 0;                                          // Текущий размер последовательности
    int *sequence = (int *)malloc(capacity * sizeof(int)); // Динамический массив для последовательности

    if (sequence == NULL)
    {
        // Проверка на успешное выделение памяти
        printf("n/a");
        return 0;
    }

    // Чтение последовательности
    while (1)
    {
        int number;
        if (scanf("%d", &number) != 1)
        {
            // Проверка на корректность ввода
            printf("n/a");
            free(sequence);
            return 0;
        }
        if (number == -1)
        {
            // Конец последовательности
            break;
        }
        if (number < 0)
        {
            // Проверка на неотрицательные числа
            printf("n/a");
            free(sequence);
            return 0;
        }
        if (size >= capacity)
        {
            // Увеличиваем емкость массива, если необходимо
            capacity *= 2;
            sequence = (int *)realloc(sequence, capacity * sizeof(int));
            if (sequence == NULL)
            {
                printf("n/a");
                return 0;
            }
        }
        sequence[size++] = number; // Добавляем число в последовательность
    }

    // Массив для хранения уникальных элементов
    int *result = (int *)malloc(size * sizeof(int));
    int result_size = 0; // Размер массива с уникальными элементами

    if (result == NULL)
    {
        // Проверка на успешное выделение памяти
        printf("n/a");
        free(sequence);
        return 0;
    }

    // Удаление повторяющихся элементов
    for (int i = 0; i < size; i++)
    {
        if (!contains(result, result_size, sequence[i]))
        {
            result[result_size++] = sequence[i]; // Добавляем уникальный элемент
        }
    }

    // Вывод результата
    for (int i = 0; i < result_size; i++)
    {
        printf("%d", result[i]);
        if (i < result_size - 1)
        {
            printf(" "); // Пробел между элементами, кроме последнего
        }
    }

    // Освобождение памяти
    free(sequence);
    free(result);

    return 0;
}