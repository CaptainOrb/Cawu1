#include <stdio.h>

void merge(int arr[], int start, int mid, int end){
    int leftLength = mid - start + 1;
    int rightLength = end - mid;

    int tmpL[50000], tmpR[50000];
    for (int i = 0; i < leftLength; i++) tmpL[i] = arr[start + i];
    for (int i = 0; i < rightLength; i++) tmpR[i] = arr[mid + 1 + i];

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

    int mid = start + (end - start)/2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

int binarySearch(int heights[], int start, int end, int target){
    if (start > end) return -1;
    int mid = start + (end - start)/2;

    if (heights[mid] == target) return mid+1;
    else if (heights[mid] < target) return binarySearch(heights, mid + 1, end, target);
    else if (heights[mid] > target) return binarySearch(heights, start, mid-1, target);
}

int main(){
    int N;
    scanf("%d",&N);
    int heights[100000];
    for (int i = 0; i < N; i++) scanf("%d", &heights[i]);

    mergeSort(heights, 0, N-1);

    int M;
    scanf("%d",&M);
    int call;
    for (int i = 0; i < M; i++){
        scanf("%d", &call);
        printf("%d\n", binarySearch(heights, 0, N-1, call));
    }
}