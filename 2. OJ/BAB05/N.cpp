#include <stdio.h>

int max(int num[], int N)
{
    int max;
    int maxIndex;
    bool init = false;
    for (int i = 0; i < N; i++)
    {
        if (init == false)
        {
            max = num[i];
            maxIndex = i;
            init = true;
            continue;
        }
        if (num[i] > max)
        {
            max = num[i];
            maxIndex = i;
        }
    }
    int prevMax;
    init = false;
    for (int i = 0; i < N; i++)
    {
        if (i == maxIndex)
        {
            continue;
        }
        if (init == false)
        {
            prevMax = num[i];
            init = true;
            continue;
        }
        if (num[i] > prevMax)
        {
            prevMax = num[i];
        }
    }

    return max + prevMax;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++)
    {
        int N;
        scanf("%d", &N);

        int num[100000];
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &num[i]);
        }

        // int res = max(num, N);
        printf("Case #%d: %d\n", tc, max(num, N));
    }
}