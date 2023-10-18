/*
    QUICKSORT ATTEMPT
    Wesley Aldrich (2702363613)
    PPTI 17

    TESTING
*/

#include <stdio.h>

void swap(int *x, int *y){
    printf("Swapping %d with %d\n", *x, *y);
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int printArr(int arr[], int start, int end){
    for (int i = start; i <= end; i++) printf("%d ", arr[i]);
    printf("\n");
}

int midData(int arr[], int a, int b, int c){
    if (arr[a] <= arr[b] && arr[b] <= arr[c] || arr[c] <= arr[b] && arr[b] <= arr[a]) return b;
    else if (arr[b] <= arr[a] && arr[a] <= arr[c] || arr[c] <= arr[a] && arr[a] <= arr[b]) return a;
    else if (arr[a] <= arr[c] && arr[c] <= arr[b] || arr[b] <= arr[c] && arr[c] <= arr[a]) return c;

    return -1; // unexpected error code
}

void pushPivot(int arr[], int start, int end){
    int mid = start + (end - start)/2;
    int pivotPos = midData(arr, start, mid, end);
    printf("Initial Pivot (value): %d\n", arr[pivotPos]);
    printf("Initial Pivot (index): %d\n", pivotPos);
    swap(&arr[pivotPos], &arr[end]); // put the selected pivot value to the end
}

void quickSort(int arr[], int start, int end){
    if (start < end){
        printf("Start Pivot (index): %d\n", end);
        int pivot = arr[end];
        int leftPointer = start, rightPointer = end - 1;
        while (leftPointer < rightPointer){
            while (arr[leftPointer] < pivot) leftPointer++;
            while (arr[rightPointer] > pivot) rightPointer--;

            if (leftPointer >= rightPointer) break;

            printf("DETECTED INDEX (pointers): %d %d\n", leftPointer, rightPointer);
            swap(&arr[leftPointer], &arr[rightPointer]);
            printArr(arr, 0, 6);
        }

        printf("DETECTED INDEX (reset pivot): %d %d\n", end, leftPointer);
        swap(&arr[end], &arr[leftPointer]);
        printArr(arr, 0, 6);
        printf("End Pivot (index): %d\n", leftPointer);
        printf("\n");
        
        quickSort(arr, start, leftPointer-1);
        quickSort(arr, leftPointer+1, end);
    }
}

void advancedQuickSort(int arr[], int start, int end){
    pushPivot(arr, start, end);
    printArr(arr, 0, 6); printf("\n");
    quickSort(arr, start, end);
}

int main(){
    int arr[] = {13, 1, 2, 15, 23, 23, 29}; // sample unsorted array
    int end = sizeof(arr)/sizeof(arr[0]) - 1;
    printf("%d\n", end);

    printf("Unsorted Array:\n");
    printArr(arr, 0, end);
    printf("\n");

    // sort immediately
    // quickSort(arr, 0, end);

    // find the median of three before sorting
    advancedQuickSort(arr, 0, end);

    printf("Sorted Array:\n");
    printArr(arr, 0, end);
}