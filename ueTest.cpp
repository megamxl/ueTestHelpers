//
// Created by Maximilian Nowak on 28.06.22.
//

#include "ueTest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

list *l_init() {
    list *lst = (list *) malloc(sizeof(list));
    lst->head = NULL;
    lst->count = 0;
    return lst;
}

void l_insert(list *lst, char *word) {
    element *new_data = (element *) malloc(sizeof(element));
    strcpy(new_data->word, word);
    new_data->next = lst->head;
    lst->head = new_data;
    lst->count++;
}

void l_delete(list *lst, char *word) {
    element *prev = NULL;
    element *cur = lst->head;
    element *next = lst->head->next;

    while (cur != NULL) {
        if (strcmp(cur->word, word) == 0) {
            if (cur == lst->head) {
                lst->head = next;
                lst->count = 0;
            } else {
                prev->next = next;
                lst->count --;
            }
            free(cur);
            return;
        }
        prev = cur;
        cur = cur->next;
        if(cur == NULL) return;
        next = cur->next;
    }
}

void l_reverse(list *lst) {
    element *prev = NULL;
    element *cur = lst->head;
    element *next = lst->head->next;

    while (cur != NULL) {
        cur->next = prev;
        prev =cur;
        cur = next;
        if(cur != NULL) next = cur->next;
    }
    lst->head = prev;
}

int l_isSet(list *lst) {
    if(lst == NULL) return -1;
    if(lst != NULL || lst->head !=NULL){
        element *tmp = lst->head;
        while (tmp != NULL) {
            if(l_find(lst,tmp->word) > 1){
                return 0;
            }
            tmp = tmp->next;
        }
        return 1;
    } else{
        return -1;
    }
}

void swap(element *a, element  *b)
{
    char temp [100];
    strcpy(temp, a->word);
    strcpy( a->word , b->word);
    strcpy( b->word , temp);
}

void l_sort(list *lst, int asc) {
    element *outside = lst->head;
    while (outside != NULL) {
        element *tmp = lst->head;
        while (tmp->next != NULL) {
            if(asc == 1){
                if(strcmp(tmp->word,tmp->next->word) > 0){
                    swap(tmp->next, tmp);
                }
            } else{
                if(strcmp(tmp->word,tmp->next->word) < 0){
                    swap(tmp->next, tmp);
                }
            }

            tmp = tmp->next;
        }
        outside = outside->next;
    }
}

void l_print(list *lst) {
    element *tmp = lst->head;
    while (tmp != NULL) {
        printf("%s -> ", tmp->word);

        tmp = tmp->next;
    }
    printf("\n");
}

int l_find(list *lst, char *word) {
    int count  =0;
    element *tmp = lst->head;
    while (tmp != NULL) {
        if (strcmp(tmp->word, word) == 0) {
            count++;
        }
        tmp = tmp->next;
    }
    return count;
}
