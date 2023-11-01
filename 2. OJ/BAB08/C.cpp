#include <stdio.h>

int main(){
    int N, M;
    scanf("%d %d",&N,&M); getchar();
    int add[100];
    for (int i = 0; i < N; i++)
        scanf("%d",&add[i]);

    for (int i = 0; i < M; i++){
        int del;
        scanf("%d",&del);

        for (int j = 0; j < N; j++)
            if (del == add[j]) add[j] = 0;
    }

    int max = -1;
    for (int i = 0; i < N; i++)
        if (add[i] != 0 && add[i] > max)
            max = add[i];

    printf("Maximum number is %d\n", max);
}