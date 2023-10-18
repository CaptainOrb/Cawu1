#include <stdio.h>

unsigned long long M;
unsigned long long tmpMax;

int findSum(int arr[], int length, unsigned long long max)
{
    int maxLength = 0;
    int index = 0;
    int decreaseIndex = 0;

    int retLength = 0;
    tmpMax = max;
    // printf("tmpmax: %llu, max: %llu\n", tmpMax, max);
    while (index < length)
    {
        if (arr[index] > max)
        {
            // reset all and go next
            // printf("GO NEXT ON: %d > %d\n", arr[index], max);
            retLength = 0;
            tmpMax = max;
            index++;
            continue;
        }
        else if (tmpMax >= arr[index])
        {
            tmpMax -= arr[index];
            retLength++;
            index++;
        }
        else if (arr[index] > tmpMax && arr[index] <= max)
        {
            tmpMax += arr[decreaseIndex];
            decreaseIndex++;
            retLength--;
            // printf("BUANG\n");
        }
        
        if (retLength > maxLength) maxLength = retLength;
        // printf("%d %d %d\n", tmpMax, retLength, maxLength);
    }

    if (maxLength == 0) maxLength = -1;

    return maxLength;
}

int main()
{
    int N;
    scanf("%d", &N);
    int numbers[5005];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &numbers[i]);
    }

    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++)
    {
        scanf("%llu", &M);

        int maxLen = findSum(numbers, N, M);

        printf("Case #%d: %d\n", tc, maxLen);
    }

    return 0;
}