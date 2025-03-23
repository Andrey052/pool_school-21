#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int n;
  if (scanf("%d", &n) != 1 || n <= 0)
  {
    // Проверка на корректность размерности
    printf("n/a");
    return 0;
  }

  // Выделяем память для векторов
  int *vector1 = (int *)malloc(n * sizeof(int));
  int *vector2 = (int *)malloc(n * sizeof(int));

  if (vector1 == NULL || vector2 == NULL)
  {
    // Проверка на успешное выделение памяти
    printf("n/a");
    free(vector1); // Освобождаем память, если одна из выделений не удалась
    free(vector2);
    return 0;
  }

  // Чтение координат первого вектора
  for (int i = 0; i < n; i++)
  {
    if (scanf("%d", &vector1[i]) != 1)
    {
      // Проверка на корректность ввода
      printf("n/a");
      free(vector1); // Освобождаем память перед выходом
      free(vector2);
      return 0;
    }
  }

  // Чтение координат второго вектора
  for (int i = 0; i < n; i++)
  {
    if (scanf("%d", &vector2[i]) != 1)
    {
      // Проверка на корректность ввода
      printf("n/a");
      free(vector1); // Освобождаем память перед выходом
      free(vector2);
      return 0;
    }
  }

  // Вычисление скалярного произведения
  int scalar_product = 0;
  for (int i = 0; i < n; i++)
  {
    scalar_product += vector1[i] * vector2[i];
  }

  // Вывод результата
  printf("%d", scalar_product);

  // Освобождение памяти
  free(vector1);
  free(vector2);

  return 0;
}