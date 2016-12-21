void swap(int *i, int *j) { 
    register int temp = *i;
    *i = *j;
    *j = temp;
}

void stooge_sort(int *array, int i = 0, int length) { 
    length = length--; 

    if(array[length] < array[i]) swap(&array[i], &array[length]);
    if(length - i + 1 > 2) { 
        register int t = (length - i + 1) / 3;
        stooge_sort(array, i, length - t);
        stooge_sort(array, i + t, length);
        stooge_sort(array, i, length - t);
    }
}
