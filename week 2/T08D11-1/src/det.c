#include <stdio.h>
#include <stdlib.h>

double Determinant(int** mas, int m);
int** GetMatr(int** mas, int rows, int cols, int row, int col);
void scanf_r_c(int* n, int* m, int* f);
int** Input(int rows, int cols, int* f);
void Free(int** mas, int rows);
void output_error(void);

int main() {
    int n, m, f = 1;
    int** mas;
    scanf_r_c(&n, &m, &f);
    if (f == 1) {
        mas = Input(n, m, &f);
    }
    if (f == 1) {
        double det = Determinant(mas, m);
        printf("%.6lf", det);
    } else {
        output_error();
    }
    return 0;
}

void scanf_r_c(int* n, int* m, int* f) {
    if ((scanf("%d %d", n, m) != 2 && getchar() != '\n') || (*m < 1 || *n < 1 || *n != *m)) {
        *f = 0;
        *n = 1;
        *m = 1;
    }
}

int** Input(int rows, int cols, int* f) {
    int** p;
    p = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows && *f == 1; i++) {
        p[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &p[i][j]) != 1) {
                *f = 0;
            }
        }
        if (getchar() != '\n') {
            *f = 0;
        }
    }
    return p;
}

int** GetMatr(int** mas, int rows, int cols, int row, int col) {
    int di, dj;
    int** p = (int**)malloc((rows - 1) * sizeof(int*));
    di = 0;
    for (int i = 0; i < rows - 1; i++) {
        if (i == row) di = 1;
        dj = 0;
        p[i] = (int*)malloc((cols - 1) * sizeof(int));
        for (int j = 0; j < cols - 1; j++) {
            if (j == col) dj = 1;
            p[i][j] = mas[i + di][j + dj];
        }
    }
    return p;
}

double Determinant(int** mas, int m) {
    int k;
    int** p = 0;
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

void Free(int** mas, int rows) {
    for (int i = 0; i < rows; i++) free(mas[i]);
    free(mas);
}

void output_error(void) { printf("n/a"); }