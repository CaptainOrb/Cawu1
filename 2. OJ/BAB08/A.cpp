#include <stdio.h>
#include <string.h>

char singkatan[101][101], arti[101][101];
bool first;

void find(char *str, int length, int listed){
    for (int i = 0; i < listed; i++){
        int len = length;
        if (strlen(singkatan[i]) > len) len = strlen(singkatan[i]);
        if (strncmp(str, singkatan[i], len) == 0){
            if (!first) printf(" ");
            printf("%s", arti[i]);
            first = false;
            return;
        }
    }
    if (!first) printf(" ");
    for (int i = 0; i < length; i++) printf("%c", str[i]);
    first = false;
    return;
}

int main(){
    FILE *fptr = fopen("testdata.in", "r");

    int N;
    fscanf(fptr, "%d\n", &N);

    for (int i = 0; i < N; i++){
        fscanf(fptr, "%[^#]#%[^\n]\n", singkatan[i], arti[i]);
    }

    int T;
    fscanf(fptr, "%d\n", &T);
    for (int i = 0; i < T; i++){
        first = true;
        char str[101];
        fscanf(fptr, "%[^\n]\n", str);

        int len = strlen(str);
        str[len] = ' ';
        int start = 0;
        int end = 0;
        printf("Case #%d:\n", i+1);
        while (end < len){
            end = start;
            // look for spaces
            while (str[end] != ' ' && end < len) end++;
            find(str + start, end-start, N);
            start = end + 1;
        }
        printf("\n");
    }          

    fclose(fptr);
}