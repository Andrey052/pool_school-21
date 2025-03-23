#include <stdio.h>
#include <math.h>

int main(void)
{
    double radians;
    if (scanf("%lf", &radians) != 1) {
        printf("n/a");
        return 0;
    }

    double degrees = radians * 57.29; // Перевод радиан в градусы
    int result = (int)round(degrees); // Математическое округление

    printf("%d", result);

    return 0;
}