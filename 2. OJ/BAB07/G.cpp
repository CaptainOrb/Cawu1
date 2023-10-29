#include <stdio.h>

int changeCount;

void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void bubbleSort(int arr[], int size){
    bool sorted = true;
    for (int i = 0; i < size-1; i++){
        if (arr[i] > arr[i+1]){// swap
            swap(&arr[i], &arr[i+1]);
            changeCount++;
            sorted = false;
        }
    }
    if (!sorted) bubbleSort(arr, size-1);
}

int main(){
    int T;
    scanf("%d",&T);
    for (int tc = 1; tc <= T; tc++){
        changeCount = 0;
        int N, X;
        scanf("%d %d",&N,&X);

        int carriages[500];
        for (int i = 0; i < N; i++){
            scanf("%d", &carriages[i]);
        }

        bubbleSort(carriages, N);

        printf("Case #%d: %d\n", tc, changeCount * X);
    }
}