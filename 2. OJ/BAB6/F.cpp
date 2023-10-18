#include <stdio.h>
#include <string.h>

void reverse(char str[], int size)
{
    int i = 0, j = size - 1;
    while (i < j)
    {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;

        i++; j--;
    }
}

int main()
{
    int T;
    scanf("%d", &T); getchar();
    for (int tc = 1; tc <= T; tc++)
    {
        char str[1001];
        scanf("%[^\n]", str); getchar();

        int len = strlen(str);

        printf("Case #%d: ", tc);
        reverse(str, len);
        for (int i = 0; i < len; i++)
        {
            printf("%c", str[i]);
        }
        printf("\n");
    }
}