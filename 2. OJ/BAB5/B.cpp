#include <stdio.h>

int main()
{
    int T, N;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        scanf("%d", &N);
        int A[N], B[N], C[N];
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &A[j]);
        }
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &B[j]);
        }

        printf("Case #%d: ", i);
        for (int j = 0; j < N; j++)
        {
            C[j] = A[j] - B[j];
            printf("%d", C[j]);
            if (j < N-1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}