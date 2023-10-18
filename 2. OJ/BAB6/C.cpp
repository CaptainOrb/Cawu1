#include <stdio.h>

int ackermann(int M, int N)
{
    if (M == 0)
    {
        return (N + 1);
    }
    else if (M > 0 && N == 0)
    {
        ackermann(M-1, 1);
    }
    else if (M > 0 && N > 0)
    {
        ackermann(M-1, ackermann(M,N-1));
    }
}

int main()
{
    int N, M;
    scanf("%d %d", &M, &N);

    printf("result: %d\n", ackermann(M, N));
}