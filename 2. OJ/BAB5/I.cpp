#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++)
    {
        int N;
        scanf("%d", &N);

        int arr[1000];
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &arr[i]);
        }

        printf("Case #%d: ", tc);
        for (int i = N - 1; i >= 0; i--)
        {
            printf("%d", arr[i]);
            if (i > 0)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}