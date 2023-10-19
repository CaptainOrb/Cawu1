#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int N, A, B, C, D;
        scanf("%d %d %d %d %d", &N, &A, &B, &C, &D);

        int throwed = 0;

        for (int j = 1; j <= N; j++)
        {
            if (j % A == 0 || j % B == 0 || j % C == 0 || j % D == 0)
            {
                throwed++;
            }
        }

        printf("Case #%d: %d\n", i+1, throwed);
    }
}