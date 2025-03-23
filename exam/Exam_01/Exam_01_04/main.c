#include <stdio.h>

int main(void)
{
    int left = 2, right = 1; // Удалено лишнее ключевое слово int перед right = 1, так как это синтаксическая ошибка.

    scanf("%d %d", &left, &right);
    printf("%d", left * right);

    return 0;
}