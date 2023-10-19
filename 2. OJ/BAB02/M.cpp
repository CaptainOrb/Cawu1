#include <stdio.h>

int main()
{
    double X, Y;
    scanf("%lf %lf", &X, &Y);
    double percentage = X * 100 / Y;
    printf("%.2lf%%\n", percentage);
}