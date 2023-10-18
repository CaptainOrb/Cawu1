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

        if ((K*N) % 2 == 0)
        {
            printf("Party time!\n");
        }
        else
        {
            printf("Need more frogs\n");
        }
    }
}