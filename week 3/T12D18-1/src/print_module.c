#include "print_module.h"

#include <stdio.h>
#include <string.h>
#include <time.h>

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print)(char), char* message) {
    time_t mytime = time(NULL);
    struct tm* now = localtime(&mytime);
    int i = 0;
    while (Log_prefix[i] != '\0') {
        print(Log_prefix[i]);
        i++;
    }
    print(' ');
    print(now->tm_hour / 10 + '0');
    print(now->tm_hour % 10 + '0');
    print(':');
    print(now->tm_min / 10 + '0');
    print(now->tm_min % 10 + '0');
    print(':');
    print(now->tm_sec / 10 + '0');
    print(now->tm_sec % 10 + '0');
    print(' ');
    i = 0;
    while (message[i] != '\0') {
        print(message[i]);
        i++;
    }
}