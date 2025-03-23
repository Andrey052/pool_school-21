#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

void s21_strlen_test(void);
void s21_strcmp_test(void);
void s21_strcpy_test(void);
void s21_strcat_test(void);
void s21_strchr_test(void);
void s21_strstr_test(void);
void s21_strtok_test(void);

int main(int argc, char **argv) {
    char res = argv[1][0];
    switch (res) {
        case '1':
            printf("test 1\n");
            s21_strlen_test();
            break;
        case '2':
            printf("test 2\n");
            s21_strcmp_test();
            break;
        case '3':
            printf("test 3\n");
            s21_strcpy_test();
            break;
        case '4':
            printf("test 4\n");
            s21_strcat_test();
            break;
        case '5':
            printf("test 5\n");
            s21_strchr_test();
            break;
        case '6':
            printf("test 6\n");
            s21_strstr_test();
            break;
        case '7':
            printf("test 7\n");
            s21_strtok_test();
            break;
        default:
            printf("FAIL\n");
            break;
    }
    return 0;
}

void s21_strlen_test(void) {
    if (s21_strlen("12345") == 5) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    if (s21_strlen("") == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    if (s21_strlen("123\0 123") == 7) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strcmp_test(void) {
    if (s21_strcmp("zxcv", "zxcv")) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    if (s21_strcmp("", "1234")) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    if (s21_strcmp("zxcv\0 ass", "zxcv")) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strcpy_test(void) {
    char *data = NULL;
    s21_strcpy(&data, "1234");
    if (s21_strcmp(data, "1234")) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    free(data);
    data = NULL;
    s21_strcpy(&data, "1234\0 123");
    if (s21_strcmp(data, "1234 123")) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    free(data);
    data = NULL;
    s21_strcpy(&data, "");
    if (s21_strcmp(data, "")) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
    free(data);
}

void s21_strcat_test(void) {
    char str1[9] = "1234";
    char str2[] = "5678";
    s21_strcat(str1, str2);
    if (s21_strcmp(str1, "12345678")) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char str3[5] = "";
    char str4[] = "5678";
    s21_strcat(str3, str4);
    if (s21_strcmp(str1, "5678")) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char str5[9] = "1234\0 123";
    char str6[] = "5678";
    s21_strcat(str5, str6);
    if (s21_strcmp(str1, "12345678")) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strchr_test(void) {
    if (s21_strchr("12345678", '1') != 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    if (s21_strchr("", '1') != 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    if (s21_strchr("2345678\0 1", '1') != 0) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strstr_test(void) {
    if (s21_strstr("1234", "23") == 1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    if (s21_strstr("1234", "12") == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    if (s21_strstr("1234\0 67", "67") == 6) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strtok_test(void) {
    char *token;
    char string[] = "12.56";
    char seps[] = ".";
    token = s21_strtok(string, seps);
    if (s21_strcmp(token, "12")) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char string2[] = "12,56";
    token = s21_strtok(string2, seps);
    if (s21_strcmp(token, "")) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char string1[] = "123\0.56";
    token = s21_strtok(string1, seps);
    if (s21_strcmp(token, "12")) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}
