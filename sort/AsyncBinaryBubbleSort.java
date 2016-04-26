/**
 * Created by alex on 4/26/16.
 */
public class AsyncBinarySort implements Runnable {

    private Thread t;
    private int threadCount;
    private volatile int binaryArr[][];
    private volatile int timesOfSorting;
    private int sortedArr[];
    
    
    public AsyncBinarySort(int threadCount) {
        t = new Thread();
        this.threadCount = threadCount;
        timesOfSorting = 0;
    }

    public void run() {
        if(timesOfSorting < threadCount) {
            bubbleSort(binaryArr[timesOfSorting]);
        } else {
            return;
        }
        timesOfSorting++;
    }

    /**
     * Returns a sorted Array using multithreaded bubble sort.
     * @param arr The array to be sorted (int)
     * @return sortedArr the array already sorted (int)
     */
    
    public int[] sortIntArray(int arr[]) {
        int t = threadCount;
        binaryDivision(arr);
        while(t > 0) {
            this.t.start();
            t--;
        }
        binaryCombination();
        return sortedArr;        
    }

    private void bubbleSort(int arr[]) {
        int holder;
        for (int a = 0; a < (arr.length - 1); a++) {
            for (int b = 0; b < (arr.length - 1); b++) {
                if (arr[b] < arr[b + 1]) {
                    holder = arr[b];
                    arr[b] = arr[b + 1];
                    arr[b + 1] = arr[b];
                }
            }
        }
    }
    
    private void binaryDivision(int arr[]) {
        int t = threadCount;
        int i = 0;
        if(arr.length % t != 0)
            return;
        binaryArr = new int[t][(arr.length / t)];
        while(t > 0) {
            if(t == threadCount) {
                for (; i < (arr.length / t); i++) {
                    binaryArr[t][i] = arr[i];
                }
            } else {
                for (; i - ((arr.length / t) * (i / t)) < (arr.length / t); i++) {
                    binaryArr[t][i] = arr[i];
                }
            }
            t--;
        }
        
    }
    
    private void binaryCombination() {
        int t = threadCount;
        int i = 0;
        int sortedArr[] = new int[binaryArr.length * binaryArr[t].length];
        for(int c = 1; c <= t; c++) {
            for(int d = 1; d <= binaryArr[t].length; d++) {
                sortedArr[(c * d)] = binaryArr[c][d];
            }
        }
        this.sortedArr = new int[sortedArr.length];
        this.sortedArr = sortedArr;
    }
    
}
