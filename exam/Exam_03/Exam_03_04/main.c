#include <stdio.h>

int main(void)
{
    int A, B, C;
    if (scanf("%d %d %d", &A, &B, &C) != 3) {
        printf("n/a");
        return 0;
    }

    // Проверяем, находится ли C строго между A и B
    int result = ((A < C && C < B) || (B < C && C < A)) ? 1 : 0;
    printf("%d", result);

    return 0;
}