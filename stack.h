//
// Created by Maximilian Nowak on 28.06.22.
//

#ifndef ALLHELPERS_STACK_H
#define ALLHELPERS_STACK_H


struct _element {
    int value;
    struct _element * next;
};

typedef struct _element element;

struct _list {
    int count;
    struct _element * head;
    struct  _element * tail;
};

typedef struct _list list;


#endif //ALLHELPERS_STACK_H
