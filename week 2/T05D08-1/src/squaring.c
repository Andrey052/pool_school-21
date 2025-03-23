#include <stdio.h>
#include <stdlib.h>

// Функция для возведения элементов массива в квадрат
void square_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = array[i] * array[i]; // Возведение элемента в квадрат
    }
}

// Функция для вывода массива
void print_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i > 0)
        { // Добавляем пробелы между элементами
            printf(" ");
        }
        printf("%d", array[i]); // Выводим элемент массива
    }
    printf("\n"); // Переход на новую строку после вывода всех элементов
}

int main()
{
    int size;

    // Чтение количества элементов
    if (scanf("%d", &size) != 1 || size <= 0)
    {
        printf("n/a\n");
        return 0;
    }

    // Выделение памяти под массив
    int *array = (int *)malloc(size * sizeof(int)); // Убедимся, что выделение прошло успешно
    if (array == NULL)
    {
        printf("n/a\n");
        return 0;
    }

    // Чтение элементов массива
    for (int i = 0; i < size; i++)
    {
        if (scanf("%d", &array[i]) != 1)
        {                // Читаем элементы массива
            free(array); // Очищаем память перед выходом
            printf("n/a\n");
            return 0;
        }
    }

    // Проверяем, есть ли лишние символы после ввода
    char c;
    while ((c = getchar()) != EOF && c != '\n')
        ; // Пропускаем все символы до конца строки

    // Возведение каждого элемента массива в квадрат
    square_array(array, size);

    // Выводим преобразованный массив
    print_array(array, size);

    // Освобождаем выделенную память
    free(array);

    return 0;
}