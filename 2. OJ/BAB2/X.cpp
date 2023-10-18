#include <stdio.h>

int main()
{
    long long A;
    long long B;
    long long C;
    scanf("%lld %lld %lld", &A, &B, &C);
    long long res = A * B * C;
    printf("%lld\n", res);
}