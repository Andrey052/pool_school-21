#include "master_modules.h"

#include <stdio.h>
#include <stdlib.h>

void selectMasterModules(const char* filename, Module** modules, int* count) {
    FILE* file = fopen(filename, "rb");
    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        *count = ftell(file) / sizeof(Module);
        rewind(file);

        *modules = (Module*)malloc(*count * sizeof(Module));
        fread(*modules, sizeof(Module), *count, file);

        fclose(file);
    } else {
        printf("Unable to open file: %s\n", filename);
    }
}

void insertMasterModules(const char* filename, Module* modules) {
    FILE* file = fopen(filename, "ab");
    if (file != NULL) {
        fwrite(modules, sizeof(Module), 1, file);
        fclose(file);
    } else {
        printf("Unable to open file: %s\n", filename);
    }
}

void updateMasterModules(const char* filename, int* dooper) {
    *dooper = 0;
    FILE* file = fopen(filename, "rb");
    Module* modules_all;
    int count_modules = 0;
    Module* module = malloc(sizeof(Module));
    Module* module_new = malloc(sizeof(Module));
    printf("Write:\nid name memoryLevel memoryCell deleteFlag\n");
    scanf("%d %s %d %d %d", &module->id, module->name, &module->memoryLevel, &module->memoryCell,
          &module->deleteFlag);
    selectMasterModules(filename, &modules_all, &count_modules);
    fclose(file);
    file = fopen(filename, "w+b");
    for (int i = 0; i < count_modules; i++) {
        if (modules_all[i].id == module->id) {
            printf("Write new:\nid name memoryLevel memoryCell deleteFlag\n");
            scanf("%d %s %d %d %d", &module_new->id, module_new->name, &module_new->memoryLevel,
                  &module_new->memoryCell, &module_new->deleteFlag);
            fwrite(module_new, sizeof(Module), 1, file);
            *dooper = 1;
        } else {
            fwrite(&modules_all[i], sizeof(Module), 1, file);
        }
    }
    fclose(file);
    free(module);
    free(modules_all);
    free(module_new);
}

void updateMasterModules_by_id(const char* filename, Module* modules, int id) {
    FILE* file = fopen(filename, "rb");
    Module* modules_all;
    int count_modules = 0;
    selectMasterModules(filename, &modules_all, &count_modules);
    fclose(file);
    file = fopen(filename, "wb");
    for (int i = 0; i < count_modules; i++) {
        if (modules_all[i].id == id) {
            fwrite(modules, sizeof(Module), 1, file);
        } else {
            fwrite(&modules_all[i], sizeof(Module), 1, file);
        }
    }
    fclose(file);
    free(modules_all);
}

void deleteMasterModules(const char* filename, int* dooper) {
    *dooper = 0;
    FILE* file = fopen(filename, "rb");
    Module* modules_all;
    int count_modules = 0;
    Module* module = malloc(sizeof(Module));
    printf("Write:id\n");
    scanf("%d", &module->id);
    selectMasterModules(filename, &modules_all, &count_modules);
    fclose(file);
    file = fopen(filename, "w+b");
    for (int i = 0; i < count_modules; i++) {
        if (modules_all[i].id == module->id) {
            *dooper = 1;
        } else {
            fwrite(&modules_all[i], sizeof(Module), 1, file);
        }
    }
    fclose(file);
    free(module);
    free(modules_all);
}