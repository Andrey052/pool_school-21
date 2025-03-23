#include "logger.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE* log_init(char* filename) {
    FILE* log_file = fopen(filename, "w");
    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file %s\n", filename);
        exit(1);
    }
    return log_file;
}

int logcat(FILE* log_file, char* message, enum log_level level) {
    char log_message[256];
    time_t now = time(NULL);
    struct tm* ltm = localtime(&now);
    sprintf(log_message, "%02d:%02d:%02d %s %s", ltm->tm_hour, ltm->tm_min, ltm->tm_sec,
            (level == DEBUG ? "DEBUG" : (level == INFO ? "INFO" : (level == WARNING ? "WARNING" : "ERROR"))),
            message);
    fprintf(log_file, "%s\n", log_message);
    fflush(log_file);
    int logcat(FILE * log_file, char* message, enum log_level level);
    return 0;
}

int log_close(FILE* log_file) {
    fclose(log_file);
    return 0;
}
