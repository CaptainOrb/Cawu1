#include <stdio.h>
#include <string.h>

void merge(char nim[][11], char name[][25], int start, int mid, int end){
    int leftLength = mid - start + 1;
    int rightLength = end - mid;

    char tmpL[500][11], tmpR[500][11];
    char nameL[500][25], nameR[500][25];
    for (int i = 0; i < leftLength; i++){
        strcpy(tmpL[i], nim[start + i]);
        strcpy(nameL[i], name[start + i]);
    }
    for (int i = 0; i < rightLength; i++){
        strcpy(tmpR[i], nim[mid + 1 + i]);
        strcpy(nameR[i], name[mid + 1 + i]);
    }

    int L = 0, R = 0, index = start;
    while (L < leftLength && R < rightLength){
        if (strcmp(tmpL[L], tmpR[R]) < 0){
            strcpy(nim[index], tmpL[L]);
            strcpy(name[index], nameL[L]);
            L++;
        }
        else{
            strcpy(nim[index], tmpR[R]);
            strcpy(name[index], nameR[R]);
            R++;
        }
        index++;
    }
    while (L < leftLength){
        strcpy(nim[index], tmpL[L]);
        strcpy(name[index], nameL[L]);
        L++;
        index++;
    }
    while (R < rightLength){
        strcpy(nim[index], tmpR[R]);
        strcpy(name[index], nameR[R]);
        R++;
        index++;
    }
}

void mergeSort(char nim[][11], char name[][25], int start, int end){
    if (start >= end) return;
    int mid = start + (end-start)/2;

    mergeSort(nim, name, start, mid);
    mergeSort(nim, name, mid+1, end);
    merge(nim, name, start, mid, end);
}

int main(){
    FILE *fptr = fopen("testdata.in", "r");

    int N;
    fscanf(fptr, "%d\n", &N);
    char nim[1001][11];
    char name[1001][25];
    for (int i = 0; i < N; i++){
        fscanf(fptr, "%s %s\n", nim[i], name[i]);
    }

    mergeSort(nim, name, 0, N-1);

    for (int i = 0; i < N; i++){
        printf("%s %s\n", nim[i], name[i]);
    }
    fclose(fptr);
}