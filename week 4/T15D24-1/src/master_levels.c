#include "master_levels.h"

#include <stdio.h>
#include <stdlib.h>

void selectMasterLevels(const char* filename, Level** levels, int* count) {
    FILE* file = fopen(filename, "rb");
    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        *count = ftell(file) / sizeof(Level);
        rewind(file);

        *levels = (Level*)malloc(*count * sizeof(Level));
        fread(*levels, sizeof(Level), *count, file);

        fclose(file);
    } else {
        printf("Unable to open file: %s\n", filename);
    }
}

void insertMasterLevels(const char* filename, Level* levels) {
    FILE* file = fopen(filename, "ab");
    if (file != NULL) {
        fwrite(levels, sizeof(Level), 1, file);
        fclose(file);
    } else {
        printf("Unable to open file: %s\n", filename);
    }
}

void updateMasterLevels(const char* filename, int* dooper) {
    *dooper = 0;
    FILE* file = fopen(filename, "rb");
    Level* levels_all;
    int count_levels = 0;
    Level* level = malloc(sizeof(Level));
    Level* level_new = malloc(sizeof(Level));
    printf("Write:\nlevelNumber cellCount protectionFlag\n");
    scanf("%d %d %d", &level->levelNumber, &level->cellCount, &level->protectionFlag);
    selectMasterLevels(filename, &levels_all, &count_levels);
    fclose(file);
    file = fopen(filename, "w+b");
    for (int i = 0; i < count_levels; i++) {
        if (levels_all[i].levelNumber == level->levelNumber) {
            printf("Write new:\nlevelNumber cellCount protectionFlag\n");
            scanf("%d %d %d", &level_new->levelNumber, &level_new->cellCount, &level_new->protectionFlag);
            fwrite(level_new, sizeof(Level), 1, file);
            *dooper = 1;
        } else {
            fwrite(&levels_all[i], sizeof(Level), 1, file);
        }
    }
    fclose(file);
    free(level);
    free(levels_all);
    free(level_new);
}

void deleteMasterLevels(const char* filename, int* dooper) {
    *dooper = 0;
    FILE* file = fopen(filename, "rb");
    Level* levels_all;
    int count_levels = 0;
    Level* level = malloc(sizeof(Level));
    printf("Write:\nlevelNumber cellCount protectionFlag\n");
    scanf("%d %d %d", &level->levelNumber, &level->cellCount, &level->protectionFlag);
    selectMasterLevels(filename, &levels_all, &count_levels);
    fclose(file);
    file = fopen(filename, "w+b");
    for (int i = 0; i < count_levels; i++) {
        if (levels_all[i].levelNumber == level->levelNumber) {
            *dooper = 1;
        } else {
            fwrite(&levels_all[i], sizeof(Level), 1, file);
        }
    }
    fclose(file);
    free(level);
    free(levels_all);
}

void protectMasterLevels_by_id(const char* filename, Level* levels, int id) {
    FILE* file = fopen(filename, "rb");
    Level* levels_all;
    int count_levels = 0;
    selectMasterLevels(filename, &levels_all, &count_levels);
    fclose(file);
    file = fopen(filename, "wb");
    for (int i = 0; i < count_levels; i++) {
        if (levels_all[i].levelNumber == id) {
            fwrite(levels, sizeof(Level), 1, file);
        } else {
            fwrite(&levels_all[i], sizeof(Level), 1, file);
        }
    }
    fclose(file);
    free(levels_all);
}