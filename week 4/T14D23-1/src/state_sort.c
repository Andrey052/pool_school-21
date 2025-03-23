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

void quickSort(struct data* ptr, int left, int right);
char* readStringFromConsole();
void printFile(FILE* file);
struct data readRecord(FILE* file);
void sortRecords(FILE* file);
void writeRecord(FILE* file, struct data record);

int main(void) {
    char* string;
    string = readStringFromConsole();
    int flag_resol = 0;
    scanf("%d", &flag_resol);
    // char *filename = "../datasets/door_state_1";
    FILE* file;
    file = fopen(string, "r+b");
    if (!file) {
        printf("n/a");
    } else {
        if (flag_resol == 0) {
            printFile(file);
            fclose(file);
        } else if (flag_resol == 1) {
            sortRecords(file);
            printFile(file);
            fclose(file);
        } else if (flag_resol == 2) {
            struct data rec;
            scanf("%d %d %d %d %d %d %d %d", &rec.year, &rec.month, &rec.day, &rec.hour, &rec.minute,
                  &rec.second, &rec.status, &rec.code);
            fseek(file, 0, SEEK_END);
            writeRecord(file, rec);
            sortRecords(file);
            printFile(file);
            fclose(file);
        }
    }
    free(string);
    return 0;
}

void quickSort(struct data* ptr, int left, int right) {
    int pivot;
    int index;
    int l_hold = left;
    int r_hold = right;
    pivot = ptr[left].year;
    while (left < right) {
        while ((ptr[right].year >= pivot) && (left < right)) right--;
        if (left != right) {
            ptr[left].year = ptr[right].year;
            ptr[left].month = ptr[right].month;
            ptr[left].day = ptr[right].day;
            ptr[left].hour = ptr[right].hour;
            ptr[left].minute = ptr[right].minute;
            ptr[left].second = ptr[right].second;
            ptr[left].status = ptr[right].status;
            ptr[left].code = ptr[right].code;
            left++;
        }
        while ((ptr[left].year <= pivot) && (left < right)) left++;
        if (left != right) {
            ptr[right].year = ptr[left].year;
            ptr[right].month = ptr[left].month;
            ptr[right].day = ptr[left].day;
            ptr[right].hour = ptr[left].hour;
            ptr[right].minute = ptr[left].minute;
            ptr[right].second = ptr[left].second;
            ptr[right].status = ptr[left].status;
            ptr[right].code = ptr[left].code;
            right--;
        }
    }
    ptr[left].year = pivot;
    index = left;
    left = l_hold;
    right = r_hold;
    if (left < index) quickSort(ptr, left, index - 1);
    if (right > index) quickSort(ptr, index + 1, right);
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

    for (int i = 0; i < fileSize; i++) {
        record = readRecord(file);
        printf("%04d-%02d-%02d %02d:%02d:%02d %d %d\n", record.year, record.month, record.day, record.hour,
               record.minute, record.second, record.status, record.code);
    }
}

struct data readRecord(FILE* file) {
    struct data record;
    fread(&record, sizeof(struct data), 1, file);
    return record;
}

void sortRecords(FILE* file) {
    if (file == NULL) {
        printf("n/a\n");
        return;
    }

    struct data records[2000];
    int fileSize = 0;
    fseek(file, 0, SEEK_END);
    fileSize = ftell(file) / sizeof(struct data);
    rewind(file);

    if (fileSize > 2000) {
        printf("n/a\n");
        return;
    }
    for (int i = 0; i < fileSize; i++) {
        if (fread(&records[i], sizeof(struct data), 1, file) != 1) {
            printf("n/a\n");
            return;
        }
    }

    quickSort(records, 0, fileSize - 1);

    for (int i = 0; i < fileSize; i++) {
        if (fwrite(&records[i], sizeof(struct data), 1, file) != 1) {
            printf("n/a\n");
            return;
        }
    }
}

void writeRecord(FILE* file, struct data record) { fwrite(&record, sizeof(struct data), 1, file); }