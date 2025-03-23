#include <stdio.h>
#define NMAX 10

void input(int *buffer, int *length, int *f, int *count);
void output(int *buffer, int length, int *f);
void move(int *buffer, int n, int count);

int main() {
    int f = 1;
    int n, data[NMAX], count;
    input(data, &n, &f, &count);
    if (f == 1) {
        move(data, n, count);
    }

    output(data, n, &f);

    return 0;
}

void input(int *buffer, int *length, int *f, int *count) {
    if (scanf("%d", length) != 1 && getchar() != '\n') {
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
        if (scanf("%d", count) != 1 && getchar() != '\n') {
            *f = 0;
            *count = 0;
        }
    }
}

void output(int *buffer, int length, int *f) {
    if (*f == 1) {
        for (int *p = buffer; p - buffer < length; p++) {
            printf("%d ", *p);
        }
        printf("\n");
    } else {
        printf("n/a\n");
    }
}

void move(int *buffer, int n, int count) {
    if (count > 0) {
        for (int j = 0; j < count; j++) {
            int first = buffer[0];
            for (int *p = buffer; p - buffer < n - 1; p++) {
                *p = *(p + 1);
            }
            buffer[n - 1] = first;
        }
    } else if (count < 0) {
        for (int j = 0; j < -count; j++) {
            int last = buffer[n - 1];
            int med = buffer[0];
            int med1 = 0;
            for (int *p = buffer + 1; p - buffer < n; p++) {
                med1 = *p;
                *p = med;
                med = med1;
            }
            buffer[0] = last;
        }
    }
}