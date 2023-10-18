#include <stdio.h>

int main()
{
    double A, B;
    scanf("%lf %lf", &A, &B);
    printf("%.4lf%%\n", B*100/A);
}