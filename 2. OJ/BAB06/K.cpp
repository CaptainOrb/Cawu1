#include <stdio.h>

int fb0, fb1;

int fibo(int target){
    if (target == 0) return fb0;
    if (target == 1) return fb1;

    return fibo(target-1) + fibo(target-2);
}

int main(){
    int fb[1001];
    scanf("%d %d", &fb0, &fb1);
    int target;
    scanf("%d", &target);
    printf("%d\n", fibo(target));
}