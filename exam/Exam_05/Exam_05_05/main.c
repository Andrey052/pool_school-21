#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int capacity = 10;                                     // Начальная емкость массива
    int size = 0;                                          // Текущий размер последовательности
    int *sequence = (int *)malloc(capacity * sizeof(int)); // Динамический массив для хранения последовательности

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

    // Вывод элементов в обратном порядке
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d", sequence[i]);
        if (i > 0)
        {
            printf(" "); // Пробел между элементами, кроме последнего
        }
    }

    // Освобождение памяти
    free(sequence);

    return 0;
}