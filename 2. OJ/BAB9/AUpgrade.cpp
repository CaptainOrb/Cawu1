#include <stdio.h>
#include <string.h>

int search(char str[], char names[][50], int nameList)
{
    int len = strlen(str);
    for (int i = 0; i < nameList; i++)
    {
        if (strncmp(str, names[i], len) == 0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    FILE *fptr;
    // fptr = fopen("testdata.in", "r");
    fptr = fopen("D:\\.BCA\\BCA Coding\\OJ\\BAB9\\testdata.txt", "r");

    int nameList;
    fscanf(fptr, "%d\n", &nameList);

    char names[180][50];
    char plants[180][50];
    for (int i = 0; i < nameList; i++)
    {
        fscanf(fptr, "%[^#]#", names[i]);
        fscanf(fptr, "%[^\n]\n", plants[i]);
    }

    int selection;
    fscanf(fptr, "%d\n", &selection);

    char inp[50];
    for (int i = 0; i < selection; i++)
    {
        fscanf(fptr, "%[^\n]\n", inp);
        printf("Case #%d: ", i+1);
        int found = search(inp, names, nameList);
        if (found == -1)
        {
            printf("N/A\n");
        }
        else
        {
            printf("%s\n", plants[found]);
        }
    }
    fclose(fptr);
}