#include <stdio.h>

int main(void)
{
    int first = 3, second = 4; // Удалено двоеточие после int, так как оно является синтаксической ошибкой.

    scanf("%d %d", &first, &second);
    printf("%d", first * second);

    return 0;
}