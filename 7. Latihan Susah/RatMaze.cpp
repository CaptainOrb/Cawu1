#include <stdio.h>

/*
    Used flags in the maze map:
    0 = walls;
    1 = available;
    -1 = taken;
*/

typedef int Map[4][4];
int size = 4;

// Main Case
// Map maze = {
//     {1, 0, 0, 0},
//     {1, 1, 0, 1},
//     {0, 1, 0, 0},
//     {1, 1, 1, 1}
// };

Map maze = { // Maze (free to edit)
    {1, 0, 1, 1},
    {1, 0, 0, 1},
    {1, 1, 1, 1},
    {1, 0, 0, 1}
};

int x = 0, y = 0; // Rat Position (free to edit)

struct Coordinate { // Target Position (free to edit)
    int x = 0;
    int y = 2;
} end;

bool safe(int x, int y){ // to check if the rat can exist in (x,y)
    if (x < 0 || y < 0 || x >= size || y >= size || maze[x][y] != 1){
        // printf("%d %d DEAD!\n", x, y);
        return false;
    }
    // printf("%d %d PASS!\n", x, y);
    return true;
}

bool check(int x, int y){ // to check if it's the correct path
    if (maze[x][y] == -1) return true;
    return false;
}

void showPath(int x, int y){ // to trace the correct path
    if (x == end.x && y == end.y) return;
    if (check(x+1, y)){
        printf("D");
        maze[x][y] = 1;
        showPath(x+1, y);
    }
    else if (check(x, y+1)){
        printf("R");
        maze[x][y] = 1;
        showPath(x, y+1);
    }
    else if (check(x-1, y)){
        printf("U");
        maze[x][y] = 1;
        showPath(x-1, y);
    }
    else if (check(x, y-1)){
        printf("L");
        maze[x][y] = 1;
        showPath(x, y-1);
    }
}

void ratMove(int x, int y){
    if (x == end.x && y == end.y){
        maze[x][y] = -1;
        showPath(0, 0);
        return;
    }
    
    if (safe(x, y)) {
        maze[x][y] = -1;

        ratMove(x+1, y);
        ratMove(x, y+1);
        ratMove(x-1, y);
        ratMove(x, y-1);

        maze[x][y] = 0;
    }
}

void printMap(){
    printf("\n\n");
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main(){
    ratMove(x, y);
    // printMap();
}