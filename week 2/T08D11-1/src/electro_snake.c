#include <stdio.h>
#include <stdlib.h>

/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);

void input(int **matrix, int n, int m, int *f);
void output(int **matrix, int n, int m, int f);
void scanf_r_c(int *n, int *m, int *f);
void sort_mat(int *buffer, int len);
void clear(int **buffer, int n);
void output_error(void);

int main() {
    int **matrix, **result;
    int n, m;
    int flag = 1;

    scanf_r_c(&n, &m, &flag);

    matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(m * sizeof(int));
    }
    result = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        result[i] = (int *)malloc(m * sizeof(int));
    }

    input(matrix, n, m, &flag);
    sort_vertical(matrix, n, m, result);
    output(result, n, m, flag);
    printf("\n");
    printf("\n");
    sort_horizontal(matrix, n, m, result);
    output(result, n, m, flag);
    clear(matrix, n);
    clear(result, n);
    return 0;
}

void scanf_r_c(int *n, int *m, int *f) {
    if ((scanf("%d %d", n, m) != 2 && getchar() != '\n') || (*m > 100 || *n > 100)) {
        *f = 0;
        *n = 1;
        *m = 1;
        output_error();
    }
}

void input(int **matrix, int n, int m, int *f) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
        if (getchar() != '\n') {
            *f = 0;
        }
    }
}

void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
    int sort[n * m];
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++, k++) {
            sort[k] = matrix[i][j];
        }
    }
    sort_mat(sort, n * m);
    k = 0;
    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                result_matrix[j][i] = sort[k];
                k++;
            }
        }
        if (i % 2 == 1) {
            for (int j = n - 1; j >= 0; j--) {
                result_matrix[j][i] = sort[k];
                k++;
            }
        }
    }
}

void sort_mat(int *buffer, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1; j++) {
            if (buffer[j] > buffer[j + 1]) {
                int tmp = buffer[j];
                buffer[j] = buffer[j + 1];
                buffer[j + 1] = tmp;
            }
        }
    }
}

void output(int **matrix, int n, int m, int f) {
    if (f == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d", matrix[i][j]);
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

void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
    int sort[n * m];
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++, k++) {
            sort[k] = matrix[i][j];
        }
    }
    sort_mat(sort, n * m);
    k = 0;
    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                result_matrix[i][j] = sort[k];
                k++;
            }
        }
        if (i % 2 == 1) {
            for (int j = n - 1; j >= 0; j--) {
                result_matrix[i][j] = sort[k];
                k++;
            }
        }
    }
}

void output_error(void) { printf("n/a"); }

void clear(int **buffer, int n) {
    for (int i = 0; i < n; i++) {
        free(buffer[i]);
    }
    free(buffer);
}