#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge(char str[][100], int start, int mid, int end){
    int leftLength = mid - start + 1;
    int rightLength = end - mid;

    char tmpL[50][100], tmpR[50][100];
    for (int i = 0; i < leftLength; i++) strcpy(tmpL[i], str[start+i]);
    for (int i = 0; i < rightLength; i++) strcpy(tmpR[i], str[mid+1+i]);

    int L = 0, R = 0, index = start;
    while (L < leftLength && R < rightLength){
        if (strcmp(tmpL[L], tmpR[R]) <= 0) strcpy(str[index++], tmpL[L++]);
        else strcpy(str[index++], tmpR[R++]);
    }
    while (L < leftLength) strcpy(str[index++], tmpL[L++]);
    while (R < rightLength) strcpy(str[index++], tmpR[R++]);
}

void mergeSort(char str[][100], int start, int end){
    if (start >= end) return;

    int mid = (start + end)/2;
    mergeSort(str, start, mid);
    mergeSort(str, mid+1, end);
    merge(str, start, mid, end);
}

void sortContacts(char str[][100], int size){
    mergeSort(str, 0, size-1);
}

void showMenu(){
    system("cls");
    printf("Phonebook Menu:\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact (Linear)\n");
    printf("3. Search Contact (Binary)\n");
    printf("4. Search Contact (Interpolation)\n");
    printf("5. Display Contact\n");
    printf("6. Quit\n");
    printf("Enter your choice: ");
}

void addContact(char contacts[][100], int *listed){
    system("cls");
    do {
        printf("Enter the contact name: ");
        scanf("%[^\n]", contacts[*listed]); getchar();
    } while (strlen(contacts[*listed]) < 4);
    printf("Contact added: %s\n", contacts[*listed]);
    (*listed)++;
    printf("Press enter to continue..."); getchar();

    sortContacts(contacts, *listed);
}

void displayContact(char contacts[][100], int listed){
    system("cls");
    printf("+============+\n");
    printf("|  Contacts  |\n");
    printf("+============+\n");
    for (int i = 0; i < listed; i++) printf("%d | %s\n", i, contacts[i]);
    printf("Press enter to continue..."); getchar();
}

void linearSearch(char contacts[][100], int listed){
    system("cls");
    char target[100];
    do {
        printf("Enter the contact name to search (Linear): ");
        scanf("%[^\n]", target); getchar();
    } while (strlen(target) < 4);
    int index = -1;
    for (int i = 0; i < listed; i++){
        if (strcmp(contacts[i], target) == 0){
            index = i; break;
        }
    }
    if (index == -1) printf("Contact not found.\n");
    else printf("Contact found at index %d.\n", index);
    printf("Press enter to continue..."); getchar();
}

void binarySearch(char contacts[][100], int listed){
    system("cls");
    char target[100];
    do {
        printf("Enter the contact name to search (Binary): ");
        scanf("%[^\n]", target); getchar();
    } while (strlen(target) < 4);
    int index = -1;
    int start = 0; int end = listed - 1;
    while (start <= end){
        int mid = (start+end)/2;
        if (strcmp(contacts[mid], target) == 0){
            index = mid; break;
        }
        else if (strcmp(contacts[mid], target) > 0) end = mid-1;
        else if (strcmp(contacts[mid], target) < 0) start = mid+1;
    }
    if (index == -1) printf("Contact not found.\n");
    else printf("Contact found at index %d.\n", index);
    printf("Press enter to continue..."); getchar();
}

void interpolationSearch(char contacts[][100], int listed){
    system("cls");
    char target[100];
    do {
        printf("Enter the contact name to search (Interpolation): ");
        scanf("%[^\n]", target); getchar();
    } while (strlen(target) < 4);
    int index = -1;

    int start = 0, end = listed - 1; // interpolation for strings
    while (start <= end){
        int mid = start + ((double)(end - start) / (strcmp(contacts[end], contacts[start]))) * (strcmp(target, contacts[start]));
        if (strcmp(contacts[mid], target) == 0){
            index = mid; break;
        }
        else if (strcmp(contacts[mid], target) > 0) end = mid-1;
        else if (strcmp(contacts[mid], target) < 0) start = mid+1;
    }
    if (index == -1) printf("Contact not found.\n");
    else printf("Contact found at index %d.\n", index);
    printf("Press enter to continue..."); getchar();
}

int main(){
    int listed = 0;
    char contacts[100][100];

    int menuInput;
    do {
        showMenu();
        scanf("%d",&menuInput); getchar();

        if (menuInput == 1) addContact(contacts, &listed);
        else if (menuInput == 2) linearSearch(contacts, listed);
        else if (menuInput == 3) binarySearch(contacts, listed);
        else if (menuInput == 4) interpolationSearch(contacts, listed);
        else if (menuInput == 5) displayContact(contacts, listed);
    } while (menuInput != 6);

    system("cls");
    printf("Thank you for using this phonebook.");
    getchar(); system("cls");
}