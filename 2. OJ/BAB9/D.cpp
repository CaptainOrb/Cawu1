#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fptr;
    // fptr = fopen("testdata.in", "r");
    fptr = fopen("D:\\.BCA\\BCA Coding\\OJ\\BAB9\\testdataD.txt", "r");

    int T;
    fscanf(fptr, "%d\n", &T);

    for (int tc = 1; tc <= T; tc++)
    {
        char str[101] = {};
        fscanf(fptr, "%s\n", str);

        int len = strlen(str);

        int change;

        char locked = '\0'; 
        fscanf(fptr, "%d\n", &change);
        for (int i = 0; i < change; i++)
        {
            char init, fin;
            fscanf(fptr, "%c %c\n", &init, &fin);

            // search
            for (int j = 0; j < len; j++)
            {
                if (init == locked) break;
                else if (str[j] == init)
                {
                    str[j] = fin;
                    locked = str[j];
                }
            }
        }

        int occurs[26] = {0}; // from 0 - 25

        for (int i = 0; i < len; i++)
        {
            occurs[str[i] - 'A']++;
        }

        for (int i = 0; i <= 25; i++)
        {
            if (occurs[i] == 0) continue;
            printf("%c %d\n", i + 'A', occurs[i]);
        }
    }

    fclose(fptr);
    return 0;
}