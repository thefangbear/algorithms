#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10240000

int comp (const void * elem1, const void * elem2)  {
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}


int main(int argc, char* argv[]) {
    int *x = (int *)malloc(sizeof(int) * MAX_SIZE );
    int i, j;
    
    for(i = 0; i < MAX_SIZE; i++) {
        printf("%d\n", x[i]);
    }
    
    qsort (x,           /* array/memory space to be sorted */
           MAX_SIZE,    /* total number of elements        */ 
           sizeof(int), /* size of one element in array    */
           comp         /* pointer to comparator function  */
          );

    
    for (i ; i > 0 ; i--) {
        printf ("%d ", x[i]);
    }
    
    return 0;
}
