#ifndef MASTER_LEVELS_H
#define MASTER_LEVELS_H

typedef struct {
    int levelNumber;
    int cellCount;
    int protectionFlag;
} Level;

void selectMasterLevels(const char *, Level **, int *);
void insertMasterLevels(const char *, Level *);
void updateMasterLevels(const char *, int *);
void deleteMasterLevels(const char *, int *);
void protectMasterLevels_by_id(const char*, Level*, int);

#endif
