#include <stdio.h>
#include <math.h>

int main()
{
    double N;
    scanf("%lf", &N);
    double pangkat = pow(2, N);
    printf("%.0lf\n", pangkat - 1);
}