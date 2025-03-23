#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int number;
    if (scanf("%d", &number) != 1) {
        // Проверка на корректность ввода
        printf("n/a");
        return 0;
    }

    // Находим наибольшую цифру
    number = abs(number); // Работаем с модулем числа
    int max_digit = 0;
    while (number > 0) {
        int current_digit = number % 10;
        if (current_digit > max_digit) {
            max_digit = current_digit;
        }
        number /= 10;
    }

    // Выводим результат
    printf("%d", max_digit);

    return 0;
}