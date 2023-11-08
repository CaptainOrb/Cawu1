#include <stdio.h>

void merge(int arr[], int start, int mid, int end){
    int leftLength = mid - start + 1;
    int rightLength = end - mid;

    int tmpL[50], tmpR[50];
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
    
    int mid = (start + end)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

int main(){
    int N;
    scanf("%d",&N);

    int arr[100];
    for (int i = 0; i < N; i++) scanf("%d",&arr[i]);

    mergeSort(arr, 0, N-1);
    for (int i = 0; i < N; i++){
        printf("%d", arr[i]);
        if (i < N-1) printf(" ");
        else printf("\n");
    }
}