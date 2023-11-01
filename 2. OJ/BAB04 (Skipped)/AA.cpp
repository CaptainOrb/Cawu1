#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int roll;
    int pos = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &roll);
        pos += roll;

        if (pos == 9)
        {
            pos = 21;
        }
        else if (pos == 33)
        {
            pos = 42;
        }
        else if (pos == 76)
        {
            pos = 92;
        }
        else if (pos == 53)
        {
            pos = 37;
        }
        else if (pos == 80)
        {
            pos = 59;
        }
        else if (pos == 97)
        {
            pos = 88;
        }
    }

    printf("%d\n", pos);
}