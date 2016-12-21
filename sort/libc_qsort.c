#include <stdlib.h>
#include <stdio.h>
// https://en.wikibooks.org/wiki/Algorithm_Implementation/Sorting/Quicksort
static void swap(void *x, void *y, size_t l) {
   char *a = x, *b = y, c;
   while(l--) {
      c = *a;
      *a++ = *b;
      *b++ = c;
   }
}

static void sort(char *array, size_t size, int (*cmp)(void*,void*), int begin, int end) {
   if (end > begin) {
      void *pivot = array + begin;
      int l = begin + size;
      int r = end;
      while(l < r) {
         if (cmp(array+l,pivot) <= 0) {
            l += size;
         } else if ( cmp(array+r, pivot) > 0 )  {
            r -= size;
         } else if ( l < r ) {
            swap(array+l, array+r, size);
         }
      }
      l -= size;
      swap(array+begin, array+l, size);
      sort(array, size, cmp, begin, l);
      sort(array, size, cmp, r, end);
   }
}

void qsort(void *array, size_t nitems, size_t size, int (*cmp)(void*,void*)) {
   sort(array, size, cmp, 0, nitems*size);
}

typedef int type;

int type_cmp(void *a, void *b){ return (*(type*)a)-(*(type*)b); }

int main(void){ /* simple test case for type=int */
  int num_list[]={5,4,3,2,1};
  int len=sizeof(num_list)/sizeof(type);
  char *sep="";
  int i;
  qsort(num_list,len,sizeof(type),type_cmp);
  printf("sorted_num_list={");
  for(i=0; i<len; i++){
    printf("%s%d",sep,num_list[i]);
    sep=", ";
  }
  printf("};\n");
  return 0;
}
