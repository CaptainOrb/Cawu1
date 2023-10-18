#include <stdio.h>

unsigned long long M;
unsigned long long sum = 0;
unsigned long long halfSum = 0;
unsigned long long tmpSum;
int A[100000];
unsigned long long sumA[100000] = {0};

int binarySearch(unsigned long long arr[], int start, int end, unsigned long long target)
{
    while (start <= end)
    {
        int mid = start + (end - start)/2;

        if (target >= arr[end])
        {
            // printf("NIGGA\n");
            return end + 1;
        }
        if (target < arr[start])
        {
            // printf("WIGGA\n");
            return -1;
        }
        if (end - start == 1)
        {
            // printf("CYKA\n");
            return start + 1;
        }
        if (target == arr[mid])
        {
            // printf("BLYAD\n");
            return mid + 1;
        }
        if (target < arr[mid]) end = mid;
        else if (target > arr[mid]) start = mid;
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
        sum += A[i];
        sumA[i] = sum;
    }
    // for (int i = 0; i < N; i++)
    // {
    //     printf("%d ", sumA[i]);
    // }
    // printf("\n");

    int Q;
    scanf("%d", &Q);
    for (int tc = 1; tc <= Q; tc++)
    {
        scanf("%llu", &M);

        // int Y = find(A, N, M);
        int start = 0;
        int end = N - 1;
        int Y = binarySearch(sumA, start, end, M);
        printf("Case #%d: %d\n", tc, Y);
    }
}