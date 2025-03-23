#include <stdio.h>
#include <stdlib.h>

int *input(int *a, int *length, int *f);
void output(int *a, int length, int f);
void sort(int *a, int length);

int main() {
    int *p = 0;
    int flag = 1;
    int length = 0;
    p = input(p, &length, &flag);
    if (flag == 1) {
        sort(p, length);
    }
    output(p, length, flag);
    return 0;
}

int *input(int *buffer, int *length, int *f) {
    if (scanf("%d", length) != 1 && getchar() != '\n') {
        *f = 0;
        *length = 1;
    } else {
        buffer = malloc((*length) * sizeof(int));
        for (int *p = buffer; p - buffer < *length; p++) {
            if (scanf("%d", p) != 1) {
                *f = 0;
            }
        }

        if (getchar() != '\n') {
            *f = 0;
        }
    }
    return buffer;
}

void output(int *a, int length, int f) {
    if (f == 1) {
        for (int *p = a; p - a < length; p++) {
            printf("%d ", *p);
        }
    } else {
        printf("n/a");
    }
    free(a);
}

void sort(int *a, int length) {
    for (int *i = a; i < length + a; i++) {
        for (int *j = a; j < length + a - 1; j++) {
            if (*j > *(j + 1)) {
                int tmp = *j;
                *j = *(j + 1);
                *(j + 1) = tmp;
            }
        }
    }
}
