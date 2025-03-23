#include <stdio.h>
#include <stdlib.h>

#include "shared.h"

void chose_module();
void chose_dir();
void Select();
void Insert();
void Update();
void Delete();

int main() {
    int operation = 0;
    int id = 0;
    while (operation != 10) {
        chose_module();
        scanf("%d", &operation);
        switch (operation) {
            case 1:
                Select();
                break;
            case 2:
                Insert();
                break;
            case 3:
                Update();
                break;
            case 4:
                Delete();
                break;
            case 5:
                module_status_1();
                break;
            case 6:
                id = 0;
                printf("Write id:\n");
                scanf("%d", &id);
                delete_modul_by_id(id);
                break;
            case 7:
                id = 0;
                printf("Write levelNumber:\n");
                scanf("%d", &id);
                protect_level_by_id(id);
                break;
            case 8:
                id = 0;
                printf("Write id:\n");
                scanf("%d", &id);
                move_to_new_memory(id);
                break;
            case 9:
                id = 0;
                printf("Write levelNumber:\n");
                scanf("%d", &id);
                protect_level_by_id(id);
                break;
            case 10:
                break;
            default:
                printf("Incorrect operation\n");
                break;
        }
    }
    return 0;
}

void chose_module() {
    printf(
        "Please choose one operation:\n1. SELECT\n2. INSERT\n3. UPDATE\n4. DELETE\n5. Get all active "
        "additional modules (last module status is 1)\n6. Delete modules by ids\n7. Set protected mode for "
        "module by id\n8. Move module by id to specified memory level and cell\n9. Set protection flag of "
        "the specified memory level\n10. Exit\n");
}

void chose_dir() { printf("Please choose directory:\n1. Modules\n2. Levels\n3. Status events\n"); }

void Select() {
    int dir = 0;
    int flag_errors = 1;
    chose_dir();
    scanf("%d", &dir);
    int count_lines = 0;
    printf("Insert the number of records or leave empty to output all of them:\n");
    getchar();
    char c = getchar();
    while (c != '\n') {
        count_lines = count_lines * 10 + c - '0';
        c = getchar();
    }
    if (count_lines == 0) {
        count_lines = 500;
    }
    flag_errors = select(dir, count_lines);
    if (flag_errors == 0) {
        printf("No search file of directory\n");
    }
}

void Insert() {
    int dir = 0;
    int flag_errors = 1;
    chose_dir();
    scanf("%d", &dir);
    flag_errors = insert(dir);
    if (flag_errors == 2) {
        printf("No search file of directory\n");
    }
}

void Update() {
    int dir = 0;
    int flag_errors = 1;
    chose_dir();
    scanf("%d", &dir);
    flag_errors = update(dir);
    if (flag_errors == 2) {
        printf("No search file of directory\n");
    } else if (flag_errors == 0) {
        printf("No search data in database\n");
    }
}

void Delete() {
    int dir = 0;
    int flag_errors = 1;
    chose_dir();
    scanf("%d", &dir);
    flag_errors = delete (dir);
    if (flag_errors == 2) {
        printf("No search file of directory\n");
    } else if (flag_errors == 0) {
        printf("No search data in database\n");
    }
}
