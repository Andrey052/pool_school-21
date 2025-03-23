#include "data_io.h"

#include <stdio.h>
#include <stdlib.h>

void input(double **data, int *n) {
    if (scanf("%d", n) != 1 && getchar() != '\n') {
        *n = 1;
    } else {
        *data = (double *)malloc(*n * sizeof(double *));
        for (int i = 0; i < *n; i++) {
            scanf("%lf", &(*data)[i]);
        }
    }
}

void output(double *data, int n) {
    for (double *p = data; p - data < n; p++) {
        printf("%lf", *p);
        if (p - data != n - 1) {
            printf(" ");
        }
    }
}