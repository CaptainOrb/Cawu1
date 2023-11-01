#include <stdio.h>
#include <stdlib.h>

char savedFile[201];
FILE *fptr;

void writeToFile()
{
    // ganti alamat ini ke alamat file yang kalian mau
    fptr = fopen("FileWriting.txt", "w");
    printf("Enter something: ");
    // ngescan huruf apapun termasuk enter, bakal stop kalau diinput tanda "#"
    scanf("%[^#]", savedFile);
    getchar();
    fprintf(fptr, "%s\n", savedFile);
}

void readFromFile()
{
    // ganti alamat ini ke alamat file yang kalian mau
    fptr = fopen("FileWriting.txt", "r");
    fscanf(fptr, "%[^#]", savedFile);
    printf("My Saved File:\n");
    printf("%s", savedFile);
}

int main()
{
    // writeToFile();
    // readFromFile();

    int select;
    puts("1. Write File");
    puts("2. Read File");

scan:
    printf(">> ");
    scanf("%d", &select);

    if (select == 1)
    {
        writeToFile();
    }
    else if (select == 2)
    {
        readFromFile();
    }
    else
    {
        goto scan;
    }

    fclose(fptr);
    return 0;
}