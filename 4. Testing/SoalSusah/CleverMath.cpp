#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        int A, B;
        scanf("%d %d", &A, &B);

        int res[10];
        int index = 0;
        while (A != 0 || B != 0)
        {
            res[index] = ((A % 10) + (B % 10)) % 10;
            A /= 10;
            B /= 10;
            index++;
        }

        int finalRes = 0;
        int multiplier = 1;
        for (int j = 0; j < index; j++)
        {
            finalRes += res[j] * multiplier;
            multiplier *= 10;
        }

        printf("Case #%d: %d\n", i, finalRes);
    }
}