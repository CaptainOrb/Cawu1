#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <conio.h>

// functions
void reverse(char *str){
    int len = strlen(str);
    int l = 0;
    char tmp[100];
    while (l < len){
        tmp[l] = str[len-1-l]; l++;
    }
    strncpy(str, tmp, len);
}
bool isPalindrome(char *str){
    int len = strlen(str);
    int left = 0, right = len-1;
    while (left < right)
        if (str[left++] != str[right--]) return false;
    return true;
}
bool isIsogram(char *str){
    int len = strlen(str);
    int occurs[100] = {0};
    for (int i = 0; i < len; i++){
        occurs[str[i] - 'a']++;
        if (occurs[str[i] - 'a'] == 2) return false; 
    }
    return true;
}
bool isValidEmail(char *str){
    int len = strlen(str);
    for (int i = 0; i < len-12; i++){
        if (!isalnum(str[i])) return false;
    }
    if (strncmp(str+len-12, "@binus.ac.id", 12) == 0) return true;
    return false;
}
void showSubstrings(char *str){
    int len = strlen(str);
    for (int sublength = 1; sublength <= len; sublength++){
        char list[100][100];
        int listed = 0;
        for (int start = 0; start <= len-sublength; start++){
            char tmp[100];
            strncpy(tmp, str+start, sublength);
            bool unique = true;
            for (int i = 0; i < listed; i++){
                if (strcmp(list[i], tmp) == 0){
                    unique = false;
                    break;
                }
            }
            if (unique){
                strcpy(list[listed++], tmp);
                for (int i = 0; i < sublength; i++) printf("%c", tmp[i]);
                printf("\n");
            }
        }
    }
}

// screens
void mainMenu(){
    system("cls");
    for (int i = 1; i <= 50; i++) printf("=");
    printf("\nWelcome to String Processor!\n");
    for (int i = 1; i <= 50; i++) printf("=");
    printf("\n");

    printf("\nMenu:\n");
    printf("1. reverse(char *str)\n");
    printf("2. isPalindrome(char *str)\n");
    printf("3. isIsogram(char *str)\n");
    printf("4. isValidEmail(char *str)\n");
    printf("5. showSubstrings(char *str, int sublength)\n");
    printf("0. back()\n");
}
void exitScreen(){
    system("cls");
    printf("Thank you for visiting, Warriors!\n");
    printf("\nCode by Wesley Aldrich\n");
    printf("\nPress any button to exit...");
    getch();
}

int main(){
    int opt;
    do {
        mainMenu();
        printf("Choice: ");
        scanf("%d", &opt); getchar();
        if (opt == 1){
            char str[100];
            do {
                printf("Input your string: ");
                scanf("%[^\n]", str); getchar();
                if (str[0] == '0') main();
            } while (strlen(str) == 0);
            reverse(str);
            printf("Reversed: %s\n", str);
            getchar();
        }
        else if (opt == 2){
            char str[100];
            do {
                printf("Input your string: ");
                scanf("%[^\n]", str); getchar();
                if (str[0] == '0') main();
            } while (strlen(str) == 0);
            if (isPalindrome(str)) printf("YES!\n");
            else printf("NO!\n");
            getchar();
        }
        else if (opt == 3){
            char str[100];
            do {
                printf("Input your string: ");
                scanf("%[^\n]", str); getchar();
                if (str[0] == '0') main();
            } while (strlen(str) == 0);
            if (isIsogram(str)) printf("YES!\n");
            else printf("NO!\n");
            getchar();
        }
        else if (opt == 4){
            char str[100];
            do {
                printf("Input your string: ");
                scanf("%[^\n]", str); getchar();
                if (str[0] == '0') main();
            } while (strlen(str) == 0);
            if (isValidEmail(str)) printf("YES!\n");
            else printf("NO!\n");
            getchar();
        }
        else if (opt == 5){
            char str[100] = "";
            do {
                printf("Input your string: ");
                scanf("%[^\n]", str); getchar();
                if (str[0] == '0') main();
            } while (strlen(str) == 0);
            showSubstrings(str); getchar();
        }
    } while (true);
    exitScreen();
    return 0;
}