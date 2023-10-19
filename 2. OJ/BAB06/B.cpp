#include <stdio.h>

void buildTree(int leaves[], int N, int index, int sum){
    int branchCounter = 0; // how many branches can the specific leaf create
    sum += leaves[index];
    if (index * 2 <= N){ // left branch
        buildTree(leaves, N, index*2, sum);
        branchCounter++;
    }
    if (index * 2 + 1 <= N){ // right branch
        buildTree(leaves, N, index*2 + 1, sum);
        branchCounter++;
    }
    if (branchCounter == 0){ // print the sum if the leaf can't create branch
        printf("%d\n", sum);
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++){
        int N;
        scanf("%d", &N);

        int leaves[101];
        for (int i = 1; i <= N; i++){
            scanf("%d", &leaves[i]);
        }

        int index = 1, sum = 0;
        printf("Case #%d:\n", tc);
        buildTree(leaves, N, index, sum);
    }
}