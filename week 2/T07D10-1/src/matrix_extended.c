#include <stdio.h>
#include <stdlib.h>

#define LEN 100

void stat(int *f);
void output(int n, int m, int **buffer, int *res1, int *res2, int *f);
void output_error(void);
void din_first(int *f);
void input(int coll, int rows, int **buffer, int *f);
void din_second(int *f);
void din_third(int *f);
void input_start(int *dir, int *f);
void scanf_r_c(int *n, int *m, int *f);
void clear(int **buffer, int n);
int max(int *buffer, int n);
int min(int *buffer, int n);
void res_min_max(int **buffer, int n, int m, int *f);

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
                stat(flag);
                break;
            case 2:
                din_first(flag);
                break;
            case 3:
                din_second(flag);
                break;
            case 4:
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

void res_min_max(int **buffer, int n, int m, int *f) {
    int res_max[n];
    int res_min[m];
    int midle_min[n];
    for (int i = 0; i < m; i++) {
        res_max[i] = max(buffer[i], m);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            midle_min[j] = buffer[j][i];
        }
        res_min[i] = min(midle_min, n);
    }
    output(n, m, buffer, res_max, res_min, f);
}

void stat(int *f) {
    int n = 0, m = 0;
    scanf_r_c(&n, &m, f);
    if (*f != 0) {
        int data[n][m];
        int *data_line[n];
        for (int i = 0; i < n; i++) {
            data_line[i] = data[i];
        }
        input(n, m, data_line, f);
        res_min_max(data_line, n, m, f);
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
        res_min_max(data, n, m, f);
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
        res_min_max(data, n, m, f);
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
        res_min_max(data, n, m, f);
        clear(data, n);
    }
}

void output(int n, int m, int **buffer, int *res1, int *res2, int *f) {
    if (*f == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d", buffer[i][j]);
                if (j < m - 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }
        for (int i = 0; i < n; i++) {
            printf("%d", res1[i]);
            if (i < n - 1) {
                printf(" ");
            }
        }
        printf("\n");
        for (int i = 0; i < m; i++) {
            printf("%d", res2[i]);
            if (i < m - 1) {
                printf(" ");
            }
        }
    } else {
        printf("n/a");
    }
}

void output_error(void) { printf("n/a"); }

int max(int *buffer, int n) {
    int max = *buffer;
    for (int *p = buffer; p - buffer < n; p++) {
        if (max < *p) {
            max = *p;
        }
    }
    return max;
}

int min(int *buffer, int n) {
    int min = *buffer;
    for (int *p = buffer; p - buffer < n; p++) {
        if (min > *p) {
            min = *p;
        }
    }
    return min;
}