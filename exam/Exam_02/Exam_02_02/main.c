#include <stdio.h>

int main(void)
{
    int x = -21;

    scanf("%d", &x); // Добавлен оператор взятия адреса & перед переменной x в scanf, так как функция scanf требует указателя на переменную для записи значения.


    printf("%03d", x);

    return 0;
}