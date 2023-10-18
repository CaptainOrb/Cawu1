#include <stdio.h>

int main()
{
    int N;
    int index[1000], num[1000], result[1000];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &index[i]);
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
        result[index[i]] = num[i]; 
    }
    for (int i = 0; i < N; i++)
    {
        printf("%d", result[i]);
        if (i < N - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
}