#include <stdio.h>

int main()
{
    char N[11];
    char M[101];
    char C;
    int O;

    scanf("%[^\n]\n", N);
    scanf("%[^\n]\n", M);
    scanf("%c %d", &C, &O);

    // #include <stdio.h>
    // #include <string.h>

    //     int main()
    //     {
    //         char id[11], name[101], a;
    //         int num;

    //         scanf("%[^\n]\n%[^\n]\n%c %d", id, name, &a, &num);
    //         printf("Id    : %s\n", id);
    //         printf("Name  : %s\n", name);
    //         printf("Class : %c\n", a);
    //         printf("Num   : %d\n", num);

    //         return 0;
    //     }

    printf("Id    : %s\n", N);
    printf("Name  : %s\n", M);
    printf("Class : %c\n", C);
    printf("Num   : %d\n", O);
}