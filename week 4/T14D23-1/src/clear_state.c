#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
int is_date_in_range(struct tm* date_to_check, struct tm* start_date, struct tm* end_date);

int main(void) {
    char* string = readStringFromConsole();
    // char *filename = "../datasets/door_state_3";
    FILE* file;
    file = fopen(string, "r+b");
    if (!file) {
        printf("n/a");
    } else {
        printFile(file);
        fclose(file);
    }
    remove(string);
    rename("buffer", string);
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
    FILE* buffer = fopen("buffer", "w+b");
    int fileSize = 0;
    fseek(file, 0, SEEK_END);
    fileSize = ftell(file) / sizeof(struct data);
    rewind(file);
    int year1 = 0, mouns1 = 0, day1 = 0;
    int year2 = 0, mouns2 = 0, day2 = 0;

    int count = 0;
    scanf("%d.%d.%d %d.%d.%d", &day1, &mouns1, &year1, &day2, &mouns2, &year2);

    for (int i = 0; i < fileSize; i++) {
        record = readRecord(file);
        struct tm date_to_check = {.tm_year = record.year, .tm_mon = record.month, .tm_mday = record.day};
        struct tm start_date = {.tm_year = year1, .tm_mon = mouns1, .tm_mday = day1};
        struct tm end_date = {.tm_year = year2, .tm_mon = mouns2, .tm_mday = day2};
        if (is_date_in_range(&date_to_check, &start_date, &end_date)) {
            // printf("%d.%d.%d\n", record.day, record.month, record.year);
            count++;
        } else {
            fwrite(&record, sizeof(struct data), 1, buffer);
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

int is_date_in_range(struct tm* date_to_check, struct tm* start_date, struct tm* end_date) {
    int res = 1;
    if (date_to_check->tm_year < start_date->tm_year || date_to_check->tm_year > end_date->tm_year) {
        res = 0;
    }
    if (date_to_check->tm_year == start_date->tm_year && date_to_check->tm_mon < start_date->tm_mon) {
        res = 0;
    }
    if (date_to_check->tm_year == end_date->tm_year && date_to_check->tm_mon > end_date->tm_mon) {
        res = 0;
    }
    if (date_to_check->tm_mon == start_date->tm_mon && date_to_check->tm_mday < start_date->tm_mday) {
        res = 0;
    }
    if (date_to_check->tm_mon == end_date->tm_mon && date_to_check->tm_mday > end_date->tm_mday) {
        res = 0;
    }
    return res;
}