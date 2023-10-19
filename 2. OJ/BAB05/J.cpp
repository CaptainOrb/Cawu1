#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    for (int tc = 1; tc <= t; tc++)
    {
        char input[1001];
        scanf("%[^\n]", input);
        getchar();

        int length = strlen(input);
        printf("Case %d: ", tc);
        for (int i = 0; i < length; i++)
        {
            printf("%d", input[i]);

            if (i < length - 1)
            {
                printf("-");
            }
        }
        printf("\n");
    }
}