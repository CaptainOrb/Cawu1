#include <stdio.h>

void merge(int arr[], int start, int mid, int end){
    int leftLength = mid - start + 1;
    int rightLength = end - mid;

    int tmpL[2500], tmpR[2500];
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

int main(){
    int T;
    scanf("%d",&T);
    for (int tc = 1; tc <= T; tc++){
        int N;
        scanf("%d",&N);

        int nums[5000];
        double sum = 0;
        for (int i = 0; i < N; i++){
            scanf("%d",&nums[i]);
            sum += nums[i];
        }
        mergeSort(nums, 0, N-1);
        double mean, median;
        mean = sum/N;
        if (N & 1) median = nums[N/2];
        else median = (nums[N/2-1] + nums[N/2]) * 0.5;

        printf("Case #%d:\n", tc);
        printf("Mean : %.2lf\nMedian : %.2lf\n", mean, median);
    }
}