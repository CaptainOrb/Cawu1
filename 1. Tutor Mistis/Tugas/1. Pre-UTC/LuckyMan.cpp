#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void gameOver() {
    printf("\n\nPROGRAM EXITED!\n");
    printf("\nPress enter to exit...");
    getchar();
}

int addScore(int *ptrPlayerX, int *ptrPlayerY, int foodX[], int foodY[]){
    int deathNum = rand() % 5; // from 0 to 4, 20%

    if (*ptrPlayerX == foodX[0] && *ptrPlayerY == foodY[0]){
        foodX[0] = -1; foodY[0] = -1;
        if (0 == deathNum) return -1;
        return 1;
    }
    else if (*ptrPlayerX == foodX[1] && *ptrPlayerY == foodY[1]){
        foodX[1] = -1;
        foodY[1] = -1;
        if (0 == deathNum) return -1;
        return 1;
    }
    else if (*ptrPlayerX == foodX[2] && *ptrPlayerY == foodY[2]){
        foodX[2] = -1;
        foodY[2] = -1;
        if (0 == deathNum) return -1;
        return 1;
    }
    else return 0;
}

void gameScreen(int score, int *ptrPlayerX, int *ptrPlayerY, int foodX[], int foodY[]){
    system("cls");

    printf("===========\n");
    printf("SCORE: %d\n", score);
    printf("===========\n\n");

    printf("###########\n");
    for (int i = 0; i < 9; i++){
        printf("#");
        for (int j = 0; j < 9; j++){
            if (i == *ptrPlayerY && j == *ptrPlayerX) printf("$");
            else if (i == foodY[0] && j == foodX[0]) printf("*");
            else if (i == foodY[1] && j == foodX[1]) printf("*");
            else if (i == foodY[2] && j == foodX[2]) printf("*");
            else printf(" ");
        }
        printf("#\n");
    }
    printf("###########\n");
}

void randomFood(int foodPosX[], int foodPosY[]){
    foodPosX[0] = rand() % 9;
    foodPosY[0] = rand() % 9;
    do {
        foodPosX[1] = rand() % 9;
        foodPosY[1] = rand() % 9;
    } while (foodPosX[1] == foodPosX[0] && foodPosY[1] == foodPosY[0]);
    do {
        foodPosX[2] = rand() % 9;
        foodPosY[2] = rand() % 9;
    } while (foodPosX[2] == foodPosX[1] && foodPosY[2] == foodPosY[1] && foodPosX[2] == foodPosX[0] && foodPosY[2] == foodPosY[0]);
}

int main(){
    while (true){
        srand(time(NULL));
        char control;
        int saved = 0;

        int playerPosX = 0, playerPosY = 0;
        int *ptrPlayerPosX = &playerPosX;
        int *ptrPlayerPosY = &playerPosY;

        int score = 0;

        int foodPosX[3], foodPosY[3];
        randomFood(foodPosX, foodPosY);
        gameScreen(score, ptrPlayerPosX, ptrPlayerPosY, foodPosX, foodPosY);

        while (true){
            control = getch();
            if (control == 'w' && playerPosY != 0) playerPosY--;
            else if (control == 'a' && playerPosX != 0) playerPosX--;
            else if (control == 's' && playerPosY != 8) playerPosY++;
            else if (control == 'd' && playerPosX != 8) playerPosX++;
            else if (control == 'q'){
                gameOver();
                return -1;
            }

            int increment = addScore(ptrPlayerPosX, ptrPlayerPosY, foodPosX, foodPosY);
            if (increment == -1){
                printf("\n\nGAME OVER!\n");
                printf("\nPress enter to continue...");
                getchar(); break;
            }
            score += increment;
            if (score % 3 == 0 && score != saved){
                randomFood(foodPosX, foodPosY);
                saved = score;
            }

            gameScreen(score, ptrPlayerPosX, ptrPlayerPosY, foodPosX, foodPosY);
        }
    }
}