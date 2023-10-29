#include <stdio.h>

int abso(int num){
    if (num < 0) return -num;
    else return num;
}

int getArea(int stackSum){
    return 4 * stackSum;
}

int getPeri(int stacks[], int N){
    int horiBase = 4 * N;
    int vertBase = 0;
    if (N != 1){
        for (int i = 0; i < N-1; i++){
            vertBase += abso(stacks[i] - stacks[i+1]) * 2;
        }
    }
    int left = 2 * stacks[0];
    int right = 2 * stacks[N-1];
    vertBase += left + right;
    return vertBase + horiBase;
}

int main(){
    FILE *fptr = fopen("testdata.in", "r");

    int T;
    fscanf(fptr, "%d\n", &T);
    for (int i = 1; i <= T; i++){
        int N;
        fscanf(fptr, "%d\n", &N);

        int stacks[101] = {0};
        int stackSum = 0;
        for (int j = 0; j < N; j++){
            fscanf(fptr, "%d ", &stacks[j]);
            stackSum += stacks[j];
        }
        int x = getArea(stackSum);
        int y = getPeri(stacks, N);
        printf("Case #%d: %d %d\n", i, y, x);
    }
    fclose(fptr);
}