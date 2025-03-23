#include <stdio.h>

int main(void)
{
    int a, b; // Заменено INT на int.
    a = b = 1;

    scanf("%d %d", &a, &b);
    printf("%d", a * b);

    return 0;
}