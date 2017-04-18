// std-C implementation of insertion sort in ascending order
// copyright (c) 2017 Conceptual-Inertia
// inertia@conceptualized.me

#include <stdio.h>
#include <stdlib.h>
#define INTLEN(s) sizeof(s)/sizeof(int)
int main(void) {
    
    int s[] = {0,9,234,346,234,1,6,3,7,4,3,5,23,6,436,3,6,4,63,4637,246436,23,46,35,47,235,74,3,75,3735,44,67,86,35,6};
    
    // print everything out.
    int k;
    for(k = 0; k < INTLEN(s); k ++) {
        printf("%d, ", s[k]);
    }
    printf("\n");
    
    int i;
    for(i = 1; i < INTLEN(s); i ++) {
        int j = i;
        while(j >= 0 && s[j-1]>s[j]) {
            int temp = s[j];
            s[j]=s[j-1];
            s[j-1]=temp;
            --j;
        }
    }
    
    // print everything out.
    for(k = 0; k < INTLEN(s); k++) {
        printf("%d, ", s[k]);
    }
    printf("\n");
    return 0;
}
