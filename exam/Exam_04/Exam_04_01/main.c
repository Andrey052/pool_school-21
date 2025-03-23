#include <stdio.h>

// Функция для вычисления факториала числа
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Функция для вычисления биномиального коэффициента C(n, k)
unsigned long long binomial_coefficient(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n < 0) {
        // Проверка на корректность ввода
        return 0;
    }

    // Вычисляем и выводим биномиальные коэффициенты для k = 0..n
    for (int k = 0; k <= n; k++) {
        printf("%llu", binomial_coefficient(n, k));
        if (k < n) {
            printf(" ");
        }
    }

    return 0;
}
