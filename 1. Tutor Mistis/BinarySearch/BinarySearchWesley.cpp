/*
    SIMULASI BINARY SEARCH
    Wesley Aldrich
    PPTI 17

    Bahan Belajar Kelompok Tutor Mistis: Binary Search
*/

#include <stdio.h>

// extra functions
void printArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// binary search functions (recursive or non-recursive)
int binarySearch(int arr[], int start, int end, int target){
    while (start <= end){
        int mid = start + (end - start)/2;
        // sama saja dengan (start+end)/2

        if (arr[mid] == target) return mid;
        else if (target < arr[mid]) end = mid - 1;
        else if (target > arr[mid]) start = mid + 1;
    }
    return -1; // when target not found
}
int binarySearch_recursive(int arr[], int start, int end, int target){
    if (start > end) return -1;

    int mid = start + (end - start)/2;
    // sama saja dengan (start+end)/2

    if (arr[mid] == target) return mid;
    else if (target < arr[mid]) binarySearch_recursive(arr, start, mid-1, target);
    else if (target > arr[mid]) binarySearch_recursive(arr, mid+1, end, target);
}

int main(){
    int nilaiAmbition[] = {49, 63, 88, 91, 92, 98, 100, 100};
    // int nilaiAmbition[] = {3, 3, 3, 3, 3, 2}; // problematic example
    int size = sizeof(nilaiAmbition)/sizeof(nilaiAmbition[0]);

    printArray(nilaiAmbition, size);

    printf("Search for:\n");
    printf(">> "); int target; scanf("%d",&target);

    // int index = binarySearch(nilaiAmbition, 0, size-1, target);
    int index = binarySearch_recursive(nilaiAmbition, 0, size-1, target);

    printf("Location of %d:\n", target);
    printf(">> [%d]\n", index);
}