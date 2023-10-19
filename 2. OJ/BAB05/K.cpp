#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    for (int tc = 1; tc <= t; tc++)
    {
        char N[1002];
        scanf("%[^\n]", N);
        getchar();

        int X = strlen(N);
        printf("Case #%d : ", tc);
        for (int i = X - 1; i >= 0; i--)
        {
            printf("%c", N[i]);
        }
        printf("\n");
    }
}