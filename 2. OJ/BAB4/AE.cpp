#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        double R, H;
        scanf("%lf %lf", &R, &H);

        double circle = 3.14 * R * R;
        double cover = 6.28 * H * R;

        printf("Case #%d: %.2lf\n", i+1, 2*circle + cover);
    }
}