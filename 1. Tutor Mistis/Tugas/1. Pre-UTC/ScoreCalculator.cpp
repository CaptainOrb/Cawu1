#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void titleScreen()
{
    puts("Score Calculator");
    puts("================");
    puts("1. Add Course");
    puts("2. Course List");
    puts("3. Update Course");
    puts("4. Delete Course");
    puts("5. Total GPA");
    puts("6. Exit");
    printf(">> ");
}

void exitScreen()
{
    puts("Thank you for using the program!");
    getchar();
}

void addCourse(int *ptrListedCourse, char courseName[][69], int courseCredit[69], int courseScore[69])
{
    do {
        printf("Input course name (has to be greater than 5 characters): ");
        scanf("%[^\n]", courseName[*ptrListedCourse]);
        getchar();
    } while (strlen(courseName[*ptrListedCourse]) <= 5);
    do {
        printf("Input course credit (must be an even number): ");
        scanf("%d", &courseCredit[*ptrListedCourse]);
        getchar();
    } while (courseCredit[*ptrListedCourse] % 2 != 0);
    do {
        printf("Input course score (must be less than or equal to 100): ");
        scanf("%d", &courseScore[*ptrListedCourse]);
        getchar();
    } while (courseScore[*ptrListedCourse] < 0 || courseScore[*ptrListedCourse] > 100);

    char tmp;
    do {
        printf("Do you want to proceed? (y/n): ");
        scanf("%c", &tmp);
        getchar();
    } while (tmp != 'y' && tmp != 'n');
    
    if (tmp == 'y')
    {
        (*ptrListedCourse)++;
        printf("\nCourse added!");
        getchar();
        return;
    }
    else
    {
        return;
    }
}

void courseList(int *ptrListedCourse, char courseName[][69], int courseCredit[69], int courseScore[69])
{
    int i;
    for (i = 0; i < *ptrListedCourse; i++)
    {
        printf("+===========================+\n");
        printf("|%-2d| %-12s| %-3d| %-4d|\n", i+1, courseName[i], courseCredit[i], courseScore[i]);
    }
    printf("+===========================+\n");
    printf("Press enter to continue...");
    getchar();
}

void updateCourse(int *ptrListedCourse, char courseName[][69], int courseCredit[69], int courseScore[69])
{
    int i;
    for (i = 0; i < *ptrListedCourse; i++)
    {
        printf("+===========================+\n");
        printf("|%-2d| %-12s| %-3d| %-4d|\n", i+1, courseName[i], courseCredit[i], courseScore[i]);
    }
    printf("+===========================+\n");

    int index;
    do {
        printf("Enter the index of the course you want to update: ");

        scanf("%d", &index);
        getchar();
    } while (index < 1 || index > *ptrListedCourse);

    index -= 1;
    do {
        printf("Input course name (has to be greater than 5 characters): ");
        scanf("%[^\n]", courseName[index]);
        getchar();
    } while (strlen(courseName[index]) <= 5);
    do {
        printf("Input course credit (must be an even number): ");
        scanf("%d", &courseCredit[index]);
        getchar();
    } while (courseCredit[index] % 2 != 0);
    do {
        printf("Input course score (must be less than or equal to 100): ");
        scanf("%d", &courseScore[index]);
        getchar();
    } while (courseScore[index] < 0 || courseScore[index] > 100);

    char tmp;
    do {
        printf("Do you want to proceed? (y/n): ");
        scanf("%c", &tmp);
        getchar();
    } while (tmp != 'y' && tmp != 'n');
    
    if (tmp == 'y')
    {
        printf("\nCourse updated!");
        getchar();
        return;
    }
    else
    {
        return;
    }
}

void deleteCourse(int *ptrListedCourse, char courseName[][69], int courseCredit[69], int courseScore[69])
{
    int i;
    for (i = 0; i < *ptrListedCourse; i++)
    {
        printf("+===========================+\n");
        printf("|%-2d| %-12s| %-3d| %-4d|\n", i+1, courseName[i], courseCredit[i], courseScore[i]);
    }
    printf("+===========================+\n");

    int index;
    do {
        printf("Enter the index of the course you want to delete: ");

        scanf("%d", &index);
        getchar();
    } while (index < 1 || index > *ptrListedCourse);

    index -= 1;
    for (i = index; i < *ptrListedCourse-1; i++)
    {
        strcpy(courseName[i], courseName[i+1]);
        courseCredit[i] = courseCredit[i+1];
        courseScore[i] = courseScore[i+1];
    }

    char tmp;
    do {
        printf("Do you want to proceed? (y/n): ");
        scanf("%c", &tmp);
        getchar();
    } while (tmp != 'y' && tmp != 'n');
    
    if (tmp == 'y')
    {
        (*ptrListedCourse)--;
        printf("\nCourse deleted!");
        getchar();
        return;
    }
    else
    {
        return;
    }
}

void totalGPA(int *ptrListedCourse, char courseName[][69], int courseCredit[69], int courseScore[69])
{
    double sumScore = 0;
    double sumCredit = 0;
    int i;
    for (i = 0; i < *ptrListedCourse; i++)
    {
        sumScore += courseScore[i];
        sumCredit += courseCredit[i];
    }

    double gpa = (sumScore / 20) * (sumCredit * 0.5);

    printf("Your score is %.2lf\n", gpa);
    printf("Press enter to continue...");
    getchar();
}

int main()
{
    int listedCourse = 0;
    int *ptrListedCourse = &listedCourse;
    char courseName[69][69];
    int courseCredit[69];
    int courseScore[69];

    do {
        system("cls");
        titleScreen();
        int userInput;
        scanf("%d", &userInput);
        getchar();

        switch (userInput) {
            case 1: // add course
            {
                system("cls");
                if (listedCourse == 3)
                {
                    puts("You have reached the maximum number of courses!");
                    printf("Press enter to continue...");
                    getchar();
                    continue;
                }
                addCourse(ptrListedCourse, courseName, courseCredit, courseScore);
                continue;
            }
            case 2: // course list
            {
                system("cls");
                courseList(ptrListedCourse, courseName, courseCredit, courseScore);
                continue;
            }
            case 3: // update course
            {
                system("cls");
                updateCourse(ptrListedCourse, courseName, courseCredit, courseScore);
                continue;
            }
            case 4: // delete course
            {
                system("cls");
                deleteCourse(ptrListedCourse, courseName, courseCredit, courseScore);
                continue;
            }
            case 5:
                system("cls");
                totalGPA(ptrListedCourse, courseName, courseCredit, courseScore);
                continue;
            case 6:
            {
                system("cls");
                exitScreen();
                return 0;
            }
        }
    } while (true);
}