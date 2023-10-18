#include <stdio.h>

int call = 0;

int fibonacci(int N)
{
    call++;
    if (N == 0 || N == 1) return 1;
    
    return fibonacci(N-1) + fibonacci(N-2);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++)
    {
        int N;
        scanf("%d", &N);
        call = 0;
        fibonacci(N);
        printf("Case #%d: %d\n", tc, call);
    }
}