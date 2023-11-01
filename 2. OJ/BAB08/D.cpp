#include <stdio.h> 
#include <string.h> 

typedef struct data {
    char studentName[15]; 
    int studentScore; 
}data; 

int findRank(data input[], char target[], int size){
    int rank = 1;
    int targetScore;
    int targetIndex;
    // get targetScore and targetIndex
    for (int i = 0; i < size; i++){
        if (strcmp(input[i].studentName, target) == 0){
            targetScore = input[i].studentScore;
            targetIndex = i;
            break;
        }
    }
    // compare targetScore to others
    for (int i = 0; i < size; i++){
        if (i == targetIndex)
            continue;
        else if (input[i].studentScore > targetScore)
            rank++;
        else if (input[i].studentScore == targetScore && strcmp(input[i].studentName, target) < 0)
            rank++;
    }
    return rank;
}

int main() {
    int t, n; 
    data input[1001]; 
    char target[15];  
    scanf ("%d", &t); getchar(); 

    for (int i = 0; i < t; i++) {
        scanf("%d", &n); getchar();

        for (int j = 0; j < n; j++) {
            scanf ("%[^#]#%d", input[j].studentName, &input[j].studentScore);
            getchar(); 
        }
        scanf ("%[^\n]", target); getchar(); 

        int rank = findRank(input, target, n);

        printf ("Case #%d: %d\n", i+1, rank);;
    }
    return 0; 
}