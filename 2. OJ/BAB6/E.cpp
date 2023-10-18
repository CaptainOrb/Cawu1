#include <stdio.h>

void plant(int tree, int *plantedTree){
    (*plantedTree) += tree;
}

int main(){
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++){
        int plantedTree = 0;
        int days;
        scanf("%d", &days);
        for (int i = 0; i < days; i++){
            int tree;
            scanf("%d", &tree);
            plant(tree, &plantedTree);
        }
        printf("Case #%d: %d\n", tc, plantedTree);
    }
}