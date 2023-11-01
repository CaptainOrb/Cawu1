#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int checkHistory(){
    FILE *fptr = fopen("ConvertString_History.orb", "r");
    int index = 0;
    while (!feof(fptr)) fscanf(fptr, "%d | %*[^\n]\n", &index);
    fclose(fptr);
    return index;
}

void convert(char *str){
    int len = strlen(str);
    for (int i = 0; i < len-1; i++){
        if (i == 0) str[i] = toupper(str[i]);
        else if (str[i] == ' ') str[i+1] = toupper(str[i+1]);
    }
    printf("Converted to: %s\n", str);
}

int main(){
    do {
        system("cls");
        printf("[CTRL + C] to EXIT\n");
        int index = checkHistory();
        FILE *fptr = fopen("ConvertString_History.orb", "a");

        char str[101];
        printf("Convert: ");
        scanf("%[^\n]", str); getchar();
        if (index > 0) fprintf(fptr, "\n");
        fprintf(fptr, "%02d | Convert: %s --> ", index+1, str);
        convert(str);
        fprintf(fptr, "%s", str);
        fclose(fptr);
    } while (true);
}