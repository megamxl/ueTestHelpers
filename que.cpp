//
// Created by Maximilian Nowak on 28.06.22.
//

#include "que.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

list *q_init() {
    // allocateing the space on the tack for acessing the list
    list *queStruct = (list *) malloc(sizeof(_list));

    // intially assinging the values
    *queStruct = {.count = 0, .head = NULL, .tail = NULL};

    // returning the ptr to reference it
    return queStruct;
}

void q_enqueue(list *lst, int value){
    element *newEntry = (element* ) malloc(sizeof (element));

    lst->count ++;
    newEntry->value = value;

    if(lst->head == NULL && lst->tail == NULL){
        newEntry->next = NULL;
        lst->head = newEntry;
        lst->tail = newEntry;
    } else {
        newEntry->next = lst->head;
        lst->head =newEntry;
    }

}

int q_dequeue(list *lst){
    element *tmp = lst->tail;
    //no element inside
    if(tmp == NULL){
        return NULL;
    }
        // only one element
    else if(tmp == lst->head){
        int ret = tmp->value;
        lst->count --;
        lst->head == NULL;
        lst->tail == NULL;
        free(tmp);

        return ret;
    }else{
        element *iterator = lst->head;
        int ret = tmp->value;
        lst->count --;
        while (iterator != NULL){
            if(iterator->next == lst->tail){
                lst->tail = iterator;
                iterator->next = NULL;
                break;
            }
            iterator = iterator->next;
        }
        free(tmp);
        return ret;
    }

}

int q_peek(list *lst){
    return lst->head->value;
}

void printQueue(list *lst){
    if(lst->head == NULL || lst->tail == NULL) {
        printf("no elements inside \n");
        return;
    }else {

        element *tmp = lst->head;
        while (tmp != NULL) {
            printf(" %d ->", tmp->value);
            tmp = tmp->next;
        }
        printf("\n");
        printf("head %d : \ntail %d : \n", lst->head->value, lst->tail->value);
        printf("\n");
    }
}
