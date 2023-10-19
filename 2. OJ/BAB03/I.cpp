#include <stdio.h>

int main()
{
    double A, B, C;
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%lf %lf %lf", &A, &B, &C);

        B /= 100;
        printf("Case #%d: ", i + 1);
        if (A*B > C)
        {
            printf("%.0lf\n", C);
        }
        else
        {
            printf("%.0lf\n", A*B);
        }
    }
}