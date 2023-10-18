#include <stdio.h>

int main()
{
    int X, Y;
    scanf("%d %d", &X, &Y);

    // get garden
    int garden[100][100];
    for (int i = 1; i <= X; i++)
    {
        for (int j = 1; j <= Y; j++)
        {
            scanf("%d", &garden[i][j]);
        }
    }

    // get changes
    int change;
    scanf("%d", &change);
    for (int i = 1; i <= change; i++)
    {
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);

        garden[A][B] = C;
    }

    for (int i = 1; i <= X; i++)
    {
        for (int j = 1; j <= Y; j++)
        {
            printf("%d", garden[i][j]);

            if (j < Y)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}