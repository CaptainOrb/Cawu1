#include <stdio.h>

void swap(long long *x, long long *y){
    long long tmp = *x;
    *x = *y;
    *y = tmp;
}

long long abs(long long int x){
    if (x < 0) return -x;
    return x;
}

void quickSort(long long arr[], int start, int end){
    if (start >= end) return;
    long long pivot = arr[end];
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

long long int arr[100009] = {0};
long long int gap[100009] = {0};

int main(){
    int N;
    scanf("%d",&N);
    
    for (int i=0; i<N; i++){
        scanf("%lld",&arr[i]);
    }
    quickSort(arr, 0, N-1);

    long long maxGap = 0;
    for (int i = 0; i < N-1; i++){
        gap[i] = abs(arr[i] - arr[i+1]);
        if (gap[i] > maxGap) maxGap = gap[i];
    }

    bool first = true; // don't print space at first
    for (int i = 0; i < N-1; i++){
        if (gap[i] == maxGap){
            if (!first) printf(" ");
            printf("%lld %lld", arr[i], arr[i+1]);
            first = false;
        }
    }
    printf("\n");
}