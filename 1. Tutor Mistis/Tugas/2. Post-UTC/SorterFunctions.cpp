/*
    SORTER FUNCTIONS
    Wesley Aldrich (2702363613)
    PPTI 17

    Tugas ALGO LAB
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Vars
int array[10] = {};
bool empty = true;

// Additional Functions
void merge(int start, int mid, int end, int selection); // defined below

void swap (int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

// Main Functions
void mainMenu(){
    system("cls");
    printf("Sequence: ");
    if (empty) printf("[null]");
    else {
        for (int i = 0; i < 10; i++){
            printf("%d", array[i]);
            if (i < 9) printf(" ");
        }
    }
    printf("\n\n");
    printf("Sorter - by Wesley Aldrich\n");
    printf("==========================\n");
    printf("1. Randomize number in array\n");
    printf("2. Merge Sort\n");
    printf("3. Quick Sort\n");
    printf("4. Exit\n");
    printf(">> ");
}

void randomize(){
    for (int i = 0; i < 10; i++) array[i] = rand() % 101;
    empty = false;
}

void mergeSort(int start, int end, int selection){
    if (start >= end) return;
    int mid = start + (end-start)/2;

    mergeSort(start, mid, selection);
    mergeSort(mid+1, end, selection);
    merge(start, mid, end, selection);
}

void quickSort(int start, int end, int selection){
    if (start >= end) return;

    int left = start;
    int right = end;
    int pivot = array[end];
    while (left <= right){
        if (selection == 1){ // ascending
            while (array[left] < pivot) left++;
            while (array[right] > pivot) right--;
        }
        else { // descending
            while (array[left] > pivot) left++;
            while (array[right] < pivot) right--;
        }

        if (left <= right) swap(&array[left++], &array[right--]);
    }

    quickSort(start, right, selection);
    quickSort(left, end, selection);
}

int main(){
    srand(time(NULL));
    int input;
    do {
        mainMenu();
        scanf("%d", &input); getchar();

        if (input == 1) randomize();
        else if (input == 2){
            int selection;
            do {
                system("cls");
                printf("1. Ascending\n");
                printf("2. Descending\n");
                printf(">> ");
                scanf("%d", &selection); getchar();
            } while (selection < 1 || selection > 2);
            mergeSort(0, 9, selection);
        }
        else if (input == 3){
            int selection;
            do {
                system("cls");
                printf("1. Ascending\n");
                printf("2. Descending\n");
                printf(">> ");
                scanf("%d", &selection); getchar();
            } while (selection < 1 || selection > 2);
            quickSort(0, 9, selection);
        }
    } while (input != 4);

    printf("\nThank you for using this program!\n");
    getchar(); system("cls"); return 0;
}

void merge(int start, int mid, int end, int selection){
    int leftLength = mid - start + 1;
    int rightLength = end - mid;

    int tmpL[5], tmpR[5];
    for (int i = 0; i < leftLength; i++) tmpL[i] = array[start+i];
    for (int i = 0; i < rightLength; i++) tmpR[i] = array[mid+1+i];

    int L = 0, R = 0, index = start;
    while (L < leftLength && R < rightLength){
        if (selection == 1){ // ascending
            if (tmpL[L] <= tmpR[R]) array[index++] = tmpL[L++];
            else array[index++] = tmpR[R++];
        }
        else { // descending
            if (tmpL[L] > tmpR[R]) array[index++] = tmpL[L++];
            else array[index++] = tmpR[R++];
        }
    }
    while (L < leftLength) array[index++] = tmpL[L++];
    while (R < rightLength) array[index++] = tmpR[R++];
}