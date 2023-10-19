#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int C[N];

    for (int i = 1; i <= N; i++)
    {
        scanf("%d ", &C[i]);
    }

    int Q;
    scanf("%d", &Q);
    for (int i = 1; i <= Q; i++)
    {
        int init, last;
        scanf("%d %d", &init, &last);

        C[init] = last;

        printf("Case #%d: ", i);
        for (int i = 1; i <= N; i++)
        {
            printf("%d", C[i]);

            if (i < N)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}