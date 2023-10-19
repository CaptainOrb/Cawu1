#include <stdio.h>

void fiboStr(int N, char c0, char c1)
{
    if (N == 0) printf("%c", c0);
    else if (N == 1) printf("%c", c1);
    else
    {
        fiboStr(N-1, c0, c1);
        fiboStr(N-2, c0, c1);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    getchar();
    for (int tc = 1; tc <= T; tc++)
    {
        int N;
        char c0, c1;
        scanf("%d %c %c", &N, &c0, &c1);
        getchar();

        printf("Case #%d: ", tc);
        fiboStr(N, c0, c1);
        printf("\n");
    }
}