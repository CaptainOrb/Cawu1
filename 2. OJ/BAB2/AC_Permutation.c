#include <stdio.h>

int permutation(int num, int slot)
{
    int tmp = 1;
    int filledSlot = 1;
    for (int i = num; filledSlot <= slot; i--)
    {
        tmp *= i;
        filledSlot++;
    }
    return tmp;
}

int main()
{
    int N;
    int chances = 0;
    scanf("%d", &N);
    int firstAndLast = N + 1;
    if (N == 1)
    {
        firstAndLast = 1;
    }
    for (int r = 2; r < N; r++)
    {
        int slot = N - r;
        chances += permutation(N, slot);
    }
    chances += firstAndLast;
    printf("%d\n", chances);
}