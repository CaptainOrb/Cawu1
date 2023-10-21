/*
    SIMULASI SORTING
    Wesley Aldrich
    PPTI 17

    Bahan Belajar Kelompok Tutor Mistis: Quick Sort (Remake Revisi)
*/

#include <stdio.h>

// extra functions
void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
void printArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// necessary functions
void quickSort(int arr[], int size);
void quickSort_recursive(int arr[], int start, int end);

int main(){
    // int nilaiAmbition[] = {98, 91, 92, 100, 63, 88, 100, 49};
    int nilaiAmbition[] = {3, 3, 3, 3, 3, 2};
    int size = sizeof(nilaiAmbition)/sizeof(nilaiAmbition[0]);

    printf("Initial Array:\n");
    printArray(nilaiAmbition, size);

    printf("Sorted Array:\n");
    quickSort(nilaiAmbition, size);
    printArray(nilaiAmbition, size);
}

void quickSort(int arr[], int size){
    int start = 0;
    int end = size - 1;
    quickSort_recursive(arr, start, end);
}

void quickSort_recursive(int arr[], int start, int end) {
    if (start >= end) return;

    int pivot = arr[end];

    int left = start;
    int right = end;

    while (left <= right) {
        while (arr[left] < pivot) left++;
        while (arr[right] > pivot) right--;

        if (left <= right) {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }

    quickSort_recursive(arr, start, right);
    quickSort_recursive(arr, left, end);
}
