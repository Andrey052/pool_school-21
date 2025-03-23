#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door *doors);
void sort(struct door *buffer);

int main()
{
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);

    sort(doors);
    // printf("\n\n");
    for (int i = 0; i < DOORS_COUNT; i++)
    {
        printf("%d, %d\n", doors[i].id, doors[i].status);
    }

    return 0;
}

void initialize_doors(struct door *doors)
{
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++)
    {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort(struct door *buffer)
{
    for (int i = 0; i < DOORS_COUNT; i++)
    {
        for (int j = 0; j < DOORS_COUNT - 1; j++)
        {
            if (buffer[j].id > buffer[j + 1].id)
            {
                struct door tmp[1];
                tmp[0].id = buffer[j].id;
                tmp[0].status = buffer[j].status;
                buffer[j].id = buffer[j + 1].id;
                buffer[j].status = buffer[j + 1].status;
                buffer[j + 1].id = tmp[0].id;
                buffer[j + 1].status = tmp[0].status;
            }
        }
    }
}
