/*
    SIMULASI SORTING
    Wesley Aldrich
    PPTI 17

    Bahan Belajar Kelompok Tutor Mistis: Merge Sort
*/

#include <stdio.h>

// extra functions
void printArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// pre-define the merge sort functions
void mergeSort(int arr[], int size);
void mergeSort_recursive(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main(){
    int nilaiAmbition[] = {98, 91, 92, 100, 63, 88, 100, 49};
    int size = sizeof(nilaiAmbition)/sizeof(nilaiAmbition[0]);

    printf("Initial Array:\n");
    printArray(nilaiAmbition, size);

    printf("Sorted Array:\n");
    mergeSort(nilaiAmbition, size);
    printArray(nilaiAmbition, size);
}

void mergeSort(int arr[], int size){
    int left = 0;
    int right = size - 1;
    mergeSort_recursive(arr, left, right);
}

void mergeSort_recursive(int arr[], int left, int right){
    if (left == right) return; // return when the size is 1

    int mid = left + (right - left)/2;

    mergeSort_recursive(arr, left, mid);
    mergeSort_recursive(arr, mid+1, right);

    merge(arr, left, mid, right);
}

void merge(int arr[], int left, int mid, int right){
    int leftLength = mid - left + 1;
    int rightLength = right - mid;

    // build temporary arrays
    int tmpL[100], tmpR[100];

    // fill the temporary arrays
    for (int i = 0; i < leftLength; i++) tmpL[i] = arr[left + i];
    for (int i = 0; i < rightLength; i++) tmpR[i] = arr[mid + 1 + i];

    // compare the temporary arrays
    int i = 0, j = 0, k = left;
    while (k <= right){
        if (tmpL[i] <= tmpR[j] || (i < leftLength && j >= rightLength)){
            // this condition also happens when j is out of range
            arr[k] = tmpL[i];
            i++;
        }
        else{
            arr[k] = tmpR[j];
            j++;
        }
        k++;
    }
}