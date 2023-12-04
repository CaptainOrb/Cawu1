#include <stdio.h>
#include <string.h>

typedef struct string {
    char str[120];
} string;

void merge(string str[10001], int start, int mid, int end){
    int leftLength = mid - start + 1;
    int rightLength = end - mid;

    string tmpL[5010], tmpR[5010];
    for (int i = 0; i < leftLength; i++){
        tmpL[i] = str[start+i];
    }
    for (int i = 0; i < rightLength; i++){
        tmpR[i] = str[mid+1+i];
    }

    int L = 0, R = 0, index = start;
    while (L < leftLength && R < rightLength){
        if (strcmp(tmpL[L].str, tmpR[R].str) <= 0){
            str[index++] = tmpL[L++];
            // strcpy(arr[index], tmpL[L]);
            // index++; L++;
        }
        else{
            str[index++] = tmpR[R++];
            // strcpy(arr[index], tmpR[R]);
            // index++; R++;
        } 
    }
    while (L < leftLength){
        str[index++] = tmpL[L++];
        // strcpy(arr[index], tmpL[L]);
        // index++; L++;
    }
    while (R < rightLength){
        str[index++] = tmpR[R++];
        // strcpy(arr[index], tmpR[R]);
        // index++; R++;
    }
}

void mergeSort(string str[10001], int start, int end){
    if (start >= end) return;

    int mid = (start+end)/2;
    mergeSort(str, start, mid);
    mergeSort(str, mid+1, end);
    merge(str, start, mid, end);
}

int main(){
    int n;
    scanf("%d", &n); getchar();
    string str[10001];
    for (int i = 0; i < n; i++){
        scanf("%s", str[i].str); getchar();
    }
    mergeSort(str, 0, n-1);
    for (int i = 0; i < n; i++) printf("%s\n", str[i].str);
    return 0;
}