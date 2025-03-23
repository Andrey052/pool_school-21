#include <stdio.h>
#include <stdlib.h>

double Determinant(double** mas, int m);
double** GetMatr(double** mas, int rows, int cols, int row, int col);
void scanf_r_c(int* n, int* m, int* f);
double** Input(int rows, int cols, int* f);
void Free(double** mas, int rows);
void output_error(void);
void move(double** matrix, int n, int m, double** res, int k);
void output(double** matrix, int n, int m, int f);

int main() {
    int n, m, f = 1;
    double** mas;
    scanf_r_c(&n, &m, &f);
    double** result = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        result[i] = (double*)malloc(m * sizeof(double));
    }
    if (f == 1) {
        mas = Input(n, m, &f);
    }
    if (f == 1) {
        // move(mas, n, m, result, 4);
        double det = Determinant(mas, n);
        double det1 = 0;
        for (int i = 0; i < m - 1; i++) {
            move(mas, n, m, result, i);
            det1 = Determinant(result, n);
            printf("%.6lf", det1 / det);
            if (i != m - 2) {
                printf(" ");
            }
        }
    } else {
        output_error();
    }
    return 0;
}

void scanf_r_c(int* n, int* m, int* f) {
    if ((scanf("%d %d", n, m) != 2 && getchar() != '\n') || (*m < 1 || *n < 1 || *n != *(m + 1))) {
        *f = 0;
        *n = 1;
        *m = 1;
    }
}

double** Input(int rows, int cols, int* f) {
    double** p;
    p = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows && *f == 1; i++) {
        p[i] = (double*)malloc(cols * sizeof(double));
        for (int j = 0; j < cols; j++) {
            if (scanf("%lf", &p[i][j]) != 1) {
                *f = 0;
            }
        }
        if (getchar() != '\n') {
            *f = 0;
        }
    }
    return p;
}

double** GetMatr(double** mas, int rows, int cols, int row, int col) {
    int di = 0, dj = 0;
    double** p = (double**)malloc((rows - 1) * sizeof(double*));
    di = 0;
    for (int i = 0; i < rows - 1; i++) {
        if (i == row) di = 1;
        dj = 0;
        p[i] = (double*)malloc((cols - 1) * sizeof(double));
        for (int j = 0; j < cols - 1; j++) {
            if (j == col) dj = 1;
            p[i][j] = mas[i + di][j + dj];
        }
    }
    return p;
}

double Determinant(double** mas, int m) {
    int k;
    double** p = 0;
    double d = 0;
    // output(mas, m, m, 1);
    k = 1;
    if (m == 1) {
        d = mas[0][0];
        return (d);
    }
    if (m == 2) {
        d = mas[0][0] * mas[1][1] - (mas[1][0] * mas[0][1]);
        return (d);
    }
    if (m > 2) {
        for (int i = 0; i < m; i++) {
            p = GetMatr(mas, m, m, i, 0);
            d = d + k * mas[i][0] * Determinant(p, m - 1);
            k = -k;
        }
    }
    Free(p, m - 1);
    return (d);
}

void Free(double** mas, int rows) {
    for (int i = 0; i < rows; i++) free(mas[i]);
    free(mas);
}

void output_error(void) { printf("n/a"); }

void move(double** matrix, int n, int m, double** res, int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            res[i][j] = matrix[i][j];
        }
        res[i][k] = matrix[i][m - 1];
        for (int j = k + 1; j < m - 1; j++) {
            res[i][j] = matrix[i][j];
        }
    }
}

void output(double** matrix, int n, int m, int f) {
    if (f == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%.6lf", matrix[i][j]);
                if (j < m - 1) {
                    printf(" ");
                }
            }
            if (i < n - 1) {
                printf("\n");
            }
        }
    } else {
        printf("n/a");
    }
}