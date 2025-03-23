#include <stdio.h>
#include <stdlib.h>

void output(int n, int m, int **buffer, int *f);
void output_error(void);
void din_first(int *f);
void input(int coll, int rows, int **buffer, int *f);
void din_second(int *f);
void din_third(int *f);
void input_start(int *dir, int *f);
void scanf_r_c(int *n, int *m, int *f);
void clear(int **buffer, int n);
void sort(int **buffer, int length_n, int leng_m, int *f);
int summ(int *buffer, int leng);

int main() {
    int flag = 1;
    int dir = 0;
    input_start(&dir, &flag);
    return 0;
}

void clear(int **buffer, int n) {
    for (int i = 0; i < n; i++) {
        free(buffer[i]);
    }
    free(buffer);
}

void scanf_r_c(int *n, int *m, int *f) {
    if ((scanf("%d %d", n, m) != 2 && getchar() != '\n') || (*m > 100 || *n > 100)) {
        *f = 0;
        *n = 1;
        *m = 1;
        output_error();
    }
}

void input_start(int *dir, int *flag) {
    if (scanf("%d", dir) != 1 && getchar() != '\n') {
        *flag = 0;
        output_error();
    } else {
        switch (*dir) {
            case 1:
                din_first(flag);
                break;
            case 2:
                din_second(flag);
                break;
            case 3:
                din_third(flag);
                break;
            default:
                output_error();
        }
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
    int n = 0, m = 0;
    scanf_r_c(&n, &m, f);
    if (*f != 0) {
        int **data = (int **)malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++) {
            data[i] = (int *)malloc(m * sizeof(int));
        }
        input(n, m, data, f);
        sort(data, n, m, f);
        clear(data, n);
    }
}

void din_second(int *f) {
    int n = 0, m = 0;
    scanf_r_c(&n, &m, f);
    if (*f != 0) {
        int **data = (int **)calloc(n, sizeof(int *));
        for (int i = 0; i < n; i++) {
            data[i] = (int *)calloc(m, sizeof(int));
        }
        for (int j = 0; j < n; j++) {
            free(data[j]);
        }
        input(n, m, data, f);
        sort(data, n, m, f);
        clear(data, n);
    }
}

void din_third(int *f) {
    int n = 0, m = 0;
    scanf_r_c(&n, &m, f);
    if (*f != 0) {
        int **data = (int **)malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++) {
            data[i] = (int *)calloc(m, sizeof(int));
        }
        for (int j = 0; j < n; j++) {
            free(data[j]);
        }
        input(n, m, data, f);
        sort(data, n, m, f);
        clear(data, n);
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

void sort(int **buffer, int length_n, int length_m, int *f) {
    for (int i = 0; i < length_n; i++) {
        for (int j = 0; j < length_n - 1; j++) {
            if (summ(buffer[j], length_m) > summ(buffer[j + 1], length_m)) {
                int *tmp = buffer[j];
                buffer[j] = buffer[j + 1];
                buffer[j + 1] = tmp;
            }
        }
    }
    output(length_n, length_m, buffer, f);
}

int summ(int *buffer, int leng) {
    int res = 0;
    for (int i = 0; i < leng; i++) {
        res += buffer[i];
    }
    return res;
}