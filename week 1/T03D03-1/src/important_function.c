#include <math.h>
#include <stdio.h>

double f(double x) {
    return (7 * pow(10, -3) * pow(x, 4) + ((22.8 * pow(x, (1. / 3)) - 1000) * x + 3) / (x * x / 2) -
            x * (pow((10 + x), (2 / x))) - 1.01);
}

int main() {
    double a;
    scanf("%lf", &a);
    printf("%0.1lf", f(a));
    return 0;
}
