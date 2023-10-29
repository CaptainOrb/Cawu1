#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fptr;
    fptr = fopen("testdata.in", "r");

    int A, B;
    fscanf(fptr, "%d %d\n", &A, &B);
    printf("%d\n", A+B);

    fclose(fptr);
}