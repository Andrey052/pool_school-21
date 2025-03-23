#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int N;
  if (scanf("%d", &N) != 1 || N <= 0)
  {
    // Проверка на корректность размерности
    printf("n/a");
    return 0;
  }

  // Выделение памяти для матриц A, B и результата C
  int **A = (int **)malloc(N * sizeof(int *));
  int **B = (int **)malloc(N * sizeof(int *));
  int **C = (int **)malloc(N * sizeof(int *));

  if (A == NULL || B == NULL || C == NULL)
  {
    // Проверка на успешное выделение памяти
    printf("n/a");
    if (A)
      free(A);
    if (B)
      free(B);
    if (C)
      free(C);
    return 0;
  }

  for (int i = 0; i < N; i++)
  {
    A[i] = (int *)malloc(N * sizeof(int));
    B[i] = (int *)malloc(N * sizeof(int));
    C[i] = (int *)malloc(N * sizeof(int));
    if (A[i] == NULL || B[i] == NULL || C[i] == NULL)
    {
      // Проверка на успешное выделение памяти
      printf("n/a");
      for (int j = 0; j <= i; j++)
      {
        if (A[j])
          free(A[j]);
        if (B[j])
          free(B[j]);
        if (C[j])
          free(C[j]);
      }
      free(A);
      free(B);
      free(C);
      return 0;
    }
  }

  // Чтение матрицы A
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (scanf("%d", &A[i][j]) != 1)
      {
        // Проверка на корректность ввода
        printf("n/a");
        for (int k = 0; k < N; k++)
        {
          if (A[k])
            free(A[k]);
          if (B[k])
            free(B[k]);
          if (C[k])
            free(C[k]);
        }
        free(A);
        free(B);
        free(C);
        return 0;
      }
    }
  }

  // Чтение матрицы B
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (scanf("%d", &B[i][j]) != 1)
      {
        // Проверка на корректность ввода
        printf("n/a");
        for (int k = 0; k < N; k++)
        {
          if (A[k])
            free(A[k]);
          if (B[k])
            free(B[k]);
          if (C[k])
            free(C[k]);
        }
        free(A);
        free(B);
        free(C);
        return 0;
      }
    }
  }

  // Умножение матриц A и B
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      C[i][j] = 0; // Инициализация элемента матрицы C
      for (int k = 0; k < N; k++)
      {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  // Вывод матрицы C
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      printf("%d", C[i][j]);
      if (j < N - 1)
      {
        printf(" "); // Пробел между элементами строки
      }
    }
    if (i < N - 1)
    {
      printf("\n"); // Перенос строки после каждой строки матрицы
    }
  }

  // Освобождение памяти
  for (int i = 0; i < N; i++)
  {
    free(A[i]);
    free(B[i]);
    free(C[i]);
  }
  free(A);
  free(B);
  free(C);

  return 0;
}