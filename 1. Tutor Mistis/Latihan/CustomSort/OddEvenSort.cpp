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
    FILE *fptr = fopen("ListAngka.mistis", "r");

    int T;
    fscanf(fptr, "%d\n", &T);
    for (int tc = 1; tc <= T; tc++){
        int N;
        fscanf(fptr, "%d\n", &N);

        int arr[100];
        for (int i = 0; i < N; i++){
            if (i < N-1) fscanf(fptr, "%d ", &arr[i]);
            else fscanf(fptr, "%d\n", &arr[i]);
        }

        mergeSort(arr, 0, N-1);

        bool first = true;
        for (int i = 1; i >= 0; i--){
            for (int j = 0; j < N; j++){
                if (arr[j] % 2 == i){
                    if (!first) printf(" ");
                    printf("%d", arr[j]);
                    first = false;
                }
            }
        }
        printf("\n");
    }
    fclose(fptr);
}