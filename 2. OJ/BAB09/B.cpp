#include <stdio.h>
#include <string.h>

char convertNum(char c){
    if (c == '0') return 'O';
    else if (c == '1') return 'I';
    else if (c == '3') return 'E';
    else if (c == '4') return 'A';
    else if (c == '5') return 'S';
    else if (c == '6') return 'G';
    else if (c == '7') return 'T';
    else if (c == '8') return 'B';
}

int main(){
    FILE *fptr = fopen("testdata.in", "r");

    int T;
    fscanf(fptr, "%d\n", &T);

    for (int tc = 1; tc <= T; tc++){
        int K;
        fscanf(fptr, "%d\n", &K);
        char str[1001] = {};
        fscanf(fptr, "%[^\n]\n", str);

        int len = strlen(str);

        for (int i = 0; i < len; i++){
            if (str[i] >= '0' && str[i] <= '9'){
                str[i] = convertNum(str[i]);
            }
        }
        for (int i = 0; i < len; i++){
            if (str[i] != ' '){
                str[i] -= K;
                if (str[i] < 'A') str[i] += 26;
            }
        }
        printf("Case #%d: %s\n", tc, str);
    }
    fclose(fptr);
}