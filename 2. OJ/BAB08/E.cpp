#include <stdio.h>

void merge(int arr[], int start, int mid, int end){
    int leftLength = mid - start + 1;
    int rightLength = end - mid;

    int tmpL[500], tmpR[500];
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

        int MMRs[1000] = {0};
        for (int i = 0; i < N; i++)
            scanf("%d",&MMRs[i]);

        mergeSort(MMRs, 0, N-1);

        bool found = false;
        int playerMMR;
        scanf("%d",&playerMMR);
        printf("CASE #%d: ", tc);
        for (int i = 0; i < N; i++){
            if (playerMMR == MMRs[i]){
                found = true;
                if (i == N-1) printf("%d %d\n", MMRs[i-1], playerMMR);
                else printf("%d %d\n", playerMMR, MMRs[i+1]);
                break;
            }
        }
        if (!found) printf("-1 -1\n");
    }
}