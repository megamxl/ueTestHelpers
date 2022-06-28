//
// Created by Maximilian Nowak on 28.06.22.
//

#ifndef ALLHELPERS_SORTINGALGORTHIMS_H
#define ALLHELPERS_SORTINGALGORTHIMS_H

#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
struct _element {
    char icao_code[5];
    char station_name[100];
};

typedef struct _element element;

void selection_sort(element* stations, int size);
void bubble_sort(element* stations, int size);
void insertion_sort(element* stations, int size);
void merge_sort(element* stations, element* tmpStations, int left, int right);
// selection sort supporting custom compare function:
void selection_sort_fp(element* stations, int size, int (*comp)(element*, element*));
int compareByIcaoCode(element* a, element* b);

#endif //ALLHELPERS_SORTINGALGORTHIMS_H
