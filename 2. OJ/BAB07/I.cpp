#include <stdio.h>

void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void quickSort(int arr[], int start, int end){
    if (start >= end) return;

    int left = start;
    int right = end;
    int pivot = arr[end];

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

int main(){
    int T;
    scanf("%d",&T);
    for (int tc = 1; tc <= T; tc++){
        int N;
        scanf("%d",&N);

        int nums[500];
        for (int i = 0; i < N; i++) scanf("%d", &nums[i]);

        quickSort(nums, 0, N-1);

        int maxGap = 0;
        for (int i = 0; i < N-1; i++){
            if (i == N/2 - 1) continue;
            if (nums[i+1] - nums[i] > maxGap) maxGap = nums[i+1] - nums[i];
        }

        printf("Case #%d: %d\n", tc, maxGap);
    }
}