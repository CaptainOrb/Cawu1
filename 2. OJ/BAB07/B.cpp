#include <stdio.h>
#include <string.h>

void swapStr(int *num1, char str1[], int *num2, char str2[]){
    int tmpNum = *num1;
    *num1 = *num2;
    *num2 = tmpNum;

    char tmp[50];
    strcpy(tmp, str1);
    strcpy(str1, str2);
    strcpy(str2, tmp);
}

void quickSort(int nums[1000], char arr[][50], int start, int end, int compareIndex = 0){
    if (start >= end) return;
    char pivot = arr[end][compareIndex];
    int left = start;
    int right = end;

    while (left <= right){
        while (arr[left][compareIndex] < pivot) left++;
        while (arr[right][compareIndex] > pivot) right--;

        if (left <= right){
            swapStr(&nums[left], arr[left], &nums[right], arr[right]);
            left++;
            right--;
        }
    }

    quickSort(nums, arr, start, right, compareIndex);
    quickSort(nums, arr, left, end, compareIndex);
}

bool sorted;
void resort(int nums[1000], char arr[][50], int limit){
    sorted = true;
    for (int i = 0; i < limit-1; i++){
        if (arr[i][0] == arr[i+1][0]){
            int compareIndex = 0;
            while (arr[i][compareIndex] == arr[i+1][compareIndex]) compareIndex++;
            // sort
            if (arr[i][compareIndex] > arr[i+1][compareIndex]){
                swapStr(&nums[i], arr[i], &nums[i+1], arr[i+1]);
                sorted = false;
            }
        }
    }
}

int main(){
    FILE *fptr = fopen("testdata.in", "r");

    int N;
    fscanf(fptr, "%d\n", &N);

    int nums[1000];
    char plants[1001][50];
    for (int i = 0; i < N; i++){
        fscanf(fptr, "%d#%[^\n]\n", &nums[i], plants[i]);
    }

    // sort plants
    quickSort(nums, plants, 0, N-1);

    // resort for next char
    sorted = false;
    while (!sorted) resort(nums, plants, N);
    for (int i = 0; i < N; i++) printf("%d %s\n", nums[i], plants[i]);

    fclose(fptr);
}