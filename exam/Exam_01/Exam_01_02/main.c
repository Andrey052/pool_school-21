#include <stdio.h>

int main(void)
{
    int x1 = 1, x2 = 2; // Добавлена запятая между объявлениями переменных x1 и x2.

    scanf("%d %d", &x1, &x2);
    printf("%d", x1 * x2);

    return 0;
}