/*
    SIMULASI RECURSION
    Wesley Aldrich
    PPTI 17

    Bahan Belajar Kelompok Tutor Mistis: Prime Numbers
*/

#include <stdio.h>

int getFactor(int n, int factor = 0, int iterator = 1){
    if (iterator <= n){
        if (n % iterator == 0){
            factor++;
            printf("%d ", iterator);
        }
        return getFactor(n, factor, iterator+1);
    }
    else return factor;
}

bool isPrime (int num){
    printf("Factors: ");
    int factorCount = getFactor(num);
    printf("\nFactor count: %d\n", factorCount);

    if (factorCount == 2) return true;
    else return false;
}

int main(){
    int N;
    scanf("%d",&N);

    if (isPrime(N)) printf("YES");
    else printf("NO");

    printf("\n");
    main();
}