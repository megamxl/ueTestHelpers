//
// Created by Maximilian Nowak on 28.06.22.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"
list *s_init() {
    // allocateing the space on the tack for acessing the list
    list *stackStruct = (list *) malloc(sizeof(_list));

    // intially assinging the values
    *stackStruct = {.count = 0, .head = NULL, .tail = NULL};

    // returning the ptr to reference it
    return stackStruct;
}


void s_push(list *lst, int value ){
    element *newEntry = (element *) malloc(sizeof (element));
    newEntry->value = value;
    lst->count++;

    if(lst->head == NULL){
        lst->head = newEntry;
        newEntry->next = NULL;
    }else{
        element *tmp = lst->head;
        lst->head = newEntry;
        newEntry->next = tmp;
    }
}

int s_pop(list *lst){
    if(lst->head == NULL){
        return NULL;
    } else{
        lst->count --;
        element *tmp = lst->head;
        lst->head = tmp->next;
        free(tmp);
        return lst->head->value;
    }
}

void printStack(list *lst){
    element *tmp = lst->head;
    while (tmp != NULL){
        printf(" %d \n", tmp->value);
        printf(" | \n");
        tmp = tmp->next;
    }
    printf("\n");
    printf("head %d : ", lst->head->value);
    printf("\n");
}