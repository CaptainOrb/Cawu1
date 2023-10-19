#include <stdio.h>

int main()
{
    double N;
    scanf("%lf", &N);
    double result = N * (100 + (N - 1) * 25);
    printf("%.0lf\n", result);
}