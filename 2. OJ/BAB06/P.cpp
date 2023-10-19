#include <stdio.h>

int jobo(int N){
    if (N % 2 != 0) return 1;
    else if (N == 0) return 0;
    else return jobo(N-1) + jobo(N-2);
}

int main(){
    int N;
    scanf("%d",&N);
    printf("%d\n",jobo(N));
}