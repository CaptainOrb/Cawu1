#include <stdio.h>
#include <string.h>

typedef struct data {
    char name[41];
    char plant[41];
} data;

int plantIndex(data participants[], int N, char target[]){
    for (int i = 0; i < N; i++){
        if (strcmp(participants[i].name, target) == 0)
            return i;
    }
    return -1;
}

int main(){
    FILE *fptr = fopen("testdata.in", "r");
    int N;
    fscanf(fptr, "%d\n", &N);

    data participants[100];
    for (int i = 0; i < N; i++)
        fscanf(fptr, "%[^#]#%[^\n]\n",
            participants[i].name, participants[i].plant);
    int M;
    fscanf(fptr, "%d\n", &M);
    for (int i = 1; i <= M; i++){
        char target[41];
        fscanf(fptr, "%[^\n]\n", target);

        int index = plantIndex(participants, N, target);
        
        printf("Case #%d: ", i);
        if (index == -1) printf("N/A\n");
        else printf("%s\n", participants[index].plant);
    }
    fclose(fptr);
}