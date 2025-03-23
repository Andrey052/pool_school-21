#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int capacity = 10;
    int size = 0;
    int *sequence = (int *)malloc(capacity * sizeof(int));

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

    // Вывод элементов в заданном порядке
    for (int i = 0; i < size / 2; i++)
    {
        printf("%d ", sequence[i]);           // Первый элемент
        printf("%d", sequence[size - 1 - i]); // Последний элемент
        if (i < size / 2 - 1)
        {
            printf(" "); // Пробел между парами, кроме последней
        }
    }

    // Если количество элементов нечетное, выводим средний элемент
    if (size % 2 != 0)
    {
        if (size > 1)
        {
            printf(" "); // Пробел перед средним элементом
        }
        printf("%d", sequence[size / 2]);
    }

    // Освобождение памяти
    free(sequence);

    return 0;
}