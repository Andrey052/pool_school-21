#include "documentation_module.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

int* check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    int* availability_mask = malloc(document_count * sizeof(int));

    va_list documents;
    va_start(documents, document_count);

    for (int i = 0; i < document_count; i++) {
        char* document_name = va_arg(documents, char*);
        availability_mask[i] = validate(document_name);
    }
    va_end(documents);
    return availability_mask;
}