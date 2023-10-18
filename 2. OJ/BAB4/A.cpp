#include <stdio.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= M; i++)
    {
        printf("%d\n", N);
        N++;
    }
}