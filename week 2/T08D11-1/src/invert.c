#include <stdio.h>
#include <stdlib.h>

double Determinant(double** mas, int m);
double** GetMatr(double** mas, int rows, int cols, int row, int col);
void scanf_r_c(int* n, int* m, int* f);
double** Input(int rows, int cols, int* f);
void Free(double** mas, int rows);
void output_error(void);
double** Transpone(double** mas, int rows, int cols);
double** Mreverse(double** mas, int m, int* f);
void output(double** buffer, int n, int m, const int* f);

int main() {
    int n, m, f = 1;
    double** mas;
    scanf_r_c(&n, &m, &f);
    if (f == 1) {
        mas = Input(n, m, &f);
    }
    if (f == 1) {
        mas = Mreverse(mas, n, &f);
        output(mas, n, m, &f);
    } else {
        output_error();
    }
    // Free(mas, m);
    return 0;
}

void scanf_r_c(int* n, int* m, int* f) {
    if ((scanf("%d %d", n, m) != 2 && getchar() != '\n') || (*m < 1 || *n < 1 || *n != *m)) {
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
    // Free(p, cols);
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
    // Free(p, row);
    return p;
}

double Determinant(double** mas, int m) {
    int k;
    double** p = 0;
    double d = 0;
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

double** Mreverse(double** mas, int m, int* f) {
    double** rez = (double**)malloc(m * sizeof(double*));
    double det = Determinant(mas, m);
    for (int i = 0; i < m; i++) {
        rez[i] = (double*)malloc(m * sizeof(double));
        for (int j = 0; j < m; j++) {
            rez[i][j] = Determinant(GetMatr(mas, m, m, i, j), m - 1);
            if ((i + j) % 2 == 1) rez[i][j] = -rez[i][j];
            rez[i][j] = rez[i][j] / det;
        }
    }
    if (det == 0.0) {
        *f = 0;
        return 0;
    }
    // Free(rez, m);
    return Transpone(rez, m, m);
}

double** Transpone(double** mas, int rows, int cols) {
    double** rez;
    rez = (double**)malloc(cols * sizeof(double*));
    for (int i = 0; i < cols; i++) {
        rez[i] = (double*)malloc(rows * sizeof(double));
        for (int j = 0; j < rows; j++) rez[i][j] = mas[j][i];
    }
    return rez;
}

void output(double** buffer, int n, int m, const int* f) {
    if (*f == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%.6lf", buffer[i][j]);
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