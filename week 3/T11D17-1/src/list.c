#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        printf("FAIL\n");
        return 0;
    }
    struct door doors[15];

    initialize_doors(doors);
    tNode *p_begin = init(doors);
    char res = argv[1][0];
    switch (res)
    {
    case '1':
        struct door doors1[1];
        doors1[0].id = 20;
        doors1[0].status = 1;
        p_begin = add_door(p_begin, doors1);
        if (p_begin != NULL)
        {
            printf("SUCCESS");
        }
        else
        {
            printf("FAIL");
        }
        delete_list(p_begin);
        break;
    case '2':
        tNode *p = p_begin;
        p_begin = find_door(21, p);
        if (p_begin != NULL)
        {
            printf("SUCCESS");
        }
        else
        {
            printf("FAIL");
        }
        delete_list(p_begin);
        delete_list(p);
        break;
    case '3':
        remove_door(&p_begin, 3);
        if (p_begin != NULL)
        {
            printf("SUCCESS");
        }
        else
        {
            printf("FAIL");
        }
        delete_list(p_begin);
        break;
    case '4':
        delete_list(p_begin);
        if (p_begin != NULL)
        {
            printf("SUCCESS");
        }
        else
        {
            printf("FAIL");
        }
        break;
    default:
        printf("FAIL\n");
        break;
    }
    return 0;
}

void initialize_doors(struct door *doors)
{
    srand(time(0));

    int seed = rand() % 15;
    for (int i = 0; i < 15; i++)
    {
        doors[i].id = (i + seed) % 15;
        doors[i].status = rand() % 2;
    }
}

tNode *init(struct door *doors)
{
    tNode *p_begin = NULL;
    tNode *p = NULL;
    p_begin = (tNode *)malloc(sizeof(tNode));
    p = p_begin;
    p->next = NULL;
    p->value[0] = doors[0].id;
    p->value[1] = doors[0].status;
    for (int k = 1; k < 15; k++)
    {
        p->next = (tNode *)malloc(sizeof(tNode));
        p = p->next;
        p->next = NULL;
        p->value[0] = doors[k].id;
        p->value[1] = doors[k].status;
    }
    return p_begin;
}

void delete_list(tNode *p_begin)
{
    tNode *p = p_begin;
    while (p != NULL)
    {
        tNode *tmp;
        tmp = p;
        p = p->next;
        free(tmp);
    }
}

void remove_door(tNode **head, int n)
{
    if (n == 0)
    {
        pop(head);
    }
    else
    {
        tNode *prev = getNth(*head, n - 1);
        tNode *elm = prev->next;
        int val[2];
        val[0] = elm->value[0];
        val[1] = elm->value[1];
        prev->next = elm->next;
        prev->value[0] = val[0];
        prev->value[1] = val[1];
        free(elm);
    }
}

tNode *getNth(tNode *head, int n)
{
    int counter = 0;
    while (counter < n && head)
    {
        head = head->next;
        counter++;
    }
    return head;
}

void pop(tNode **head)
{
    tNode *prev = NULL;
    int val[2];
    if (head == NULL)
    {
        exit(-1);
    }
    prev = (*head);
    val[0] = prev->value[0];
    val[1] = prev->value[1];
    prev->value[1] = val[1];
    (*head) = (*head)->next;
    free(prev);
}

tNode *add_door(tNode *elem, struct door *door)
{
    tNode *p = (tNode *)malloc(sizeof(tNode));
    p->value[0] = door[0].id;
    p->value[1] = door[0].status;
    p->next = elem->next;
    elem->next = p;

    return elem;
}

tNode *find_door(int door_id, tNode *root)
{
    tNode *p = root;
    while (p->next != NULL)
    {
        if (p->value[0] == door_id)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}