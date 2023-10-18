#include <stdio.h>

int main()
{
    int tc;
    scanf("%d", &tc);
    int t;
    for (t = 1; t <= tc; t++)
    {
        int N, i, j;
        scanf("%d", &N);

        long long int A[500][500], res[500];

        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                scanf("%lld", &A[i][j]);
            }
        }

        printf("Case #%d: ", t);
        for (i = 0; i < N; i++)
        {
            int sum = 0;
            for (j = 0; j < N; j++)
            {
                sum += A[j][i];
            }
            res[i] = sum;
            printf("%lld", res[i]);
            if (i < N - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}