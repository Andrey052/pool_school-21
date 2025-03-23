#include <stdio.h>
#include <stdlib.h>

#define LEN 100

void output(int n, int m, int **buffer, int *f);
void output_error(void);
void din_first(int *f);
void input(int coll, int rows, int **buffer, int *f);
void scanf_r_c(int *n, int *m, int *f);
void clear(int **buffer, int n);
void summ(int **buffer1, int **buffer2, int n, int m);
void mult(int **buff1, int **buff2, int n1, int m1, int **res);
void transpon(int **buff, int n, int m, int **res);

int main() {
    int flag = 1;
    din_first(&flag);
    return 0;
}

void clear(int **buffer, int n) {
    for (int i = 0; i < n; i++) {
        free(buffer[i]);
    }
    free(buffer);
}

void scanf_r_c(int *n, int *m, int *f) {  // n - строка m - столбец
    if ((scanf("%d %d", n, m) != 2 && getchar() != '\n') || (*m > 100 || *n > 100)) {
        *f = 0;
        *n = 1;
        *m = 1;
        output_error();
    }
}

void input(int coll, int rows, int **buffer, int *f) {
    for (int i = 0; i < coll; i++) {
        for (int j = 0; j < rows; j++) {
            scanf("%d", &buffer[i][j]);
        }
        if (getchar() != '\n') {
            *f = 0;
        }
    }
}

void din_first(int *f) {
    int n1 = 0, m1 = 0, dir = 0, n2 = 0, m2 = 0;
    int **data1, **data2, **res;
    if (scanf("%d", &dir) != 1 && getchar() != '\n') {
        *f = 0;
    } else {
        if (*f != 0) {
            switch (dir) {
                case 1:
                    //сумма
                    scanf_r_c(&n1, &m1, f);
                    data1 = (int **)malloc(n1 * sizeof(int *));
                    for (int i = 0; i < n1; i++) {
                        data1[i] = (int *)malloc(m1 * sizeof(int));
                    }
                    input(n1, m1, data1, f);
                    scanf_r_c(&n2, &m2, f);
                    data2 = (int **)malloc(n2 * sizeof(int *));
                    for (int i = 0; i < n2; i++) {
                        data2[i] = (int *)malloc(m2 * sizeof(int));
                    }
                    input(n2, m2, data2, f);
                    if (n1 == n2 && m1 == m2) {
                        summ(data1, data2, n1, m1);
                        output(n1, m1, data1, f);
                    }
                    clear(data1, n1);
                    clear(data2, n2);
                    break;
                case 2:
                    //умножение
                    scanf_r_c(&n1, &m1, f);
                    data1 = (int **)malloc(n1 * sizeof(int *));
                    for (int i = 0; i < n1; i++) {
                        data1[i] = (int *)malloc(m1 * sizeof(int));
                    }
                    input(n1, m1, data1, f);
                    scanf_r_c(&n2, &m2, f);
                    data2 = (int **)malloc(n2 * sizeof(int *));
                    for (int i = 0; i < n2; i++) {
                        data2[i] = (int *)malloc(m2 * sizeof(int));
                    }
                    input(n2, m2, data2, f);
                    res = (int **)malloc(n1 * sizeof(int *));
                    for (int i = 0; i < n1; i++) {
                        res[i] = (int *)malloc(m2 * sizeof(int));
                        for (int j = 0; j < n2; j++) {
                            res[i][j] = 0;
                        }
                    }
                    if (n1 == m2 || n2 == m1) {
                        mult(data1, data2, n1, m1, res);
                        output(n1, m2, res, f);
                    }
                    clear(data1, n1);
                    clear(data2, n2);
                    clear(res, n1);
                    break;
                case 3:
                    // транспонирование
                    scanf_r_c(&n1, &m1, f);
                    data1 = (int **)malloc(n1 * sizeof(int *));
                    for (int i = 0; i < n1; i++) {
                        data1[i] = (int *)malloc(m1 * sizeof(int));
                    }
                    input(n1, m1, data1, f);
                    res = (int **)malloc(m1 * sizeof(int *));
                    for (int i = 0; i < m1; i++) {
                        res[i] = (int *)malloc(n1 * sizeof(int));
                        for (int j = 0; j < n1; j++) {
                            res[i][j] = 0;
                        }
                    }
                    transpon(data1, n1, m1, res);
                    output(m1, n1, res, f);
                    clear(data1, n1);
                    clear(res, n1);
                    break;
                default:
                    output_error();
            }
        }
    }
}

void output(int n, int m, int **buffer, int *f) {
    if (*f == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d", buffer[i][j]);
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

void output_error(void) { printf("n/a"); }

void summ(int **buffer1, int **buffer2, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            buffer1[i][j] += buffer2[i][j];
        }
    }
}

void mult(int **buff1, int **buff2, int n, int m, int **res) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                res[i][j] += buff1[i][k] * buff2[k][j];
            }
        }
    }
}

void transpon(int **buff, int n, int m, int **res) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = buff[j][i];
        }
    }
}
