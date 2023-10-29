#include <stdio.h>
#include <string.h>

typedef struct course {
    char name[11];
    int deadline;
} course;

void merge(course data[], int start, int mid, int end){
    int leftLength = mid - start + 1;
    int rightLength = end - mid;

    course tmpL[50], tmpR[50];
    for (int i = 0; i < leftLength; i++) tmpL[i] = data[start+i];
    for (int i = 0; i < rightLength; i++) tmpR[i] = data[mid+1+i];

    int L = 0, R = 0, index = start;
    while (L < leftLength && R < rightLength){
        if (tmpL[L].deadline < tmpR[R].deadline){
            data[index++] = tmpL[L++];
        }
        else if (tmpL[L].deadline == tmpR[R].deadline){
            if (strcmp(tmpL[L].name, tmpR[R].name) > 0){
                data[index++] = tmpR[R++];
            }
            else {
                data[index++] = tmpL[L++];
            }
        }
        else {
            data[index++] = tmpR[R++];
        }
    }

    while (L < leftLength) data[index++] = tmpL[L++];
    while (R < rightLength) data[index++] = tmpR[R++];
}

void mergeSort(course data[], int start, int end){
    if (start >= end) return;

    int mid = start + (end-start)/2;
    mergeSort(data, start, mid);
    mergeSort(data, mid+1, end);

    merge(data, start, mid, end);
}

int main(){
    course data[100];
    int N;
    scanf("%d", &N); getchar();
    for (int i = 0; i < N; i++){
        scanf("%s %d", data[i].name, &data[i].deadline);
    }

    mergeSort(data, 0, N-1);

    for (int i = 0; i < N; i++){
        printf("%s\n", data[i].name);
    }
}