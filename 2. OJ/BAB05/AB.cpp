#include <stdio.h>
#include <string.h>

long long int matrix1[50][50], matrix2[50][50], matrix3[50][50];
long long int matrix12[50][50], matrix123[50][50];

void multiplyToMatrix12(int size)
{
    // matrix12[i][j] = (matrix1[i][k] * matrix2[k][j])
    for (int row = 1; row <= size; row++)
    {
        for (int column = 1; column <= size; column++)
        {
            for (int k = 1; k <= size; k++)
            {
                matrix12[row][column] += (matrix1[row][k] * matrix2[k][column]);
            }
        }
    }
}

void multiplyToMatrix123(int size)
{
    for (int row = 1; row <= size; row++)
    {
        for (int column = 1; column <= size; column++)
        {
            for (int k = 1; k <= size; k++)
            {
                matrix123[row][column] += (matrix12[row][k] * matrix3[k][column]);
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        int size;
        scanf("%d", &size);

        for (int row = 1; row <= size; row++)
        {
            for (int column = 1; column <= size; column++)
            {
                scanf("%lld", &matrix1[row][column]);
            }
        }
        // getchar();
        for (int row = 1; row <= size; row++)
        {
            for (int column = 1; column <= size; column++)
            {
                scanf("%lld", &matrix2[row][column]);
            }
        }
        // getchar();
        for (int row = 1; row <= size; row++)
        {
            for (int column = 1; column <= size; column++)
            {
                scanf("%lld", &matrix3[row][column]);
            }
        }
        // getchar();

        multiplyToMatrix12(size);
        multiplyToMatrix123(size);

        printf("Case #%d:\n", i);
        for (int row = 1; row <= size; row++)
        {
            for (int column = 1; column <= size; column++)
            {
                if (column == size)
                {
                    printf("%lld", matrix123[row][column]);
                }
                else
                {
                    printf("%lld ", matrix123[row][column]);
                }
            }
            printf("\n");
        }
        memset(matrix1, 0, sizeof(matrix1));
        memset(matrix2, 0, sizeof(matrix2));
        memset(matrix3, 0, sizeof(matrix3));
        memset(matrix12, 0, sizeof(matrix12));
        memset(matrix123, 0, sizeof(matrix123));
    }
}