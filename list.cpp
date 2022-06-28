//
// Created by Maximilian Nowak on 28.06.22.
//

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>


list * l_init() {
    list * lst = (list *)malloc(sizeof(list));
    lst->head = NULL;
    lst->count = 0;
    return lst;
}

void l_insert(list * lst,  char * word)
{
    element * new_data = (element *)malloc(sizeof(element));
    strcpy(new_data->word, word);
    new_data->next = lst->head;
    lst->head = new_data;
    lst->count++;
}

void l_delete(list * lst, char * word)
{
    element * tmp = lst->head;
    element * prv = NULL;
    while (tmp != NULL) {
        if (strcmp(tmp->word, word) == 0) {
            if (prv == NULL) {
                lst->head = tmp->next;
            }
            else {
                prv->next = tmp->next;
            }
            free(tmp);
            lst->count--;
            return;
        }
        prv = tmp;
        tmp = tmp->next;
    }
}

void l_print(list * lst) {
    element * tmp = lst->head;
    while (tmp != NULL) {
        printf("%s: \n", tmp->word);

        tmp = tmp->next;
    }
}

element * l_find(list * lst, char * word)
{
    element * tmp = lst->head;
    while (tmp != NULL) {
        if (strcmp(tmp->word, word) == 0) {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}