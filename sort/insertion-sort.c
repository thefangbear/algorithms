

void insertion_sort(int * arr, int size) {
  int i, j, key;
  for(i = 1; i < size; ++i) {
    key = arr[i];
    j = i - 1;
    while(j>0 && arr[j]<key) {
      arr[j+1]=arr[j];
    }
    arr[j]=key;
  }
}
