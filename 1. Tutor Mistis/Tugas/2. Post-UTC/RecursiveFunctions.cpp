/*
    RECURSIVE FUNCTIONS
    Wesley Aldrich (2702363613)
    PPTI 17

    Tugas ALGO LAB
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

unsigned long long factorial(int num){
    if (num > 65) return 0;
    if (num == 0) return 1;
    return num * factorial(num-1);
}

bool palindrome(char str[], int start, int end){
    if (start >= end) return true;
    else if (str[start] == str[end]) return palindrome(str, start+1, end-1);
    else return false;
}

int gcd(int x, int y){
    if (x < y) swap(&x, &y);
    if (y == 0) return x; // immediately return when there exist 0.
    if (x % y == 0)return y;
    return gcd(y, x % y);
}

void bubbleSort(int arr[], int size){
    int i, j;
    for (int i = 0; i < size-1; i++){
        bool sorted = true;
        for (int j = 0; j < size - 1 - i; j++){
            if (arr[j] > arr[j + 1]){
                sorted = false;
                swap(&arr[j], &arr[j + 1]);
            }
        }
        if (sorted) break;
    }
}

int main(){
    int input;
    do {
        system("cls");
        printf("Recursive Functions\n");
        printf("===================\n");
        printf("1. Factorial\n");
        printf("2. Palindrome\n");
        printf("3. Greatest Common Divisor\n");
        printf("4. Bubble Sort\n");
        printf("5. Exit\n");
        printf(">> ");
        scanf("%d", &input); getchar();

        if (input == 1){
            int number;
            do {
                system("cls");
                printf("Input the number you want: ");
                scanf("%d", &number); getchar();
            } while (number < 0);
            unsigned long long res = factorial(number);
            if (res == 0) printf("The factorial of %d is beyond 10^19!\n", number);
            else printf("The factorial of %d is %llu\n", number, res);

            printf("Press enter to continue...");
            getchar();
        }
        else if (input == 2){
            char str[101];
            int len;
            do {
                system("cls");
                printf("Input the string you want: ");
                scanf("%[^\n]", str); getchar();
                len = strlen(str);
            } while (len < 1 || len > 100);

            if (palindrome(str, 0, len-1)){
                printf("%s is a palindrome!\n", str);
            }
            else {
                printf("%s is not a palindrome!\n", str);
            }
            printf("Press enter to continue...");
            getchar();
        }
        else if (input == 3){
            int a, b;
            do {
                system("cls");
                printf("Input the two numbers you want: ");
                scanf("%d %d", &a, &b); getchar();
            } while (a < 0 || b < 0);
            int res = gcd(a, b);
            printf("The GCD of %d and %d is %d.\n", a, b, res);
            printf("Press enter to continue...");
            getchar();
        }
        else if (input == 4){
            int arr[1001];
            int N;
            do {
                system("cls");
                printf("Please input the array size: ");
                scanf("%d", &N); getchar();
            } while (N < 1);
            for (int i = 0; i < N; i++){
                scanf("%d", &arr[i]); getchar();
            }
            bubbleSort(arr, N);
            printf("Here is your sorted array:\n");
            for (int i = 0; i < N; i++){
                printf("%d", arr[i]);
                if (i < N - 1) printf(" ");
            }
            printf("\n");
            printf("Press enter to continue...");
            getchar();
        }

    } while (input != 5);
    system("cls");
    printf("Program finished, press enter to exit...");
    getchar();
    system("cls");
}