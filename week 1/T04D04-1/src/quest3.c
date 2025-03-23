#include <math.h>
#include <stdio.h>

int fibonacci(int number_fi);

int main() {
  int number;
  if (scanf("%d", &number) != 2) {
    if (number == 0) {
      printf("0\n");
    } else if (number > 0) {
      printf("%d\n", fibonacci(number));
    } else {
      printf("%d\n", pow((-1), (number + 1)) * fibonacci(number));
    }

  } else {
    printf("n/a\n");
  }
  return 0;
}

int fibonacci(int number_fi) {
  if (number_fi == 1 || number_fi == 2) {
    return 1;
  }
  return (fibonacci(number_fi - 1) + fibonacci(number_fi - 2));
}