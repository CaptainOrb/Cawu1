#include <stdio.h>
#include <string.h>

int main(){
    FILE *fptr;
    fptr = fopen("testdata.in", "r");

    int T;
    fscanf(fptr, "%d\n", &T);

    for (int tc = 1; tc <= T; tc++){
        char str[101] = "";
        fscanf(fptr, "%[^\n]\n", str);

        int len = strlen(str);
        int denyChange[26] = {0};
        int change;
        fscanf(fptr, "%d\n", &change);
        for (int i = 0; i < change; i++){
            char init, fin;
            fscanf(fptr, "%c %c\n", &init, &fin);

            // search
            for (int j = 0; j < len; j++){
                if (str[j] == init && denyChange[init - 'A'] == 0){
                    str[j] = fin;
                }
            }
            denyChange[init - 'A'] = 1;
        }

        int occurs[26] = {0}; // from 0 - 25
        for (int i = 0; i < len; i++){
            occurs[str[i] - 'A']++;
        }

        for (int i = 0; i <= 25; i++){
            if (occurs[i] == 0) continue;
            printf("%c %d\n", i + 'A', occurs[i]);
        }
    }
    fclose(fptr);
    return 0;
}