#include <stdio.h>

void convert(long long int N, int *operation)
{
    if (N == 1)
    {
        return;
    }
    else if (N % 2 == 0)
    {
        (*operation)++;
        convert(N/2, operation);
    }
    else if (N % 2 == 1)
    {
        (*operation)++;
        convert(N*3+1, operation);
    }
}

int main()
{
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {
        long long int N;
        scanf("%lld", &N);

        int operation = 0; // berapa kali angka N diubah
        convert(N, &operation);

        printf("Case #%d: ", tc);
        if (operation % 2 == 0) printf("Lili\n");
        else printf("Jojo\n");
    }
}