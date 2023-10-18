#include <stdio.h>

int main()
{
    double X, Y;
    scanf("%lf %lf", &X, &Y);
    double percentage = (X-Y) * 100 / X;
    printf("%.2lf%%\n", percentage);
}