#include <stdio.h>

int main()
{
    char input1[101];

    scanf("%[^\n]", input1);
    printf("%s-san\n", input1);
}