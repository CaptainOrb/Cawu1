#include <stdio.h>

int main()
{
    double A, B, C, D;
    double E, F, G, H;
    double I, J, K, L;
    scanf("(%lf+%lf)x(%lf-%lf)", &A, &B, &C, &D);
    getchar();
    scanf("(%lf+%lf)x(%lf-%lf)", &E, &F, &G, &H);
    getchar();
    scanf("(%lf+%lf)x(%lf-%lf)", &I, &J, &K, &L);
    getchar();
    printf("%.0lf ", (A + B) * (C - D));
    printf("%.0lf ", (E + F) * (G - H));
    printf("%.0lf\n", (I + J) * (K - L));
}