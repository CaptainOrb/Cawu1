#include <stdio.h>
#include <string.h>

bool isPalin(char str[])
{
    int len = strlen(str);
    int i = 0, j = len - 1;
    while (i < j)
    {
        if (str[i] != str[j]) return false;
        i++; j--;
    }
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    getchar();
    for (int tc = 1; tc <= T; tc++)
    {
        char str[1001];
        scanf("%[^\n]", str); getchar();

        printf("Case #%d: ", tc);
        if (isPalin(str)) printf("yes\n");
        else printf("no\n");
    }
}