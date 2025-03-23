#ifndef MASTER_MODULES_H
#define MASTER_MODULES_H

typedef struct {
    int id;
    char name[30];
    int memoryLevel;
    int memoryCell;
    int deleteFlag;
} Module;

void selectMasterModules(const char *, Module **, int *);
void insertMasterModules(const char *, Module *);
void updateMasterModules(const char *, int *);
void deleteMasterModules(const char *, int *);
void updateMasterModules_by_id(const char*, Module*, int);

#endif