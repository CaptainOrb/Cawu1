#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data {
    char name[3];
    int size;
} data;

data drinks[100], sodas[100];
int listedDrink = 0;
int listedSoda = 0;

void showList(){
    printf("Mineral Water\n");
    printf("========================\n");
    printf("| %-4s | %-4s | %-8s |\n", "No.", "Merk", "Size");
    for (int i = 0; i < listedDrink; i++){
        printf("| %-4d | %-4s | %-8d |\n", i+1, drinks[i].name, drinks[i].size);
    }
}

void mainMenu(){
    system("cls");
    showList();

    printf("\nMenu:\n");
    printf("1. Insert New\n");
    printf("2. Manage Products\n");
    printf("3. Insert New Carbonated\n");
    printf("4. Manage Carbonated Products\n");
    printf("5. Exit\n");
    printf("Choice: ");
}

int main(){
    int opt;
    do {
        mainMenu();
        scanf("%d", &opt); getchar();
        if (opt == 1){
            do {
                printf("Merk [2]: ");
                scanf("%s", drinks[listedDrink].name);
                getchar();
            } while (strlen(drinks[listedDrink].name) != 2);
            do {
                printf("Size [240/600/1500]: ");
                scanf("%d", &drinks[listedDrink].size);
                getchar();
            } while (
                drinks[listedDrink].size != 240
                && drinks[listedDrink].size != 600
                && drinks[listedDrink].size != 1500
            );
            bool valid = true;
            for (int i = 0; i < listedDrink; i++){
                if (drinks[i].name == drinks[listedDrink].name){
                    printf("Minuman tidak boleh sama!\n"); getchar();
                    valid = false;
                }
            }
            if (!valid) continue;

            printf("Minuman %s %d ml berhasil ditambahkan!",
                drinks[listedDrink].name, drinks[listedDrink].size);
            getchar();
            listedDrink++;
        }
        else if (opt == 2){
            showList();
            printf("\nManage Menu\n");
            printf("============\n");
            printf("1. Edit\n");
            printf("2. Delete\n");
            printf("Choice: ");
            int select;
            do {
                scanf("%d", &select);
            } while (select != 1 && select != 2);
            if (select == 1){
                if (listedDrink == 0){
                    printf("No listed drink yet!"); getchar();
                    continue;
                }
                int index;
                do{
                    printf("Produk mana yang anda mau edit [1..%d]: ", listedDrink);
                    scanf("%d", &index);
                } while (index < 1 || index > listedDrink);
                index--;
                do {
                    printf("Merk [2]: ");
                    scanf("%s", drinks[index].name);
                    getchar();
                } while (strlen(drinks[index].name) != 2);
                do {
                    printf("Size [240/600/1500]: ");
                    scanf("%d", &drinks[index].size);
                    getchar();
                } while (
                    drinks[index].size != 240
                    && drinks[index].size != 600
                    && drinks[index].size != 1500
                );
                bool valid = true;
                for (int i = 0; i < listedDrink; i++){
                    if (drinks[i].name == drinks[index].name){
                        printf("Minuman tidak boleh sama!\n"); getchar();
                        valid = false;
                    }
                }
                if (!valid) continue;
                printf("Minuman %s %d ml berhasil diubah!",
                    drinks[index].name, drinks[index].size);
                getchar();
            }
            else if (select == 2){
                if (listedDrink == 0){
                    printf("No listed drink yet!"); getchar();
                    continue;
                }
                int index;
                do{
                    printf("Produk mana yang anda mau edit [1..%d]: ", listedDrink);
                    scanf("%d", &index);
                } while (index < 1 || index > listedDrink);
                index--;
                for (int i = index; i < listedDrink-1; i++){
                    drinks[i] = drinks[i+1];
                }
                printf("Minuman berhasil dihapus!"); getchar();
                listedDrink--;
            }
        }
    } while (opt != 5);
}