#include <stdio.h>
#include <string.h>

int main()
{
    int tc;
    scanf("%d", &tc);
    getchar();
    for (int t = 1; t <= tc; t++)
    {
        char input[100001];
        scanf("%[^\n]", input);
        getchar();

        int length = strlen(input);
        int index = 0;
        int diff = 0;

        for (int i = 0; i < length; i++)
        {
            bool unique = true;
            for (int j = 0; j < i; j++)
            {
                if (input[i] == input[j])
                {
                    unique = false;
                    break;
                }
            }
            if (unique)
            {
                diff++;
            }
        }

        bool girl = false;
        if (diff % 2 == 0)
        {
            girl = true;
        }

        printf("Case #%d: ", t);
        if (girl)
        {
            printf("Yay\n");
        }
        else
        {
            printf("Ewwww\n");
        }
    }
}