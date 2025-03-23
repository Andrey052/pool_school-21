#include "s21_string.h"

#include <stdlib.h>
#include <string.h>

int s21_strlen(char *s) {
    char *sc = 0;

    for (sc = s; *sc != '\0'; ++sc) {
    }
    return sc - s;
}

int s21_strcmp(char *cs, char *ct) {
    char c1, c2;
    while (1) {
        c1 = *cs++;
        c2 = *ct++;
        if (c1 != c2) return 0;
        if (!c1) break;
    }
    return 1;
}

void s21_strcpy(char **dest, char *src) {
    int len = s21_strlen(src);
    *dest = (char *)malloc(len * sizeof(char *));
    for (int i = 0; i < len; i++) {
        (*dest)[i] = src[i];
    }
}

char *s21_strcat(char *dest, char *src) {
    char *tmp = dest;
    while (*dest) dest++;
    while ((*dest++ = *src++) != '\0') {
    }
    return tmp;
}

char *s21_strchr(char *s, int c) {
    for (; *s != c; ++s)
        if (*s == '\0') return 0;
    return (char *)s;
}

int equal_to_patern(char *str, char *pattern) {
    while (*pattern) {
        if (*(pattern++) != *(str++)) return 0;
    }
    return 1;
}

int s21_strstr(char *str, char *pattern) {
    char *start = str;

    if (s21_strlen(str) < s21_strlen(pattern)) return -1;

    while (*str) {
        if (*str == *pattern) {
            if (equal_to_patern(str, pattern)) return str - start;
        }
        str++;
    }
    return -1;
}

char *s21_strtok(char *str, char *delim) {
    char *next;

    if (str) {
        next = str;
        while (*next && s21_strchr(delim, *next)) *next++ = '\0';
    }

    if (!*next) return NULL;

    str = next;

    while (*next && !s21_strchr(delim, *next)) ++next;
    while (*next && s21_strchr(delim, *next)) *next++ = '\0';

    return str;
}