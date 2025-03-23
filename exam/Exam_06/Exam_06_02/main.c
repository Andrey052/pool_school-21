#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int M, N;
    if (scanf("%d %d", &M, &N) != 2 || M <= 0 || N <= 0)
    {
        // Проверка на корректность размеров матрицы
        printf("n/a");
        return 0;
    }

    // Выделение памяти для матрицы
    int **matrix = (int **)malloc(M * sizeof(int *));
    if (matrix == NULL)
    {
        printf("n/a");
        return 0;
    }
    for (int i = 0; i < M; i++)
    {
        matrix[i] = (int *)malloc(N * sizeof(int));
        if (matrix[i] == NULL)
        {
            printf("n/a");
            for (int j = 0; j < i; j++)
            {
                free(matrix[j]);
            }
            free(matrix);
            return 0;
        }
    }

    // Чтение матрицы
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (scanf("%d", &matrix[i][j]) != 1)
            {
                // Проверка на корректность ввода
                printf("n/a");
                for (int k = 0; k < M; k++)
                {
                    free(matrix[k]);
                }
                free(matrix);
                return 0;
            }
        }
    }

    // Поиск минимального и максимального элементов
    int min_value = matrix[0][0];
    int max_value = matrix[0][0];
    int min_row = 0;
    int max_row = 0;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (matrix[i][j] < min_value)
            {
                min_value = matrix[i][j];
                min_row = i;
            }
            if (matrix[i][j] > max_value)
            {
                max_value = matrix[i][j];
                max_row = i;
            }
        }
    }

    // Меняем строки местами
    int *temp = matrix[min_row];
    matrix[min_row] = matrix[max_row];
    matrix[max_row] = temp;

    // Вывод результата
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d", matrix[i][j]);
            if (j < N - 1)
            {
                printf(" ");
            }
        }
        if (i < M - 1)
        {
            printf("\n");
        }
    }

    // Освобождение памяти
    for (int i = 0; i < M; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}