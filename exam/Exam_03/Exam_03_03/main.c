#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int number;
    scanf("%d", &number);

    // Извлекаем цифры
    int sign = (number < 0) ? -1 : 1; // Определяем знак числа
    number = abs(number); // Работаем с модулем числа
    int first_digit = number / 100; // Первая цифра
    int second_digit = (number / 10) % 10; // Вторая цифра
    int third_digit = number % 10; // Третья цифра

    // Меняем первую и третью цифры местами
    int swapped_number = sign * (third_digit * 100 + second_digit * 10 + first_digit);

    // Выводим результат с учетом ведущих нулей
    printf("%03d", swapped_number);

    return 0;
}