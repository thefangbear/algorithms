#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// radix sort

void radix_sort(int *array, int size, int max) {
    int *map = (int *)malloc(sizeof(int)*max);
    
    register int i;
    for(i = 0; i < size; i++) {
        map[array[i]-1]++;
    }
    
    for(i = 0; i < size; i++) {
        register int j, k = i;
        for(j = 0; j < map[k]; j++) {
            array[i++] = k;
        }
    }
    free(map);
}
