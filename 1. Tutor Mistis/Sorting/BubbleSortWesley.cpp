/*
    SIMULASI SORTING
    Wesley Aldrich
    PPTI 17

    Bahan Belajar Kelompok Tutor Mistis: Bubble Sort (Optimized)
*/

#include <stdio.h>

// extra functions
void printArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int arr[], int size){
    int i, j;
    for (int i = 0; i < size-1; i++){
        bool sorted = true;
        for (int j = 0; j < size - 1 - i; j++){
            if (arr[j] > arr[j + 1]){
                sorted = false;
                swap(&arr[j], &arr[j + 1]);
            }
        }
        if (sorted) break;
    }
}

int main(){
    int nilaiAmbition[] = {98, 91, 92, 100, 63, 88, 100, 49};
    int size = sizeof(nilaiAmbition)/sizeof(nilaiAmbition[0]);

    printf("Initial Array:\n");
    printArray(nilaiAmbition, size);

    printf("Sorted Array:\n");
    bubbleSort(nilaiAmbition, size);
    printArray(nilaiAmbition, size);
}