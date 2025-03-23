#include <stdio.h>

int main(void)
{
    int value = 1;
    double pi = 3.141; // Убраны кавычки вокруг числа 3.141, так как pi должно быть числом типа double, а не строкой.

    scanf("%d", &value);
    printf("%.2f", value * pi);

    return 0;
}