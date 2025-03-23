#include <stdio.h>

int main(void)
{
    int x = 0;
    double pi = 3.141; // Добавлен тип double для переменной pi, так как она содержит дробное значение.

    scanf("%d", &x);
    printf("%.2f", pi * x);

    return 0;
}