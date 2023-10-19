#include <stdio.h>

int main()
{
    char A, B;
    scanf("%c %c", &A, &B);
    getchar();
    int numA = A;
    int numB = B;
    printf("%d\n", numA*numB);
}