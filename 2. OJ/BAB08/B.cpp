#include <stdio.h>
#include <string.h>

typedef struct data {
    char NIM[11];
    char name[21];
} data;

void search(data students[], int listed, char target[]){
    for (int i = 0; i < listed; i++)
        if (strcmp(students[i].NIM, target) == 0){
            printf("%s\n", students[i].name);
            return;
        }
    printf("N/A\n");
}

int main(){
    FILE *fptr = fopen("testdata.in", "r");
    int N;
    fscanf(fptr, "%d\n", &N);

    data students[100];
    for (int i = 0; i < N; i++)
        fscanf(fptr, "%s %s\n", students[i].NIM, students[i].name);

    int M;
    fscanf(fptr, "%d\n", &M);
    for (int tc = 1; tc <= M; tc++){
        char targetNIM[11];
        fscanf(fptr, "%s\n", targetNIM);

        printf("Case #%d: ", tc);
        search(students, N, targetNIM);
    }
}