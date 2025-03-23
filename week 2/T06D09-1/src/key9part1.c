#include <stdio.h>
#define NMAX 10

void input(int *buffer, int *length, int *f);
void output(int *buffer, int length, int *f, int s);
int sum_numbers(int *buffer, int length, int *f);
int find_numbers(int *buffer, int length, int number, int *numbers);

int main() {
    int f = 1;
    int n, data[NMAX], data1[NMAX];
    input(data, &n, &f);
    int summ = 0;
    if (f == 1) {
        summ = sum_numbers(data, n, &f);
        n = find_numbers(data, n, summ, data1);
    }

    output(data1, n, &f, summ);

    return 0;
}

void input(int *buffer, int *length, int *f) {
    if (scanf("%d", length) != 1 && getchar() != '\n' || *length > NMAX) {
        *f = 0;
        *length = 1;
    } else if (*length > NMAX) {
        *f = 0;
        *length = 0;
    } else {
        for (int *p = buffer; p - buffer < *length; p++) {
            if (scanf("%d", p) != 1) {
                *f = 0;
            }
        }
        if (getchar() != '\n') {
            *f = 0;
        }
    }
}

void output(int *buffer, int length, int *f, int s) {
    if (*f == 1) {
        printf("%d\n", s);
        for (int *p = buffer; p - buffer < length; p++) {
            printf("%d ", *p);
        }
        printf("\n");
    } else {
        printf("n/a\n");
    }
}

int sum_numbers(int *buffer, int length, int *f) {
    int sum = 0;
    *f = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
            *f = 1;
        }
    }
    return sum;
}

int find_numbers(int *buffer, int length, int number, int *numbers) {
    int i = 0;
    for (int *j = buffer; j - buffer < length; j++) {
        if (*j != 0) {
            if (number % (*j) == 0) {
                numbers[i] = (*j);
                i++;
            }
        }
    }
    return i;
}
