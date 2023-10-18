#include <stdio.h>

int main()
{
    int T;
    int N, K;
    char bitstring[10001];

    scanf("%d", &T);
    getchar();
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &N, &K);
        getchar();
        scanf("%[^\n]", bitstring);
        getchar();

        int staircase = 0;
        int firstStair = -1, lastStair = -1;
        for (int j = 0; j < N; j++)
        {
            if (bitstring[j] == '1')
            {
                firstStair = j + 1;
                break;
            }
        }
        for (int j = N - 1; j >= 0; j--)
        {
            if (bitstring[j] == '1')
            {
                lastStair = j;
                break;
            }
        }
        for (int j = 0; j < N; j++)
        {
            if (bitstring[j] == '1')
            {
                staircase++;
                // puts("Trigger 1");
            }
        }

        bool survive;
        if (K >= N)
        {
            // puts("Code 1");
            survive = true;
        }
        else if (firstStair == -1)
        {
            survive = false;
        }
        else if ((firstStair <= K) && (N - lastStair <= K) && (staircase != 1))
        {
            survive = true;
        }
        else
        {
            survive = false;
        }

        // check for survivability
        if (survive)
        {
            printf("Case #%d: Alive\n", i + 1);
        }
        else
        {
            printf("Case #%d: Dead\n", i + 1);
        }
    }
}