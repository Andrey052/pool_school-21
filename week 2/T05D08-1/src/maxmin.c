#include <stdio.h>

void maxmin(int prob1, int prob2, int prob3, int *max, int *min);

/* Find a max & min probabilities */
int main()
{
    int x, y, z;

    // Считываем три целых числа
    if (scanf("%d %d %d", &x, &y, &z) != 3)
    {
        printf("n/a\n");
    }
    else
    {
        int max, min;

        // Вызов функции для нахождения максимума и минимума
        maxmin(x, y, z, &max, &min);

        // Вывод результатов
        printf("%d %d\n", max, min);
    }

    return 0;
}

/* Эта функция должна остаться неизменной! */
void maxmin(int prob1, int prob2, int prob3, int *max, int *min)
{
    *max = *min = prob1;
    if (prob2 > *max)
        *max = prob2;
    if (prob2 < *min)
        *min = prob2;
    if (prob3 > *max)
        *max = prob3;
    if (prob3 < *min)
        *min = prob3;
}