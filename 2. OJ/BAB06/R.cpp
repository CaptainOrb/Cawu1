#include <stdio.h>

int wall;
int height, width;

void flood(int x, int y, char map[101][101]){
    if (x < 0 || y < 0 || x >= height
    || y >= width || map[x][y] == '#')
    return;

    // printf("%d %d\n", x, y);
    if (map[x][y] == '.') wall++;
    map[x][y] = '#';

    // move
    flood(x+1, y, map);
    flood(x-1, y, map);
    flood(x, y+1, map);
    flood(x, y-1, map);
}

int main(){
    int T;
    scanf("%d",&T); getchar();
    for (int tc = 1; tc <= T; tc++){
        wall = 0; // reset wall
        char map[101][101];
        scanf("%d %d", &height, &width); getchar();

        int posX, posY;
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                scanf("%c", &map[i][j]);
                if (map[i][j] == 'S'){
                    posX = i; posY = j;
                }
            }
            getchar();
        }
        flood(posX, posY, map);
        printf("Case #%d: %d\n", tc, wall);
    }
}