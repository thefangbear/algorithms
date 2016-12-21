#include <stdio.h>
#include <stdlib.h>
void swap(int *i, int *j) {
    register int temp = *i;
    *i = *j;
    *j = temp;
}

void stooge_sort(int *array, int i, int length) {
    length = length--;

    if(array[length] < array[i]) swap(&array[i], &array[length]);
    if(length - i + 1 > 2) {
        register int t = (length - i + 1) / 3;
        stooge_sort(array, i, length - t);
        stooge_sort(array, i + t, length);
        stooge_sort(array, i, length - t);
    }
}

int main(void) {
    int *arr = (int *)malloc(sizeof(int)*12);
    int i;
    printf("\n-=-=-=-=-=-=-=-=-=-\n");
    for(i = 0; i < 12; i++) {
        arr[i] = rand();
        printf("%d\n", arr[i]);
    }
    printf("\n-=-=-=-=-=-=-=-=-=-\n");
    int temp;
    stooge_sort(arr, 0, 12);
    for(i; i >= 0; i--) {
        printf("%d\n", arr[i]);
    }
    printf("\n-=-=-=-=-=-=-=-=-=-\n");
}


