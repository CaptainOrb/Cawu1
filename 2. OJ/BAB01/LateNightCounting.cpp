#include <stdio.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = N; i <= N + M - 1; i++)
    {
        printf("%d\n", i);
    }
}