#include <stdio.h>

int binarySearch(int A[], int start, int end, int B){
    while (start <= end){
        int mid = start + (end - start)/2;

        if (B == A[mid]){
            for (int i = start; i <= mid; i++)
            if (B == A[i]) return i;
        }
        if (B < A[mid]) end = mid - 1;
        if (B > A[mid]) start = mid + 1;
    }
    return -2;
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);

    int A[100001], B;
    for (int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    
    int start = 0;
    int end = N-1;
    for (int i = 0; i < M; i++){
        scanf("%d", &B);

        int res = binarySearch(A, start, end, B);
        printf("%d\n", res + 1);
    }
}