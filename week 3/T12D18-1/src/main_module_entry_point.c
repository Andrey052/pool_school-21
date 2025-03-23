#include <stdio.h>
#include <stdlib.h>

#include "documentation_module.h"
#include "print_module.h"

int main() {
#ifdef Q_1
    print_log(print_char, Module_load_success_message);
#else
    int *res = check_available_documentation_module(validate, Documents_count, Documents);
    char *str[] = {Documents};
    for (int i = 0; i < Documents_count; i++) {
        if (res[i] == 0) {
            printf("[%-15s:unavailable]\n", str[i]);
        } else {
            printf("[%-15s:available]\n", str[i]);
        }
    }
    free(res);
#endif
    return 0;
}
