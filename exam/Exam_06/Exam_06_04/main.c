#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    if (scanf("%d", &N) != 1 || N <= 0)
    {
        // Проверка на корректность порядка матрицы
        printf("n/a");
        return 0;
    }

    // Выделение памяти для матрицы
    int **matrix = (int **)malloc(N * sizeof(int *));
    if (matrix == NULL)
    {
        printf("n/a");
        return 0;
    }
    for (int i = 0; i < N; i++)
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

    // Заполнение матрицы по спирали
    int value = 1;
    int top = 0, bottom = N - 1, left = 0, right = N - 1;

    while (top <= bottom && left <= right)
    {
        // Заполнение верхней строки слева направо
        for (int i = left; i <= right; i++)
        {
            matrix[top][i] = value++;
        }
        top++;

        // Заполнение правого столбца сверху вниз
        for (int i = top; i <= bottom; i++)
        {
            matrix[i][right] = value++;
        }
        right--;

        // Заполнение нижней строки справа налево
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                matrix[bottom][i] = value++;
            }
            bottom--;
        }

        // Заполнение левого столбца снизу вверх
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                matrix[i][left] = value++;
            }
            left++;
        }
    }

    // Вывод матрицы
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d", matrix[i][j]);
            if (j < N - 1)
            {
                printf(" ");
            }
        }
        if (i < N - 1)
        {
            printf("\n");
        }
    }

    // Освобождение памяти
    for (int i = 0; i < N; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}