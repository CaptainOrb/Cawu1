#include <stdio.h>

int main()
{
    int t, tc;
    scanf("%d", &t);
    for (tc = 1; tc <= t; tc++)
    {
        int N;
        scanf("%d", &N);

        int A[10000], B[10000], failed = 0;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &B[i]);
            if (A[i] < B[i])
            {
                failed++;
            }
        }

        printf("Case #%d: %d\n", tc, failed);
    }
}