#include <stdio.h>
#include <string.h>

void merge(char letters[201], int start, int mid, int end){
    int leftLength = mid - start + 1;
    int rightLength = end - mid;
    char tmpL[101], tmpR[101];

    for (int i = 0; i < leftLength; i++)
        tmpL[i] = letters[start + i];
    for (int i = 0; i < rightLength; i++)
        tmpR[i] = letters[mid + 1 + i];

    int L = 0, R = 0, index = start;
    while (L < leftLength && R < rightLength){
        if (tmpL[L] <= tmpR[R])
            letters[index++] = tmpL[L++];
        else
            letters[index++] = tmpR[R++];
    }

    while (L < leftLength) letters[index++] = tmpL[L++];
    while (R < rightLength) letters[index++] = tmpR[R++];
}

void mergeSort(char letters[201], int start, int end){
    if (start >= end) return;

    int mid = start + (end - start)/2;
    mergeSort(letters, start, mid);
    mergeSort(letters, mid+1, end);
    merge(letters, start, mid, end);
}

void resort(char letters[][201], int size){
    bool sorted = true;
    for (int i = 0; i < size-1; i++){
        if (strcmp(letters[i], letters[i+1]) < 0){
            sorted = false;
            char tmp[201];
            strcpy(tmp, letters[i]);
            strcpy(letters[i], letters[i+1]);
            strcpy(letters[i+1], tmp);
        }
    }
    if (!sorted) resort(letters, size-1);
}

int main(){
    int R, C;
    scanf("%d %d",&R,&C); getchar();

    char letters[201][201];
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            scanf("%c", &letters[i][j]);
        }
        getchar();
    }

    // sort the letters
    for (int i = 0; i < R; i++) mergeSort(letters[i], 0, C-1);
    resort(letters, R);

    for (int i = 0; i < R; i++) printf("%s\n", letters[i]);
}