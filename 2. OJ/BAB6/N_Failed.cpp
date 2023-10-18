#include <stdio.h>

int abs(int num){
    if (num < 0) num = -num;
    return num;
}

int convertCoordinate(char c){
    int tmp = c - 'A' + 1;
    return tmp;
}

void moveKnight(int *remainingMove, int xRange, int yRange,
char *xStart, char *yStart){
    // which quadrant
    if (xRange >= 0 && yRange >= 0){ // quadrant 1
    // printf("Quadrant 1\n");
        if (abs(xRange) >= abs(yRange)){
            *xStart += 2;
            *yStart += 1;
        }
        else if (abs(xRange) < abs(yRange)){
            *xStart += 1;
            *yStart += 2;
        }
    }
    else if (xRange < 0 && yRange >= 0){ // quadrant 2
    // printf("Quadrant 2\n");
        if (abs(xRange) >= abs(yRange)){
            *xStart -= 2;
            *yStart += 1;
        }
        else if (abs(xRange) < abs(yRange)){
            *xStart -= 1;
            *yStart += 2;
        }
    }
    else if (xRange < 0 && yRange < 0){ // quadrant 3
    // printf("Quadrant 3\n");
        if (abs(xRange) >= abs(yRange)){
            *xStart -= 2;
            *yStart -= 1;
        }
        else if (abs(xRange) < abs(yRange)){
            *xStart -= 1;
            *yStart -= 2;
        }
    }
    else if (xRange >= 0 && yRange < 0){ // quadrant 4
    // printf("Quadrant 4\n");
        if (abs(xRange) >= abs(yRange)){
            *xStart += 2;
            *yStart -= 1;
        }
        else if (abs(xRange) < abs(yRange)){
            *xStart += 1;
            *yStart -= 2;
        }
    }
    (*remainingMove)--;
}

bool knightCaptured(int remainingMove,
char xStart, char xEnd, char yStart, char yEnd){
    if (remainingMove >= 6) return true;
    while(true){
        // get range
        int xRange = xEnd - xStart;
        int yRange = yEnd - yStart;
        // knight logic (for 5x5 area around the knight)
        if (xRange == 0 && yRange == 0) return true; // arrived
        if (remainingMove == 0) return false; // no more movement allowed
        if (xRange == 0){ // vertical
            if (abs(yRange) == 1 && remainingMove >= 3) return true;
            else if (abs(yRange) == 2 && remainingMove >= 2) return true;
        }
        else if (yRange == 0){ // horizontal
            if (abs(xRange) == 1 && remainingMove >= 3) return true;
            else if (abs(xRange) == 2 && remainingMove >= 2) return true;
        }
        else if (remainingMove >= 2){ // diagonal short
            if (abs(xRange) == 1 && abs(yRange) == 1) return true;
        }
        else if (remainingMove >= 4){ // diagonal long
            if (abs(xRange) == 2 && abs(yRange) == 2) return true;
        }
        else if (remainingMove == 1){ // direct move
            if (abs(yRange) == 2 && abs(xRange) == 1
            || abs(yRange) == 1 && abs(xRange) == 2) return true;
        }
        // get closer to target
        moveKnight(&remainingMove, xRange, yRange, &xStart, &yStart);
    }
}

int main(){
    int T;
    scanf("%d",&T); getchar();
    for (int tc = 1; tc <= T; tc++){
        int maxMove;
        scanf("%d", &maxMove); getchar();
        maxMove *= 2;

        char startSquare[3];
        char endSquare[3];
        scanf("%s %s", startSquare, endSquare); getchar();
        int xStart = convertCoordinate(startSquare[0]);
        int xEnd = convertCoordinate(endSquare[0]);
        int yStart = startSquare[1];
        int yEnd = endSquare[1];

        printf("Case #%d: ", tc);
        if (knightCaptured(maxMove, xStart, xEnd, yStart, yEnd)) printf("YES\n");
        else printf("NO\n");
    }
}