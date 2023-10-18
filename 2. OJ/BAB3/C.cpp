#include <stdio.h>

int main()
{
    int T;
    int K, N;

    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &K, &N);

        printf("Case #%d: ", i + 1);

        if (K > N)
        {
            printf("Go-Jo\n");
        }
        else
        {
            printf("Bi-Pay\n");
        }
    }
}