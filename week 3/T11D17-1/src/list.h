#ifndef _LIST_H_
#define _LIST_H_
#include "door_struct.h"
#define DOORS_COUNT 100
#define MAX_ID_SEED 10000

typedef int tData;

typedef struct sNode {
    tData value[2];
    struct sNode* next;
} tNode;

void initialize_doors(struct door* doors);
tNode* init(struct door* doors);
void delete_list(tNode* p_begin);
void remove_door(tNode** head, int n);
tNode* getNth(tNode* head, int n);
void pop(tNode** head);
tNode* add_door(tNode* elem, struct door* door);
tNode* find_door(int door_id, tNode* root);

#endif