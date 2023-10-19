#include <stdio.h>

bool cond(int matrix[][100], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < j; k++)
            {
                if (matrix[i][j] == matrix[i][k])
                {
                    return true;
                }
            }

            for (int k = 0; k < i; k++)
            {
                if (matrix[i][j] == matrix[k][j])
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int N;
    scanf("%d", &N);

    int matrix[100][100];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (cond(matrix, N))
    {
        printf("Nay\n");
    }
    else
    {
        printf("Yay\n");
    }
}