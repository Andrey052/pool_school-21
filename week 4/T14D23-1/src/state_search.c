#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
};

char* readStringFromConsole();
void printFile(FILE* file);
struct data readRecord(FILE* file);
void writeRecord(FILE* file, struct data record);

int main(void) {
    char* string = readStringFromConsole();
    // char *filename = "../datasets/door_state_1";
    FILE* file;
    file = fopen(string, "r+b");
    if (!file) {
        printf("n/a");
    } else {
        printFile(file);
        fclose(file);
    }
    free(string);
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

void printFile(FILE* file) {
    struct data record;
    int fileSize = 0;
    fseek(file, 0, SEEK_END);
    fileSize = ftell(file) / sizeof(struct data);
    rewind(file);
    int year1 = 0, mouns1 = 0, day1 = 0;
    int count = 0;
    scanf("%d.%d.%d", &day1, &mouns1, &year1);
    for (int i = 0; i < fileSize; i++) {
        record = readRecord(file);
        if (record.year == year1 && record.month == mouns1 && record.day == day1) {
            printf("%d", record.code);
            count++;
        }
    }
    if (count == 0) {
        printf("n/a");
    }
}

struct data readRecord(FILE* file) {
    struct data record;
    fread(&record, sizeof(struct data), 1, file);
    return record;
}
