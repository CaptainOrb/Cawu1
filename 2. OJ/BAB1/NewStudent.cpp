#include <stdio.h>

int main()
{
    char NIS[10], name[200];
    int age;
    scanf("%[^\n]s", name);
    getchar();
    scanf("%s %d", NIS, &age);

    printf("Name: %s\n", name);
    printf("NIS: %s\n", NIS);
    printf("Age: %d\n", age);
}