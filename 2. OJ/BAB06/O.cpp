#include <stdio.h>

int food;
int height, width;

void pacmon(int x, int y, char map[101][101]){
    if (x < 0 || y < 0 || x >= height
    || y >= width || map[x][y] == '#')
    return;

    // printf("%d %d\n", x, y);
    if (map[x][y] == '*') food++;
    map[x][y] = '#';

    // move
    pacmon(x+1, y, map);
    pacmon(x-1, y, map);
    pacmon(x, y+1, map);
    pacmon(x, y-1, map);
}

int main(){
    int T;
    scanf("%d",&T); getchar();
    for (int tc = 1; tc <= T; tc++){
        food = 0; // reset food
        char map[101][101];
        scanf("%d %d", &height, &width); getchar();

        int posX, posY;
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                scanf("%c", &map[i][j]);
                if (map[i][j] == 'P'){
                    posX = i; posY = j;
                }
            }
            getchar();
        }
        pacmon(posX, posY, map);
        printf("Case #%d: %d\n", tc, food);
    }
}