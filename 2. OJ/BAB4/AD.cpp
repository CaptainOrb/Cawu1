#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int items[1001] = {0};
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        int item;
        scanf("%d", &item);
        items[item]++;
        if (item > max) max = item;
    }

    int ans = 0;
    for (int i = 1; i <= max; i++)
    {
        if (items[i] > ans) ans = items[i];
    }

    printf("%d\n", ans);
}