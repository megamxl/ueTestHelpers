//
// Created by Maximilian Nowak on 28.06.22.
//

#ifndef ALLHELPERS_LIST_H
#define ALLHELPERS_LIST_H

struct _element {
    char word[100]; // value = station_name
    struct _element * next;
};

typedef struct _element element;

struct _list
{
    element * head;
    int count;
};

typedef struct _list list;

list *    l_init(void);
void      l_insert(list * lst, char * word);
void      l_delete(list * lst, char * word);
void      l_print(list * lst);
element * l_find(list * lst, char * word);

#endif //ALLHELPERS_LIST_H
