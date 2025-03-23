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

    // Выделение памяти для исходной матрицы
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

    // Чтение исходной матрицы
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

    // Выделение памяти для повернутой матрицы
    int **rotated_matrix = (int **)malloc(N * sizeof(int *));
    if (rotated_matrix == NULL)
    {
        printf("n/a");
        for (int i = 0; i < M; i++)
        {
            free(matrix[i]);
        }
        free(matrix);
        return 0;
    }
    for (int i = 0; i < N; i++)
    {
        rotated_matrix[i] = (int *)malloc(M * sizeof(int));
        if (rotated_matrix[i] == NULL)
        {
            printf("n/a");
            for (int j = 0; j < i; j++)
            {
                free(rotated_matrix[j]);
            }
            free(rotated_matrix);
            for (int k = 0; k < M; k++)
            {
                free(matrix[k]);
            }
            free(matrix);
            return 0;
        }
    }

    // Поворот матрицы на 90 градусов по часовой стрелке
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            rotated_matrix[j][M - 1 - i] = matrix[i][j];
        }
    }

    // Вывод повернутой матрицы
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d", rotated_matrix[i][j]);
            if (j < M - 1)
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
    for (int i = 0; i < M; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    for (int i = 0; i < N; i++)
    {
        free(rotated_matrix[i]);
    }
    free(rotated_matrix);

    return 0;
}