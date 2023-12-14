#include <stdio.h>

int binarySearch(int arr[], int size, int target){
    int start = 0, end = size-1;
    while (start <= end){
        int mid = (start+end)/2;

        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) start = mid+1;
        else end = mid-1;
    }
    return -1;
}

void merge(int arr[], int start, int mid, int end){
    int leftLength = mid - start + 1;
    int rightLength = end - mid;

    int tmpL[500], tmpR[500];
    for (int i = 0; i < leftLength; i++) tmpL[i] = arr[start+i];
    for (int i = 0; i < rightLength; i++) tmpR[i] = arr[mid+1+i];

    int L = 0, R = 0, index = start;
    while (L < leftLength && R < rightLength){
        if (tmpL[L] <= tmpR[R]) arr[index++] = tmpL[L++];
        else arr[index++] = tmpR[R++];
    }
    while (L < leftLength) arr[index++] = tmpL[L++];
    while (R < rightLength) arr[index++] = tmpR[R++];
}

void mergeSort(int arr[], int start, int end){
    if (start >= end) return;

    int mid = (start+end)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void quickSort(int arr[], int start, int end){
    if (start >= end) return;

    int pivot = arr[end];
    int L = start, R = end;
    while (L <= R){
        while (arr[L] < pivot) L++;
        while (arr[R] > pivot) R--;

        if (L <= R){
            swap(&arr[L], &arr[R]);
            L++; R--;
        }
    }

    quickSort(arr, start, R);
    quickSort(arr, L, end);
}