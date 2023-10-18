#include <stdio.h>

int main()
{
    long long N;
    double P;
    int T;
    scanf("%d", &T);
    for (int i = 0; i < 3; i++)
    {
        scanf("%lf %lld", &P, &N);

        printf("%.2lf\n", P*N/100);
    }
}