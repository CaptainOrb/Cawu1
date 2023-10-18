#include <stdio.h>

int minMove;

void knight (int move, int x, int y, int xTarget, int yTarget){
    if (move > minMove) return;

    if (x > 8 || x < 1 || y > 8 || y < 1){
        // printf("Out of bounds\n");
        return;
    }
    if (x == xTarget && y == yTarget){
        if (move < minMove) minMove = move;
        return;
    }

    // moves
    knight(move+1, x+1, y+2, xTarget, yTarget);
    knight(move+1, x+2, y+1, xTarget, yTarget);
    knight(move+1, x+2, y-1, xTarget, yTarget);
    knight(move+1, x+1, y-2, xTarget, yTarget);
    knight(move+1, x-1, y-2, xTarget, yTarget);
    knight(move+1, x-2, y-1, xTarget, yTarget);
    knight(move+1, x-2, y+1, xTarget, yTarget);
    knight(move+1, x-1, y+2, xTarget, yTarget);
}

int main(){
    int T;
    scanf("%d",&T); getchar();
    for (int tc = 1; tc <= T; tc++){

        minMove = 6;
        char startSquare[3];
        char endSquare[3];
        scanf("%s %s", startSquare, endSquare); getchar();

        int xStart = startSquare[0] - 'A' + 1;
        int xEnd = endSquare[0] - 'A' + 1;
        int yStart = startSquare[1] - '0';
        int yEnd = endSquare[1] - '0';
        // printf("%d ", xStart);
        // printf("%d\n", yStart);
        // printf("%d ", xEnd);
        // printf("%d\n", yEnd);
        knight(0, xStart, yStart, xEnd, yEnd);

        printf("Case #%d: ", tc);
        printf("%d\n", minMove);
    }
}