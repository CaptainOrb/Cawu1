// REPE AP

#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    getchar();
    for (int i = 0; i < T; i++)
    {
        char str[110];
        int N, K;
        scanf("%d %d", &N, &K);
        getchar();

        scanf("%[^\n]", str);
        for (int j = 0; j < N; j++)
        {
            // printf("0 : %d\n", str[j]);
            str[j] -= 'a';
            // printf("1 : %d\n", str[j]);
            str[j] += K;
            // printf("2 : %d\n", str[j]);

            while (str[j] > 25)
            {
                str[j] -= 26;
            }

// .1.1.1.1.

            str[j] += 'a';
        }
        printf("%s\n", str);
    }
}