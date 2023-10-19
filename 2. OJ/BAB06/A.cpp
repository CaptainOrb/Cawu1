#include <stdio.h>

int kelipatan = 0;

int fun(int num)
{
    if (num % 3 == 0 && num != 0) kelipatan++;
    if (num == 1) return 2;
    else if (num == 0) return 1;
    else if (num % 5 == 0) return num * 2;
    else return fun(num-1) + num + fun(num-2) + num-2;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int N;
        scanf("%d", &N);

        kelipatan = 0;
        printf("Case #%d: %d ", i+1, fun(N));
        printf("%d\n", kelipatan);
    }
}