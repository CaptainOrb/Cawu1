#include <stdio.h>

int main(){
    int T;
    scanf("%d",&T);
    for (int tc = 1; tc <= T; tc++){
        int N, K;
        scanf("%d %d",&N,&K);
        int count = 0;
        for (int i = 0; i < N; i++){
            int num;
            scanf("%d",&num);
            if (num >= K) count++;
        }
        printf("Case #%d: %d\n", tc, count);
    }
}