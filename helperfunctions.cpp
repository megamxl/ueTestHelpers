//
// Created by Maximilian Nowak on 28.06.22.
//

#include <cstring>

struct _element {
    char word[100]; // value = station_name
    struct _element * next;
};

typedef struct _element element;


int asciiSize(char *str) {
    int sum = 0;
    int i = 0;
    while (str[i]) {
        sum += str[i];
        i++;
    }
    return sum;
}

void swap(element *a, element  *b)
{
    char temp [100];
    strcpy(temp, a->word);
    strcpy( a->word , b->word);
    strcpy( b->word , temp);
}