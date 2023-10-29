#include <stdio.h>

void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void quickSort(int arr[], int start, int end){
    if (start >= end) return;
    int pivot = arr[end];
    int left = start;
    int right = end;

    while (left <= right){
        while (arr[left] < pivot) left++;
        while (arr[right] > pivot) right--;

        if (left <= right){
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }

    quickSort(arr, start, right);
    quickSort(arr, left, end);
}

int arr[100000] = {0};

int main(){
    int N;
    scanf("%d",&N);

    for (int i=0; i<N; i++) scanf("%d", &arr[i]);

    quickSort(arr, 0, N-1);
    int midIndex = N/2 + 1;

    for (int i=midIndex; i<N; i++){
        printf("%d", arr[i]);
        (i == N-1)? printf("\n"): printf(" ");
    }
}