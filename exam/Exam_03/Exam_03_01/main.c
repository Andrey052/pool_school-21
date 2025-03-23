#include <stdio.h>
#include <math.h>

int main(void)
{
    double radius;
    if (scanf("%lf", &radius) != 1 || radius <= 0) {
        printf("n/a");
        return 0;
    }

    const double density = 21500; // Плотность платины в кг/м^3
    double volume = (4.0 / 3.0) * M_PI * pow(radius, 3); // Объем шара
    double mass = density * volume; // Масса шара
    double result = round(mass); // Округление до целого числа

    printf("%.0lf", result);

    return 0;
}