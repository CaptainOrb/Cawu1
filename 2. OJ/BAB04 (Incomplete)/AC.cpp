#include <stdio.h>

int main()
{
    unsigned int T;
    unsigned int N, M;
    unsigned int P;
    unsigned int min;

    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &N, &M); 
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &P);
            if (j == 0)
            {
                min = P;
            }
            else if (P < min)
            {
                min = P;
            }
        }
        printf("Case #%d: %d\n", i + 1, M / min);
    }
}