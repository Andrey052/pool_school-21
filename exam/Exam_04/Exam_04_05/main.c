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

    number = abs(number); // Работаем с модулем числа
    int product = 1; // Инициализируем произведение
    int has_odd_digits = 0; // Флаг наличия нечетных цифр

    // Обрабатываем каждую цифру числа
    while (number > 0) {
        int digit = number % 10; // Извлекаем последнюю цифру
        if (digit % 2 != 0) { // Проверяем, является ли цифра нечетной
            product *= digit; // Умножаем произведение на нечетную цифру
            has_odd_digits = 1; // Устанавливаем флаг
        }
        number /= 10; // Убираем последнюю цифру
    }

    // Если нечетных цифр не было, выводим 0
    if (!has_odd_digits) {
        product = 0;
    }

    // Выводим результат
    printf("%d", product);

    return 0;
}