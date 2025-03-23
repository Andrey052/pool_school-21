#include "master_status_events.h"

#include <stdio.h>
#include <stdlib.h>

void selectMasterStatusEvents(const char* filename, StatusEvent** events, int* count) {
    FILE* file = fopen(filename, "rb");
    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        *count = ftell(file) / sizeof(StatusEvent);
        rewind(file);

        *events = (StatusEvent*)malloc(*count * sizeof(StatusEvent));
        fread(*events, sizeof(StatusEvent), *count, file);

        fclose(file);
    } else {
        printf("Unable to open file: %s\n", filename);
    }
}

void insertMasterStatusEvents(const char* filename, StatusEvent* events) {
    FILE* file = fopen(filename, "ab");
    if (file != NULL) {
        fwrite(events, sizeof(StatusEvent), 1, file);
        fclose(file);
    } else {
        printf("Unable to open file: %s\n", filename);
    }
}

void updateMasterStatusEvents(const char* filename, int* dooper) {
    *dooper = 0;
    FILE* file = fopen(filename, "rb");
    StatusEvent* events_all;
    int count_events = 0;
    StatusEvent* event = malloc(sizeof(StatusEvent));
    StatusEvent* event_new = malloc(sizeof(StatusEvent));
    printf("Write:\neventId moduleId newStatus date(00.00.0000) time(00:00:00)\n");
    scanf("%d %d %d %s %s", &event->eventId, &event->moduleId, &event->newStatus, event->date, event->time);
    selectMasterStatusEvents(filename, &events_all, &count_events);
    fclose(file);
    file = fopen(filename, "w+b");
    for (int i = 0; i < count_events; i++) {
        if (events_all[i].eventId == event->eventId) {
            printf("Write new:\neventId moduleId newStatus date(00.00.0000) time(00:00:00)\n");
            scanf("%d %d %d %s %s", &event_new->eventId, &event_new->moduleId, &event_new->newStatus,
                  event_new->date, event_new->time);
            fwrite(event_new, sizeof(StatusEvent), 1, file);
            *dooper = 1;
        } else {
            fwrite(&events_all[i], sizeof(StatusEvent), 1, file);
        }
    }
    fclose(file);
    free(event);
    free(events_all);
    free(event_new);
}

void deleteMasterStatusEvents(const char* filename, int* dooper) {
    *dooper = 0;
    FILE* file = fopen(filename, "rb");
    StatusEvent* events_all;
    int count_events = 0;
    StatusEvent* event = malloc(sizeof(StatusEvent));
    printf("Write:\neventId moduleId newStatus date(00.00.0000) time(00:00:00)\n");
    scanf("%d %d %d %s %s", &event->eventId, &event->moduleId, &event->newStatus, event->date, event->time);
    selectMasterStatusEvents(filename, &events_all, &count_events);
    fclose(file);
    file = fopen(filename, "w+b");
    for (int i = 0; i < count_events; i++) {
        if (events_all[i].eventId == event->eventId) {
            *dooper = 1;
        } else {
            fwrite(&events_all[i], sizeof(StatusEvent), 1, file);
        }
    }
    fclose(file);
    free(event);
    free(events_all);
}
