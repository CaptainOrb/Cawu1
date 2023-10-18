#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int N, K;
        scanf("%d %d", &N, &K);


        int n[101][101], k[101][101];
        for (int j = 0; j < N; j++)
        {
            for (int l = 0; l < N; l++)
            {
                scanf("%d", &n[j][l]);
            }
        }
        for (int j = 0; j < K; j++)
        {
            for (int l = 0; l < K; l++)
            {
                scanf("%d", &k[j][l]);
            }
        }

        // logic starts here
        int R[101][101] = {0};
        for (int j = 0; j+K <= N; j++)
        {
            for (int o = 0; o + K <= N; o++)
            {
                for (int l = 0; l < K; l++)
                {
                    for (int m = 0; m < K; m++)
                    {
                        R[j][o] += n[l+j][m+o] * k[l][m];
                    }
                }
                
                printf("%d", R[j][o]);
                if (o + K < N)
                {
                    printf(" ");
                }
                else
                {
                    printf("\n");
                }
            }
        }

//        for (int j = 0; j+K <= N; j++)
//        {
//            for (int o = 0; o + K <= N; o++)
//            {
//                printf("%d", R[j][o]);
//                if (o + K < N)
//                {
//                    printf(" ");
//                }
//                else
//                {
//                    printf("\n");
//                }
//            }
//        }
    }
}
