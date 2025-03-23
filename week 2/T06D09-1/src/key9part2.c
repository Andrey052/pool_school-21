#include <stdio.h>

#define LEN 100

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void input(int *buffer1, int *len1, int *buffer2, int *len2, int *f);
void output(int *buffer, int length, int f);
void move(int *buffer, int n);
void move_plus(int *buffer, int n);

int main() {
    int data1[LEN], data2[LEN], len1, len2;
    int flag = 1;
    int result[LEN], result_length;
    input(data1, &len1, data2, &len2, &flag);
    if (flag == 1) {
        sum(data1, len1, data2, len2, result, &result_length);
        output(result, result_length, flag);
        if (len1 > len2) {
            sub(data1, len1, data2, len2, result, &result_length);
            output(result, result_length, flag);
        } else if (len1 == len2 && data1[0] >= data2[0]) {
            sub(data1, len1, data2, len2, result, &result_length);
            output(result, result_length, flag);
        } else {
            output(result, result_length, 0);
        }
    } else {
        output(result, result_length, 0);
    }
    return 0;
}

void input(int *buffer1, int *len1, int *buffer2, int *len2, int *f) {
    int *p = buffer1 - 1;
    do {
        p++;
        if (scanf("%d", p) != 1 || *p > 9 || *p < 0) {
            *f = 0;
        }
    } while (getchar() != '\n' && (p - buffer1) < 100);
    *len1 = p - buffer1 + 1;

    int *p2 = buffer2 - 1;
    do {
        p2++;
        if (scanf("%d", p2) != 1 || *p2 > 9 || *p2 < 0) {
            *f = 0;
        }
    } while (getchar() != '\n' && (p2 - buffer2) < 100);
    *len2 = p2 - buffer2 + 1;
}

void output(int *buffer, int length, int f) {
    if (f == 1) {
        for (int *p = buffer; p - buffer < length; p++) {
            printf("%d ", *p);
        }
        printf("\n");
    } else {
        printf("n/a\n");
    }
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int flag = 0;
    if (len1 > len2) {
        *result_length = len1 - 1;
        for (int i = len2 - 1; i >= 0; i--) {
            if (buff1[i + (len1 - len2)] + buff2[i] + flag > 9) {
                result[*result_length] = buff1[i + (len1 - len2)] + buff2[i] + flag - 10;
                flag = 1;
            } else {
                result[*result_length] = buff1[i + (len1 - len2)] + buff2[i] + flag;
                flag = 0;
            }
            --*result_length;
        }
        for (int i = len1 - len2 - 1; i >= 0; i--) {
            result[*result_length] = buff1[i] + flag;
            --*result_length;
            flag = 0;
        }
        *result_length = len1;
        if (flag == 1) {
            move(result, 1 + *result_length);
            result[0] = flag;
            *result_length = 1 + len1;
        }
    } else {
        *result_length = len2 - 1;
        for (int i = len1 - 1; i >= 0; i--) {
            if (buff2[i + (len2 - len1)] + buff1[i] > 9) {
                result[*result_length] = buff2[i + (len2 - len1)] + buff1[i] + flag - 10;
                flag = 1;
            } else {
                result[*result_length] = buff2[i + (len2 - len1)] + buff1[i] + flag;
                flag = 0;
            }
            --*result_length;
        }

        for (int i = len2 - len1 - 1; i >= 0; i--) {
            result[*result_length] = buff2[i] + flag;
            --*result_length;
            flag = 0;
        }
        *result_length = len2;
        if (flag == 1) {
            move(result, 1 + *result_length);
            result[0] = flag;
            *result_length = 1 + len2;
        }
        while (result[0] == 0) {
            move_plus(result, (*result_length));
            *result_length -= 1;
        }
    }
}

void move(int *buffer, int n) {
    int med = buffer[0];
    int med1 = 0;
    for (int *p = buffer + 1; p - buffer < n; p++) {
        med1 = *p;
        *p = med;
        med = med1;
    }
}

void move_plus(int *buffer, int n) {
    for (int *p = buffer; p - buffer < n - 1; p++) {
        *p = *(p + 1);
    }
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int flag = 0;
    *result_length = len1 - 1;
    for (int i = len2 - 1; i >= 0; i--) {
        if (buff1[i + (len1 - len2)] - buff2[i] - flag < 0) {
            result[*result_length] = buff1[i + (len1 - len2)] - buff2[i] - flag + 10;
            flag = 1;
        } else {
            result[*result_length] = buff1[i + (len1 - len2)] - buff2[i] - flag;
            flag = 0;
        }
        --*result_length;
    }
    for (int i = len1 - len2 - 1; i >= 0; i--) {
        result[*result_length] = buff1[i] - flag;
        --*result_length;
        flag = 0;
    }
    *result_length = len1;
    while (result[0] == 0) {
        move_plus(result, (*result_length));
        *result_length -= 1;
    }
}