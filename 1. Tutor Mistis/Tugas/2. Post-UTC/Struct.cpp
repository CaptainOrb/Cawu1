#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    size struct mahasiswa selalu dibulatin 
    ke atas hingga kelipatan 4 (karena ada int)
*/

void selectionMenu(){
    system("cls");
    printf("MENU\n");
    printf("1. Insert Student Data\n");
    printf("2. View Student Data\n");
    printf("3. Edit Student Data\n");
    printf("4. Delete Student Data\n");
    printf("5. Exit\n");
    printf(">> ");
}

struct dob {
    int date, month, year;
};

typedef struct mahasiswa {
    char nim[11];
    char name[51];
    int age;
    float gpa;
    struct dob birthDay;
} student;

int arr[10];

void insertData(student _11LA[], int *listedStudent){
    system("cls");
    do {
        printf("Insert new student NIM: "); scanf("%s", _11LA[*listedStudent].nim);
        getchar();
    } while (strlen(_11LA[*listedStudent].nim) != 10);
    do {
        printf("Insert new student name: "); scanf("%[^\n]", _11LA[*listedStudent].name);
        getchar();
    } while (strlen(_11LA[*listedStudent].name) < 3);
    do {
        printf("Insert new student age: "); scanf("%d", &_11LA[*listedStudent].age);
        getchar();
    } while (_11LA[*listedStudent].age < 17);
    do {
        printf("Insert new student gpa: "); scanf("%f", &_11LA[*listedStudent].gpa);
        getchar();
    } while (_11LA[*listedStudent].gpa < 1.5 || _11LA[*listedStudent].gpa > 4);
    printf("DATA ADDED SUCCESSFULLY!\n");
    printf("Press enter to continue..."); getchar();
    (*listedStudent)++;
}

void viewData(student _11LA[], int listedStudent){
    system("cls");
    for (int i = 0; i < listedStudent; i++){
        printf("Nim of Warrior %d: %s\n", i+1, _11LA[i].nim);
        printf("Name of Warrior %d: %s\n", i+1, _11LA[i].name);
        printf("Age of Warrior %d: %d\n", i+1, _11LA[i].age);
        printf("GPA of Warrior %d: %.2f\n", i+1, _11LA[i].gpa);
        printf("\n");
    }
    printf("Press enter to continue..."); getchar();
}

void editData(student _11LA[], int listedStudent){
    system("cls");
    int editIndex;
    do {
        printf("Index of Data to Edit [1...%d]: ", listedStudent); scanf("%d", &editIndex);
        getchar();
    } while (editIndex < 1 || editIndex > listedStudent);
    editIndex--;
    do {
        printf("Insert new student NIM: "); scanf("%s", _11LA[editIndex].nim);
        getchar();
    } while (strlen(_11LA[editIndex].nim) != 10);
    do {
        printf("Insert new student name: "); scanf("%[^\n]", _11LA[editIndex].name);
        getchar();
    } while (strlen(_11LA[editIndex].name) < 3);
    do {
        printf("Insert new student age: "); scanf("%d", &_11LA[editIndex].age);
        getchar();
    } while (_11LA[editIndex].age < 17);
    do {
        printf("Insert new student gpa: "); scanf("%f", &_11LA[editIndex].gpa);
        getchar();
    } while (_11LA[editIndex].gpa < 1.5 || _11LA[editIndex].gpa > 4);
    printf("DATA EDITED SUCCESSFULLY!\n");
    printf("Press enter to continue..."); getchar();
}

void deleteData(student _11LA[], int *listedStudent){
    system("cls");
    int editIndex;
    do {
        printf("Index of Data to Delete [1...%d]: ", *listedStudent); scanf("%d", &editIndex);
        getchar();
    } while (editIndex < 1 || editIndex > *listedStudent);
    editIndex--;
    for (int i = editIndex; i < *listedStudent-1; i++){
        _11LA[i] = _11LA[i+1];
    }
    (*listedStudent)--;
    
    printf("DATA DELETED SUCCESSFULLY!\n");
    printf("Press enter to continue..."); getchar();
}

int main(){
    student student1;
    printf("Sizeof arr: %d\n", sizeof(arr));
    printf("Sizeof student: %d\n", sizeof(student1));

    student student2 = {"2702363613", "Wesley Aldrich", 18, 4};
    printf("Nim of Student 2: %s\n", student2.nim);
    printf("Name of Student 2: %s\n", student2.name);
    printf("Age of Student 2: %d\n", student2.age);
    printf("GPA of Student 2: %.2f\n", student2.gpa);
    printf("\n");

    // student1 = student2;
    strcpy(student1.nim, "2702123456");
    strcpy(student1.name, "Putu Artika");
    student1.age = 17;
    student1.gpa = 3.98;
    printf("Nim of Student 1: %s\n", student1.nim);
    printf("Name of Student 1: %s\n", student1.name);
    printf("Age of Student 1: %d\n", student1.age);
    printf("GPA of Student 1: %.2f\n", student1.gpa);
    printf("\n\n");

    printf("Press enter to proceed to menu..."); getchar();

    student warriors[35];
    int listedStudent = 0;
    int userSelection;
    do {
        selectionMenu();
        scanf("%d", &userSelection); getchar();
        
        if (userSelection == 1) insertData(warriors, &listedStudent);
        else if (userSelection == 2) viewData(warriors, listedStudent);
        else if (userSelection == 3) editData(warriors, listedStudent);
        else if (userSelection == 4) deleteData(warriors, &listedStudent);
    } while (userSelection != 5);

    student tika = {
        "12345678", "Artika Chintya Meliana", 18, 3.98,
        {3, 3, 2005} // atau tanpa kurung kurawal juga bisa
    };
}