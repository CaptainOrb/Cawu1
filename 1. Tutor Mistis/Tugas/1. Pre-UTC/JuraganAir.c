
/*	WESLEY ALDRICH
    PPTI 17
    NIM: 2702363613  */

#include <stdio.h>
#include <string.h>

int showMenu()
{
    int ret;
    puts("\nMenu:");
    puts("=========================");
    puts("1. Insert New");
    puts("2. Manage Products");
    puts("3. Insert New Carbonated");
    puts("4. Manage Carbonated Products");
    puts("5. Exit");
    printf("Choice: ");
    scanf("%d", &ret);
    getchar();
    return ret;
}

void showMineralWater(int *ptr, char merk[][3], int listedSize[])
{
    puts("Mineral Water");
    puts("=========================");
    printf("%-15s%s\n", "No. Merk", "Size");
    int i = 1;
    if (*ptr == 0)
    {
        printf("\n");
        return;
    }
    // else
    for (i = 1; i <= *ptr; i++)
    {
        printf("%-4d%-11s%d\n", i, merk[i - 1], listedSize[i - 1]);
    }
    printf("\n");
}

void newMineralWater(int *ptr, char merk[][3], int listedSize[])
{
    puts("\nMineral Water");
    puts("=========================");
    char newMerk[3];
    int newSize;
    do
    {
        printf("Merk [2] ? ");
        scanf("%[^\n]", newMerk);
        getchar();
    } while (strlen(newMerk) != 2);
    do
    {
        printf("Size [240/600/1500] ml? ");
        scanf("%d", &newSize);
        getchar();
    } while (newSize != 240 && newSize != 600 && newSize != 1500);

    if (strcmp(merk[*ptr - 1], newMerk) == 0 && listedSize[*ptr - 1] == newSize)
    {
        printf("Sudah ada minuman %s size %d!!!\n\n", merk[*ptr - 1], listedSize[*ptr - 1]);
        *ptr = *ptr - 1;
        return;
    }

    strcpy(merk[*ptr], newMerk);
    listedSize[*ptr] = newSize;
}

int manageMenu()
{
    puts("\nManage Menu");
    puts("=========================");
    puts("1. Edit");
    puts("2. Delete");
    printf("Choice: ");
    int ret;
    scanf("%d", &ret);
    return ret;
}

void showCarbonWater(int *ptrC, char merkC[][3], int listedSizeC[], char powder[][31])
{
    puts("Carbonated Water");
    puts("=========================");
    printf("%-15s%-10s%s\n", "No. Merk", "Powder", "Size");
    int i = 1;
    if (*ptrC == 0)
    {
        printf("\n");
        return;
    }
    // else
    for (i = 1; i <= *ptrC; i++)
    {
        printf("%-4d%-11s%-10s%d\n", i, merkC[i - 1], powder[i - 1], listedSizeC[i - 1]);
    }
    printf("\n");
}

void newCarbonWater(int *ptrC, char merkC[][3], int listedSizeC[], char powder[][31])
{
    puts("\nCarbonated Water");
    puts("=========================");
    char newMerk[3];
    int newSize;
    char newPowder[31];
    do
    {
        printf("Merk [2] ? ");
        scanf("%[^\n]", newMerk);
        getchar();
    } while (strlen(newMerk) != 2);
    do
    {
        printf("Size [240/600/1500] ml? ");
        scanf("%d", &newSize);
        getchar();
    } while (newSize != 240 && newSize != 600 && newSize != 1500);

    int tmp;
    do
    {
        printf("Powder [2..30] ? ");
        scanf("%[^\n]", newPowder);
        getchar();
        tmp = strlen(newPowder);
    } while (tmp < 2 || tmp > 30);

    if (strcmp(merkC[*ptrC - 1], newMerk) == 0 && listedSizeC[*ptrC - 1] == newSize && strcmp(powder[*ptrC - 1], newPowder))
    {
        printf("Sudah ada minuman %s size %d dengan powder %s!!!\n\n", merkC[*ptrC - 1], listedSizeC[*ptrC - 1], powder[*ptrC - 1]);
        *ptrC = *ptrC - 1;
        return;
    }

    strcpy(merkC[*ptrC], newMerk);
    strcpy(powder[*ptrC], newPowder);
    listedSizeC[*ptrC] = newSize;
}

int main()
{
    printf("%20s\n\n", "Juragan Air");

    // var mineral
    char merk[20][3];
    int listedSize[20];
    int listedMineralWater = 0;
    int *ptrListedMineralWater = &listedMineralWater;

    // var carbon
    char merkC[20][3];
    char powder[20][31];
    int listedSizeC[20];
    int listedCarbonWater = 0;
    int *ptrListedCarbonWater = &listedCarbonWater;

    showMineralWater(ptrListedMineralWater, merk, listedSize);

    int menuChoice;
menu1:
    menuChoice = showMenu();
    if (menuChoice == 1)
    {
        newMineralWater(ptrListedMineralWater, merk, listedSize);
        listedMineralWater++;

        showMineralWater(ptrListedMineralWater, merk, listedSize);
        goto menu1;
    }
    else if (menuChoice == 2)
    {
        showMineralWater(ptrListedMineralWater, merk, listedSize);

    menu2:
        menuChoice = manageMenu();
        if (menuChoice == 1)
        {
            // Edit
            int select;
            do
            {
                printf("Produk mana yang Anda mau edit? [%d..%d] ? ", 1, listedMineralWater);
                scanf("%d", &select);
                getchar();
            } while (select < 1 || select > listedMineralWater);

            char newMerk[3];
            int newSize;
            do
            {
                printf("Merk [2] ? ");
                scanf("%[^\n]", newMerk);
                getchar();
            } while (strlen(newMerk) != 2);
            do
            {
                printf("Size [240/600/1500] ml? ");
                scanf("%d", &newSize);
                getchar();
            } while (newSize != 240 && newSize != 600 && newSize != 1500);

            strcpy(merk[select - 1], newMerk);
            listedSize[select - 1] = newSize;
            printf("Minuman menjadi %s %d ml berhasil!\n", merk[select - 1], listedSize[select - 1]);

            showMineralWater(ptrListedMineralWater, merk, listedSize);
            goto menu1;
        }
        else if (menuChoice == 2)
        {
            // Delete
            int select;
            do
            {
                printf("Produk mana yang Anda mau delete? [%d..%d] ? ", 1, listedMineralWater);
                scanf("%d", &select);
                getchar();
            } while (select < 1 || select > listedMineralWater);

            if (select == listedMineralWater)
            {
                listedMineralWater--;
                strcpy(merk[select - 1], "-1");
                listedSize[select - 1] = -1;
            }
            else if (select < listedMineralWater)
            {
                listedMineralWater--;
                int i;
                for (i = select - 1; i < listedMineralWater; i++)
                {
                    strcpy(merk[i], merk[i + 1]);
                    listedSize[i] = listedSize[i + 1];
                }
            }
            printf("Berhasil dihapus!\n");

            showMineralWater(ptrListedMineralWater, merk, listedSize);
            goto menu1;
        }
        else
        {
            goto menu2;
        }
    }
    else if (menuChoice == 3)
    {
        showCarbonWater(ptrListedCarbonWater, merkC, listedSizeC, powder);
        newCarbonWater(ptrListedCarbonWater, merkC, listedSizeC, powder);
        listedCarbonWater++;

        showCarbonWater(ptrListedCarbonWater, merkC, listedSizeC, powder);
        goto menu1;
    }
    else if (menuChoice == 4)
    {
        showCarbonWater(ptrListedCarbonWater, merkC, listedSizeC, powder);

    menu3:
        menuChoice = manageMenu();
        if (menuChoice == 1)
        {
            // Edit
            int select;
            do
            {
                printf("Produk mana yang Anda mau edit? [%d..%d] ? ", 1, listedCarbonWater);
                scanf("%d", &select);
                getchar();
            } while (select < 1 || select > listedCarbonWater);

            char newMerk[3];
            int newSize;
            char newPowder[31];
            do
            {
                printf("Merk [2] ? ");
                scanf("%[^\n]", newMerk);
                getchar();
            } while (strlen(newMerk) != 2);
            do
            {
                printf("Size [240/600/1500] ml? ");
                scanf("%d", &newSize);
                getchar();
            } while (newSize != 240 && newSize != 600 && newSize != 1500);

            int tmp;
            do
            {
                printf("Powder [2..30] ? ");
                scanf("%[^\n]", newPowder);
                getchar();
                tmp = strlen(newPowder);
            } while (tmp < 2 || tmp > 30);

            strcpy(merkC[select - 1], newMerk);
            strcpy(powder[select - 1], newPowder);
            listedSizeC[select - 1] = newSize;

            printf("Minuman menjadi %s %d ml berhasil!\n", merkC[select - 1], listedSizeC[select - 1]);

            showCarbonWater(ptrListedCarbonWater, merkC, listedSizeC, powder);
            goto menu1;
        }
        else if (menuChoice == 2)
        {
            // Delete
            int select;
            do
            {
                printf("Produk mana yang Anda mau delete? [%d..%d] ? ", 1, listedCarbonWater);
                scanf("%d", &select);
            } while (select < 1 || select > listedCarbonWater);

            if (select == listedCarbonWater)
            {
                listedCarbonWater--;
                strcpy(merkC[select - 1], "-1");
                listedSizeC[select - 1] = -1;
            }
            else if (select < listedCarbonWater)
            {
                listedCarbonWater--;
                int i;
                for (i = select - 1; i < listedCarbonWater; i++)
                {
                    strcpy(merkC[i], merkC[i + 1]);
                    listedSizeC[i] = listedSizeC[i + 1];
                    strcpy(powder[i], powder[i + 1]);
                }
            }
            printf("Berhasil dihapus!\n");

            showCarbonWater(ptrListedCarbonWater, merkC, listedSizeC, powder);
            goto menu1;
        }
        else
        {
            goto menu3;
        }
    }
    else if (menuChoice == 5)
    {
        return 0;
    }
    else
    {
        goto menu1;
    }
}