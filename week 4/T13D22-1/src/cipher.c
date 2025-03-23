#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logger.h"

#define ALPHABET_SIZE 26
#define MAX_LINE_LENGTH 1024
#define EXTC ".c"
#define EXTH ".h"
#define ELEN 2

void print_in(char* char_array, int steps);
char* readStringFromConsole();
int Quest1(char* name);
int Quest2(char* name, char* second);
void Des(char* name);
void des_encrypt(uint64_t* block, uint64_t* key);

int main() {
#ifdef Q_1
    FILE* file;
    int flag_resol = 1;
    scanf("%d", &flag_resol);
    while (flag_resol != -1) {
        getchar();
        char* string;
        if (flag_resol == 1) {
            string = readStringFromConsole();
            flag_resol = Quest1(string);
            free(string);
        } else if (flag_resol == 2) {
            char* string1 = readStringFromConsole();
            if (!string) {
                printf("n/a");
                scanf("%d", &flag_resol);
                continue;
            }
            flag_resol = Quest2(string, string1);
            free(string1);
        } else if (flag_resol == 3) {
            char str[100];
            char name[100];
            FILE* file1;
            DIR* d;
            struct dirent* dir;
            char* string = readStringFromConsole();
            int count_steps = 0;
            scanf("%d", &count_steps);
            d = opendir(string);
            if (d) {
                while ((dir = readdir(d)) != NULL) {
                    size_t nlen = strlen(dir->d_name);
                    if (!strcmp((dir->d_name) + nlen - ELEN, EXTC)) {
                        strcpy(name, string);
                        strncat(name, dir->d_name, nlen);
                        file = fopen(name, "r");
                        file1 = fopen("buff.txt", "w");
                        if (file != NULL) {
                            while (fgets(str, 100, file) != NULL) {
                                print_in(str, count_steps);
                                fprintf(file1, "%s", str);
                            }
                        }
                        fclose(file);
                        fclose(file1);
                        file = fopen("buff.txt", "r");
                        file1 = fopen(name, "w");
                        if (file != NULL) {
                            while (fgets(str, 100, file) != NULL) {
                                print_in(str, count_steps);
                                fprintf(file1, "%s", str);
                            }
                        }
                        fclose(file);
                        fclose(file1);
                    } else if (!strcmp((dir->d_name) + nlen - ELEN, EXTH)) {
                        strcpy(name, string);
                        strncat(name, dir->d_name, nlen);
                        file = fopen(name, "w");
                        fclose(file);
                    }
                }
            }
            closedir(d);
            remove("buff.txt");
            free(string);
            scanf("%d", &flag_resol);
        } else if (flag_resol == 4) {
            DIR* d;
            char name[100];
            struct dirent* dir;
            char* string = readStringFromConsole();
            d = opendir(string);
            if (d) {
                while ((dir = readdir(d)) != NULL) {
                    size_t nlen = strlen(dir->d_name);
                    if (!strcmp((dir->d_name) + nlen - ELEN, EXTC)) {
                        strcpy(name, string);
                        strncat(name, dir->d_name, nlen);
                        Des(name);
                    } else if (!strcmp((dir->d_name) + nlen - ELEN, EXTH)) {
                        strcpy(name, string);
                        strncat(name, dir->d_name, nlen);
                        file = fopen(name, "w");
                        fclose(file);
                    }
                }
            }
            free(string);
            free(d);
            scanf("%d", &flag_resol);
        } else {
            printf("n/a");
            scanf("%d", &flag_resol);
            if (flag_resol != -1) {
                printf("\n");
            }
            continue;
        }
    }
#endif
#ifdef D
    char* string = readStringFromConsole();
    FILE* log_file = log_init(string);
    char* massage = readStringFromConsole();
    logcat(log_file, massage, DEBUG);
    log_close(log_file);
#elif I
    char* string = readStringFromConsole();
    FILE* log_file = log_init(string);
    char* massage = readStringFromConsole();
    logcat(log_file, massage, INFO);
    log_close(log_file);
#elif W
    char* string = readStringFromConsole();
    FILE* log_file = log_init(string);
    char* massage = readStringFromConsole();
    logcat(log_file, massage, WARNING);
    log_close(log_file);
#elif E
    char* string = readStringFromConsole();
    FILE* log_file = log_init(string);
    char* massage = readStringFromConsole();
    logcat(log_file, massage, ERROR);
    log_close(log_file);
#endif
    return 0;
}

char* readStringFromConsole() {
    char* buffer = NULL;
    size_t bufferSize = 0;
    ssize_t bytesRead = getline(&buffer, &bufferSize, stdin);
    if (bytesRead == -1) {
        free(buffer);
        return NULL;
    }
    buffer[strcspn(buffer, "\n")] = 0;
    return buffer;
}

void print_in(char* char_array, int steps) {
    int i;
    for (i = 0; i < (int)strlen(char_array); i++) {
        if (char_array[i] >= 'a' && char_array[i] <= 'z') {
            char_array[i] = 'a' + (char_array[i] - 'a' + steps) % ALPHABET_SIZE;
        } else if (char_array[i] >= 'A' && char_array[i] <= 'Z') {
            char_array[i] = 'A' + (char_array[i] - 'A' + steps) % ALPHABET_SIZE;
        }
    }
}

int Quest1(char* name) {
    FILE* file;
    char line[MAX_LINE_LENGTH];
    int flag_resol = 1;
    file = fopen(name, "r");
    if (file == NULL) {
        printf("n/a");
        scanf("%d", &flag_resol);
        return flag_resol;
    }
    while (fgets(line, 100, file) != NULL) {
        printf("%s", line);
    }
    fclose(file);
    if (line[0] == '\0') {
        printf("n/a");
        scanf("%d", &flag_resol);
        if (flag_resol != -1) {
            printf("\n");
        }
        return flag_resol;
    }
    scanf("%d", &flag_resol);
    if (flag_resol != -1) {
        printf("\n");
    }
    return flag_resol;
}

int Quest2(char* name, char* second) {
    FILE* file;
    char line[MAX_LINE_LENGTH];
    int flag_resol = 1;
    file = fopen(name, "r");
    if (file == NULL) {
        printf("n/a\n");
        printf("n/a");
        scanf("%d", &flag_resol);
        return flag_resol;
    }
    while (fgets(line, 100, file) != NULL) {
        printf("%s", line);
    }
    fclose(file);
    if (line[0] == '\0') {
        printf("n/a\n");
        printf("n/a");
        printf("%s", second);
        scanf("%d", &flag_resol);
        if (flag_resol != -1) {
            printf("\n");
        }
        return flag_resol;
    }
    printf("%s", second);
    scanf("%d", &flag_resol);
    if (flag_resol != -1) {
        printf("\n");
    }
    return flag_resol;
}

void des_encrypt(uint64_t* block, uint64_t* key) {
    uint64_t left, right;
    uint64_t temp;
    left = *block >> 32;
    right = *block & 0xffffffff;
    for (int i = 0; i < 16; i++) {
        temp = (left ^ (key[i / 4] >> (24 - (i % 4) * 8)));
        temp = (temp >> 4) | (temp << 60);
        right ^= temp;
        temp = left;
        left = right;
        right = temp;
    }
    *block = (left << 32) | right;
}

void Des(char* name) {
    FILE* file;
    file = fopen("buff.txt", "w");
    char message[64];
    uint64_t block;
    uint64_t key = 0x0123456789abcdef;
    FILE* file_start = fopen(name, "r");
    if (file_start != NULL) {
        while (fgets(message, sizeof(message), file_start) != NULL) {
            message[strcspn(message, "\n")] = 0;
            block = *(uint64_t*)message;
            des_encrypt(&block, &key);
            for (int i = 0; i < (int)sizeof(uint64_t); i++) {
                fprintf(file, "%02x", (unsigned char)((block >> (i * 8)) & 0xff));
            }
            fprintf(file, "\n");
        }
    }
    fclose(file);
    fclose(file_start);
    remove(name);
    rename("buff.txt", name);
}