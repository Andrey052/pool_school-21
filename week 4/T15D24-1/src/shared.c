#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "master_levels.h"
#include "master_modules.h"
#include "master_status_events.h"

#define PATH_TO_MASTER_MODULES "../materials/master_modules.db"
#define PATH_TO_MASTER_LEVELS "../materials/master_levels.db"
#define PATH_TO_MASTER_STATUS_EVENTS "../materials/master_status_events.db"

int select(int name, int count) {
    int flag = 0;
    if (name == 1) {
        Module* modules;
        int count_modules = 0;
        selectMasterModules(PATH_TO_MASTER_MODULES, &modules, &count_modules);
        printf("id\tname\t\t\tmemoryLevel\tmemoryCell\tdeleteFlag\n");
        for (int i = 0; i < count_modules && i < count; i++) {
            printf("%d\t%s\t\t%d\t\t%d\t\t%d\n", modules[i].id, modules[i].name, modules[i].memoryLevel,
                   modules[i].memoryCell, modules[i].deleteFlag);
        }
        flag = 1;
        free(modules);
    } else if (name == 2) {
        Level* levels;
        int count_levels = 0;
        selectMasterLevels(PATH_TO_MASTER_LEVELS, &levels, &count_levels);
        printf("id\tcellCount\tprotectionFlag\n");
        for (int i = 0; i < count_levels && i < count; i++) {
            printf("%d\t%d\t\t%d\n", levels[i].levelNumber, levels[i].cellCount, levels[i].protectionFlag);
        }
        flag = 1;
        free(levels);
    } else if (name == 3) {
        StatusEvent* events;
        int count_events = 0;
        selectMasterStatusEvents(PATH_TO_MASTER_STATUS_EVENTS, &events, &count_events);
        printf("eventId\t\tmoduleId\tStatus\t\tdate\t\ttime\n");
        for (int i = 0; i < count_events && i < count; i++) {
            printf("%d\t\t%d\t\t%d\t\t%s\t%s\n", events[i].eventId, events[i].moduleId, events[i].newStatus,
                   events[i].date, events[i].time);
        }
        flag = 1;
        free(events);
    }
    return flag;
}

int insert(int name) {
    if (name == 1) {
        Module* modules = malloc(sizeof(Module));
        Module* modules_all;
        printf("Write:\nid name memoryLevel memoryCell deleteFlag\n");
        scanf("%d %s %d %d %d", &modules->id, modules->name, &modules->memoryLevel, &modules->memoryCell,
              &modules->deleteFlag);
        int count_modules = 0;
        selectMasterModules(PATH_TO_MASTER_MODULES, &modules_all, &count_modules);
        for (int i = 0; i < count_modules; i++) {
            if (modules_all[i].id == modules->id) {
                printf("Module with this id already exists\n");
                free(modules);
                free(modules_all);
                return 0;
            }
        }
        insertMasterModules(PATH_TO_MASTER_MODULES, modules);
        free(modules);
        free(modules_all);
    } else if (name == 2) {
        Level* level = malloc(sizeof(Level));
        Level* levels_all;
        printf("Write:\nlevelNumber cellCount protectionFlag\n");
        scanf("%d %d %d", &level->levelNumber, &level->cellCount, &level->protectionFlag);
        int count_levels = 0;
        selectMasterLevels(PATH_TO_MASTER_MODULES, &levels_all, &count_levels);
        for (int i = 0; i < count_levels; i++) {
            if (levels_all[i].levelNumber == level->levelNumber) {
                printf("Module with this id already exists\n");
                free(level);
                free(levels_all);
                return 0;
            }
        }
        insertMasterLevels(PATH_TO_MASTER_MODULES, level);
        free(level);
        free(levels_all);
    } else if (name == 3) {
        StatusEvent* event = malloc(sizeof(StatusEvent));
        StatusEvent* events_all;
        printf("Write:\neventId moduleId newStatus date(00.00.0000) time(00:00:00)\n");
        scanf("%d %d %d %s %s", &event->eventId, &event->moduleId, &event->newStatus, event->date,
              event->time);
        int count_events = 0;
        selectMasterStatusEvents(PATH_TO_MASTER_MODULES, &events_all, &count_events);
        for (int i = 0; i < count_events; i++) {
            if (events_all[i].eventId == event->eventId) {
                printf("Module with this id already exists\n");
                free(event);
                free(events_all);
                return 0;
            }
        }
        insertMasterStatusEvents(PATH_TO_MASTER_MODULES, event);
        free(event);
        free(events_all);
    } else {
        return 2;
    }
    return 1;
}

int update(int name) {
    int dooper = 0;
    if (name == 1) {
        dooper = 0;
        updateMasterModules(PATH_TO_MASTER_MODULES, &dooper);
    } else if (name == 2) {
        dooper = 0;
        updateMasterLevels(PATH_TO_MASTER_MODULES, &dooper);
    } else if (name == 3) {
        dooper = 0;
        updateMasterStatusEvents(PATH_TO_MASTER_MODULES, &dooper);
    } else {
        dooper = 2;
    }
    return dooper;
}

int delete (int name) {
    int dooper = 0;
    if (name == 1) {
        deleteMasterModules(PATH_TO_MASTER_MODULES, &dooper);
    } else if (name == 2) {
        deleteMasterLevels(PATH_TO_MASTER_LEVELS, &dooper);
    } else if (name == 3) {
        deleteMasterStatusEvents(PATH_TO_MASTER_STATUS_EVENTS, &dooper);
    } else {
        dooper = 2;
    }
    return dooper;
}

void module_status_1() {
    StatusEvent* events;
    int count_events = 0;
    selectMasterStatusEvents(PATH_TO_MASTER_STATUS_EVENTS, &events, &count_events);
    printf("eventId\t\tmoduleId\tStatus\t\tdate\t\ttime\n");
    for (int i = 0; i < count_events; i++) {
        if (events[i].newStatus == 1) {
            printf("%d\t\t%d\t\t%d\t\t%s\t%s\n", events[i].eventId, events[i].moduleId, events[i].newStatus,
                   events[i].date, events[i].time);
        }
    }
    free(events);
}

void delete_modul_by_id(int id) {
    Module* modules_new = malloc(sizeof(Module));
    Module* modules;
    int count_modules = 0;
    selectMasterModules(PATH_TO_MASTER_MODULES, &modules, &count_modules);
    int not = 0;
    for (int i = 0; i < count_modules; i++) {
        if (modules[i].id == id) {
            modules_new->id = modules[i].id;
            strcpy(modules_new->name, modules[i].name);
            modules_new->memoryLevel = modules[i].memoryLevel;
            modules_new->memoryCell = modules[i].memoryCell;
            modules_new->deleteFlag = 1;
            not = 1;
        }
    }
    if (not == 1) {
        updateMasterModules_by_id(PATH_TO_MASTER_MODULES, modules_new, id);
    }else{
        printf("There is no module with this id\n");
    }
    free(modules);
    free(modules_new);
}

void protect_level_by_id(int id) {
    Level* levels_new = malloc(sizeof(Level));
    Level* levels;
    int count_levels = 0;
    int not = 0;
    selectMasterLevels(PATH_TO_MASTER_LEVELS, &levels, &count_levels);
    for (int i = 0; i < count_levels; i++) {
        if (levels[i].levelNumber == id) {
            levels_new->levelNumber = levels[i].levelNumber;
            levels_new->cellCount = levels[i].cellCount;
            levels_new->protectionFlag = 1;
            not = 1;
        }
    }
    if (not == 1) {
        protectMasterLevels_by_id(PATH_TO_MASTER_LEVELS, levels_new, id);
    }else{
        printf("There is no level with this levelNumber\n");
    }
    
    free(levels);
    free(levels_new);
}

void move_to_new_memory(int id) {
    Module* modules_new = malloc(sizeof(Module));
    Module* modules;
    int count_modules = 0;
    selectMasterModules(PATH_TO_MASTER_MODULES, &modules, &count_modules);
    int not = 0;
    for (int i = 0; i < count_modules; i++) {
        if (modules[i].id == id) {
            modules_new->id = modules[i].id;
            strcpy(modules_new->name, modules[i].name);
            modules_new->deleteFlag = 1;
            not = 1;
        }
    }
    if (not == 1) {
        printf("New memory level and cell:\n");
        scanf("%d %d", &modules_new->memoryLevel, &modules_new->memoryCell);
        updateMasterModules_by_id(PATH_TO_MASTER_MODULES, modules_new, id);
    }else{
        printf("There is no module with this id\n");
    }
    free(modules);
    free(modules_new);
}