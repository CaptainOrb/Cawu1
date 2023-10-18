#include <stdio.h>

int findSum(int arr[], int length, unsigned long long max)
{
    int maxLength = 0;
    int index = 0;
    while (index < length)
    {
        unsigned long long tmpSum = 0;
        int retLength = 0;
        for (int j = index; j < length; j++)
        {
            if (tmpSum + arr[j] <= max)
            {
                tmpSum += arr[j];
                retLength++;
            }
            else break;
        }
        
        if (retLength > maxLength) maxLength = retLength;
        index++;
    }

    return maxLength;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++)
    {
        int N;
        unsigned long long M;
        scanf("%d %llu", &N, &M);
        int numbers[10000];
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &numbers[i]);
        }

        int maxLen = findSum(numbers, N, M);
        if (maxLen == 0) maxLen = -1;

        printf("Case #%d: %d\n", tc, maxLen);
    }
}