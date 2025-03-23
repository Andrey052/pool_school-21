#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

void change_lines(void);
void output(char *buffer, int lenn, int flag_enter);
void move(int *buffer, int *n, int count);

int main(int argc, char **argv) {
    if (argv[1][0] == '-' && argv[1][1] == 'w') {
        change_lines();
    } else {
        printf("n/a");
    }
    return 0;
}

void change_lines(void) {
    int len = 0;
    char *token;
    if ((scanf("%d", &len) != 1 && getchar() != '\n') || len < 2) {
        printf("n/a");
    } else {
        char output_str[len];
        int len_out = 0;
        getchar();
        char str[100];
        char sim = getchar();
        int i = 0;
        while (sim != '\n') {
            str[i] = sim;
            sim = getchar();
            i++;
        }
        token = s21_strtok(str, " ");
        if (len_out < len - 1) {
            if (s21_strlen(token) > 1) {
                output(output_str, len_out, 1);
            } else {
                output_str[len - 1] = token[0];
                output(output_str, len, 1);
                output_str = NULL;
                move(str, s21_strlen(str));
            }
        } else if (len - len_out + 1 < s21_strlen(token)) {
            output_str[len_out] = " ";
            for (int j = len_out + 1; j < len - 1) {
                output_str[j] = token[j - len_out];
            }
            output_str[len - 1] = "-";
            output(output_str, len, 1);
            move(token, &s21_strlen(token), len - len_out - 1);
            output_str = NULL;
        }

        if (s21_strlen(token) > len) {
            for (int j = 0; j < len; j++) {
                output_str[j] = token[j];
            }
        }
        output(output_str, len, 1);
    }
}

void output(char *buffer, int lenn, int flag_enter) {
    for (int i = 0; i < lenn; i++) {
        printf("%c", buffer[i]);
    }
    if (flag_enter == 1) {
        printf("\n");
    }
}

void move(int *buffer, int *n, int count) {
    for (int j = 0; j < count; j++) {
        for (int *p = buffer; p - buffer < n - 1; p++) {
            *p = *(p + 1);
        }
    }
}