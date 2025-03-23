#ifndef S21_STRING_H_
#define S21_STRING_H_

int s21_strlen(char *);
int s21_strcmp(char *, char *);
void s21_strcpy(char **dest, char *src);
char *s21_strcat(char *dest, char *src);
char *s21_strchr(char *s, int c);
int equal_to_patern(char *str, char *pattern);
int s21_strstr(char *str, char *pattern);
char *s21_strtok(char *str, char *delim);

#endif