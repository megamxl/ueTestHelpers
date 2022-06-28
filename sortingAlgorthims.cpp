//
// Created by Maximilian Nowak on 28.06.22.
//

#include "sortingAlgorthims.h"
#include <string.h>


void selection_sort(element *stations, int size) {
    int currentMin = 0;

    /*
     * strcmp returns a value greater than zero when the matching character of left string
     * has greater ASCII value than the character of the right string
     */

    //looping over the array for all indexes ath a time
    for (int i = 0; i < size; ++i) {

        // setting my new current min to the element we are look at
        currentMin = i;

        // from now on loop over the array again and find out if there are smaller elements then the currentMin
        for (int currentItem = i; currentItem < size; ++currentItem) {

            // if jes assign it as the new current min
            if (strcmp(stations[currentMin].station_name, stations[currentItem].station_name) > 0) {
                currentMin = currentItem;
            }

            // check if the current min is not our element of the first loop
            // because we don't want to swap it if it is the same because we would just swap in a circle
            if (i != currentMin) {

                stations[i] = stations[currentMin];
            }
        }
    }
}


// because of left and right I guess it should be top down
void merge_sort(element *stations, element *tmpStations, int left, int right) {

    // check if recursion should stop
    if (left >= right) return;

    //calculating the new middle
    int middle = left + (right - left) / 2;

    // like bisection divide and conquer it from the actual standpoint
    merge_sort(stations, tmpStations, left, middle);
    merge_sort(stations, tmpStations, middle + 1, right);

    /***
     * Inspo from https://moodle.fh-campuswien.ac.at/pluginfile.php/956326/mod_resource/content/1/Mergesort.pdf
     * everything except merge is from brain
     * i am just too dump to merge
     */
    //assign all variables that I need to get the elements I want
    int i = left, j = right, k = left;

    // filling tmp to left array
    for (i; i <= middle; ++i) {
        tmpStations[k++] = stations[i];
    }

    // filling tmp to right
    for (j; j > middle; j--) {
        tmpStations[k++] = stations[j];
    }

    // assigning variables new for merging together after filling
    i = left;
    j = right;
    k = left;

    // merge it together until our current index exceeds the reduced max index
    while (i <= j) {
        // check if alphabetical deciding
        if (strcmp(tmpStations[i].station_name, tmpStations[j].station_name) >= 0) {
            // if yes set it to current k and make i bigger
            stations[k++] = tmpStations[i++];
        } else {
            // else set it to the last element in tmp and reduce the tmp index
            stations[k++] = tmpStations[j--];
        }
    }
}

// selection sort supporting custom compare function:
void selection_sort_fp(element *stations, int size, int (*comp)(element *, element *)) {
    int currentMin = 0;

    /*
     * strcmp returns a value greater than zero when the matching character of left string
     * has greater ASCII value than the character of the right string
     */

    //looping over the array for all indexes ath a time
    for (int i = 0; i < size; ++i) {

        // setting my new current min to the element we are look at
        currentMin = i;

        // from now on loop over the array again and find out if there are smaller elements then the currentMin
        for (int currentItem = i; currentItem < size; ++currentItem) {

            // if jes assign it as the new current min
            if (comp(&stations[currentMin], &stations[currentItem]) > 0) {
                currentMin = currentItem;
            }

            // check if the current min is not our element of the first loop
            // because we don't want to swap it if it is the same because we would just swap in a circle
            if (i != currentMin) {

                //swapping, could also be done without tmp but would still be 3 lines of code
                stations[i] = stations[currentMin];

            }
        }
    }

}

int compareByIcaoCode(element *a, element *b) {
    // get the sizes of all both elements
    return strcmp(a->icao_code, b->icao_code);
}

void bubble_sort(element *stations, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            if (strcmp(stations[j].station_name, stations[j + 1].station_name) > 0) {
                element tmp = stations[j + 1];
                stations[j + 1] = stations[j];
                stations[j] = tmp;
            }
        }
    }
}

void insertion_sort(element *stations, int size) {
    for (int i = 1; i < size; ++i) {
        int j = i;
        while (j > 0 && strcmp(stations[j - 1].station_name, stations[j].station_name) > 0) {
            element tmp = stations[j-1];
            stations[j - 1] = stations[j];
            stations[j] = tmp;
            j--;
        }
    }
}
