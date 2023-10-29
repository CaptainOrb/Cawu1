#include <stdio.h>

void merge(int arr[], int start, int mid, int end){
    int leftLength = mid - start + 1;
    int rightLength = end - mid;

    int tmpL[20], tmpR[20];
    for (int i = 0; i < leftLength; i++) tmpL[i] = arr[start + i];
    for (int i = 0; i < rightLength; i++) tmpR[i] = arr[mid + 1 + i];

    int L = 0, R = 0, index = start;
    while (L < leftLength && R < rightLength){
        if (tmpL[L] <= tmpR[R]){
            arr[index] = tmpL[L];
            L++;
        }
        else{
            arr[index] = tmpR[R];
            R++;
        }
        index++;
    }
    while (L < leftLength){
        arr[index] = tmpL[L];
        L++;
        index++;
    }
    while (R < rightLength){
        arr[index] = tmpR[R];
        R++;
        index++;
    }
}

void mergeSort(int arr[], int start, int end){
    if (start >= end) return;
    int mid = start + (end - start)/2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    merge(arr, start, mid, end);
}

int getC(int arr[], int A, int B, int D, int E){
    int adQuota = 2, aeQuota = 2, bdQuota = 2, beQuota = 2,
        bbQuota = 1, ddQuota = 1;
    for (int i = 3; i <= 21; i++){
        if (arr[i] == A+D && adQuota > 0){
            arr[i] = 0;
            adQuota--;
        }
        else if (arr[i] == A+E && aeQuota > 0){
            arr[i] = 0;
            aeQuota--;
        }
        else if (arr[i] == B+D && bdQuota > 0){
            arr[i] = 0;
            bdQuota--;
        }
        else if (arr[i] == B+E && beQuota > 0){
            arr[i] = 0;
            beQuota--;
        }
        else if (arr[i] == B+B && bbQuota > 0){
            arr[i] = 0;
            bbQuota--;
        }
        else if (arr[i] == D+D && ddQuota > 0){
            arr[i] = 0;
            ddQuota--;
        }
    }
    for (int i = 21; i >= 3; i--){
        if (arr[i] != 0) return (arr[i] - E);
    }
}

int main(){
    int T;
    scanf("%d",&T);
    for (int tc = 1; tc <= T; tc++){
        int papers[30];
        for (int i = 0; i < 25; i++){
            scanf("%d",&papers[i]);
        }
        mergeSort(papers, 0, 24);
        int A = papers[0] / 2;
        int E = papers[24] / 2;
        int B = papers[1] - A;
        int D = papers[23] - E;
        int C = getC(papers, A, B, D, E);
        printf("Case #%d: %d %d %d %d %d\n",tc,A,B,C,D,E);
    }
}

/*
Test Case
3
5 7 6 7 10 8 2 3 4 11 11 3 4 5 6 8 9 7 8 9 4 6 7 8 12
2 3 4 5 6 3 4 5 6 7 4 5 6 7 8 5 6 7 8 9 6 7 8 9 10
3 3 4 4 2 2 3 3 3 2 3 2 3 3 2 2 2 3 2 2 3 3 4 4 3
*/

/*
ANALYSIS BOARD
2 3 4 5 6 3 4 5 6 7 4 5 6 7 8 5 6 7 8 9 6 7 8 9 10
(2 3 3) (4 4 4) (5 5 5 5) 6 6 6 6 6 (7 7 7 7) (8 8 8) (9 9 10)
3 3 4 4 2 2 3 3 3 2 3 2 3 3 2 2 2 3 2 2 3 3 4 4 3
(2 2 2) 2 2 2 2 2 2 3 3 3 3 3 3 3 3 3 3 3 3 4 (4 4 4)
*/

/*
A = letter[0]/2; = 1
E = letter[24]/2; = 2
B = letter[1|2]-A; = 1
D = E-letter[22|23]; = 2
*/