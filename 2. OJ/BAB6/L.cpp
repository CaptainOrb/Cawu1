#include <stdio.h>

int X, Y;

int jojonanci(int n){
    if (n == 0) return X;
    if (n == 1) return Y;

    return jojonanci(n-1) - jojonanci(n-2);
}

int main(){
    int T;
    scanf("%d",&T);
    for (int tc = 1; tc <= T; tc++){
        int N;
        scanf("%d %d %d", &N, &X, &Y);

        printf("Case #%d: %d\n", tc, jojonanci(N));
    }
}