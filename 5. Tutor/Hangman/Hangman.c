#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>

// vars
int lifePoint = 7;
bool gameOver = false;
bool win = false;

void holdScreen(){
    char tmp;
    do { tmp = getch();
    } while (tmp != '\r');
}
void winScreen(){
    printf("Congratulations! You've won!\n"); holdScreen();
    system("cls"); gameOver = true;
}
void loseScreen(char *key){
    printf("Oof! You've died!\n");
    printf("The word was %s!\n", key); holdScreen();
    system("cls"); gameOver = true;
}

void showHangman(){
    if (lifePoint == 0){
        printf(" ____\n");
        printf("|    |\n");
        printf("|    O      Remaining Attempt: 0\n");
        printf("|   /|\\\n");
        printf("|    |\n");
        printf("|   / \\\n");
        printf("|___\n");
        printf("|   |______\n");
        printf("|          |\n");
        printf("|__________|\n");
    }
    else if (lifePoint == 1){
        printf(" ____\n");
        printf("|    |\n");
        printf("|    O      Remaining Attempt: 1\n");
        printf("|   /|\\\n");
        printf("|    |\n");
        printf("|   /  \n");
        printf("|___\n");
        printf("|   |______\n");
        printf("|          |\n");
        printf("|__________|\n");
    }
    else if (lifePoint == 2){
        printf(" ____\n");
        printf("|    |\n");
        printf("|    O      Remaining Attempt: 2\n");
        printf("|   /|\\\n");
        printf("|    |\n");
        printf("|     \n");
        printf("|___\n");
        printf("|   |______\n");
        printf("|          |\n");
        printf("|__________|\n");
    }
    else if (lifePoint == 3){
        printf(" ____\n");
        printf("|    |\n");
        printf("|    O      Remaining Attempt: 3\n");
        printf("|   /|\\\n");
        printf("|     \n");
        printf("|     \n");
        printf("|___\n");
        printf("|   |______\n");
        printf("|          |\n");
        printf("|__________|\n");
    }
    else if (lifePoint == 4){
        printf(" ____\n");
        printf("|    |\n");
        printf("|    O      Remaining Attempt: 4\n");
        printf("|   /|  \n");
        printf("|     \n");
        printf("|     \n");
        printf("|___\n");
        printf("|   |______\n");
        printf("|          |\n");
        printf("|__________|\n");
    }
    else if (lifePoint == 5){
        printf(" ____\n");
        printf("|    |\n");
        printf("|    O      Remaining Attempt: 5\n");
        printf("|   / \n");
        printf("|     \n");
        printf("|     \n");
        printf("|___\n");
        printf("|   |______\n");
        printf("|          |\n");
        printf("|__________|\n");
    }
    else if (lifePoint == 6){
        printf(" ____\n");
        printf("|    |\n");
        printf("|    O      Remaining Attempt: 6\n");
        printf("|     \n");
        printf("|     \n");
        printf("|     \n");
        printf("|___\n");
        printf("|   |______\n");
        printf("|          |\n");
        printf("|__________|\n");
    }
    else if (lifePoint == 7){
        printf(" ____\n");
        printf("|    |\n");
        printf("|           Remaining Attempt: 7\n");
        printf("|     \n");
        printf("|     \n");
        printf("|     \n");
        printf("|___\n");
        printf("|   |______\n");
        printf("|          |\n");
        printf("|__________|\n");
    }
}
void showWord(char *key, bool reveals[]){
    printf("Word    : ");
    int len = strlen(key);
    for (int i = 0; i < len; i++){
        (reveals[i])? printf("%c", key[i]): printf("_");
        (i == len-1)? printf("\n"): printf(" ");
    }
}
void checkAnswer(char guess, char *key, bool reveals[]){
    int keyLen = strlen(key);
    bool correct = false;
    win = true;
    for (int i = 0; i < keyLen; i++){
        if (key[i] == guess){
            reveals[i] = true;
            correct = true;
        }
    }
    for (int i = 0; i < keyLen; i++)
        if (!reveals[i]) win = false;
    if (!correct) lifePoint--;
}

void mainScreen(char *key, bool reveals[]){
    system("cls");
    showHangman();
    showWord(key, reveals);
    if (win){
        winScreen(); return;
    }
    if (lifePoint == 0){
        loseScreen(key); return;
    }
    printf("Guess   : ");
    char guess[100];
    scanf("%[^\n]", guess); getchar();
    checkAnswer(guess[0], key, reveals);
}

void getKey(char *key){
    FILE *fptr = fopen("hangman.keys", "r");

    int index = rand() % 1000;
    char tmp[100] = "";
    for (int i = 0; i <= index; i++){
        fscanf(fptr, "%[^\n]\n", tmp);
    }
    strcpy(key, tmp);
    printf("Key = %s\n", key);
    printf("Tmp = %s\n", tmp);

    fclose(fptr);
}

void reset();
int main(){
    srand(time(NULL));
    system("cls");
    char key[100] = "";
    bool reveals[100] = {0};
    getKey(key);
    while (!gameOver) mainScreen(key, reveals);
    reset();
}

void reset(){
    lifePoint = 7;
    gameOver = false;
    win = false;
    main();
}