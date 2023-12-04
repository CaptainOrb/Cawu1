/*
    N-Queen Problem

    Code: Captain Orb
*/

#include <bits/stdc++.h>

typedef int map[20][20]; // count from 1 to 9

int solution = 0;
map board = {0};

void printRes(int N){
    if (solution > 0) printf(",");
    printf("[");
    for (int i = 1; i <= N; i++){
        printf("\"");
        for (int j = 1; j <= N; j++){
            if (board[i][j] == 1) printf("Q");
            else printf(".");
        }
        printf("\"");
    }
    printf("]");
    solution++;
}

bool isAttacked(int row, int col){
    for (int i = 1; i <= row; i++) // check rook move
        if (board[i][col] == 1) return true;

    for (int i = 1; i <= row-1; i++){ // check bishop move
        if (board[row-i][col-i] == 1) return true;
        if (board[row-i][col+i] == 1) return true;
    }

    return false; // queen is not attacked
}

void reset(int N){
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            board[i][j] = 0;
}

void spawn(int row, int N){
    for (int col = 1; col <= N; col++){
        if (isAttacked(row, col)) continue; // skip if queen would be attacked

        board[row][col] = 1; // place the queen

        if (row == N) printRes(N); // print when all N queens placed
        else spawn(row+1, N); // otherwise, spawn more queen

        board[row][col] = 0; // remove the queen when backtracking
    }
}

int main(){
    int N;
    scanf("%d", &N);

    printf("[");

    // Note that N = 2 and N = 3 has no solution!
    if (N == 1) printf("[\"Q\"]");
    else spawn(1, N);

    printf("]");
    return 0;
}