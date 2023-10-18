#include <stdio.h>

int main()
{
    int a, b, c, d, T;

    scanf("%d", &T);
    for (int i = 0; i < 3; i++)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        double tmp = 2 * a + 2 * b + 4.0 * c / 3 + 1.0 * d / 2;
        printf("%.2lf\n", tmp);
    }
}