#include <stdio.h>
#include <stdlib.h>

// process conditions
void processScreen(int screen);
void processShape(int shape);

// screens
void mainScreen();
void shapeAreaCalculator();
void gradeCalculator();
void exitingScreen();

// spesific functions
void squareCalculator();
void rectangleCalculator();
void triangleCalculator();
char getGrade(double average);

// final screen
void continueScreen();

// =======================================

int main()
{
    mainScreen();
}

void processScreen(int screen)
{
    if (screen == 1)
    {
        // Shape Area Calculator
        shapeAreaCalculator();
    }
    else if (screen == 2)
    {
        // Grade Calculator
        gradeCalculator();
    }
    else if (screen == 3)
    {
        // Exit
        exitingScreen();
    }
    else
    {
        mainScreen();
    }
}

void processShape(int shape)
{
    if (shape == 1)
    {
        // Square
        squareCalculator();
    }
    else if (shape == 2)
    {
        // Rectangle
        rectangleCalculator();
    }
    else if (shape == 3)
    {
        // Triangle
        triangleCalculator();
    }
    else if (shape == 0)
    {
        // Back
        mainScreen();
    }
    else
    {
        shapeAreaCalculator();
    }
}

void mainScreen()
{
    puts("Selection and Repetition");
    puts("========================");
    puts("1. Shape Area Calculator");
    puts("2. Grade Calculator");
    puts("3. Exit");
    printf(">> ");

    int userSelection;
    scanf("%d", &userSelection);

    system("cls");
    processScreen(userSelection);
}

void shapeAreaCalculator()
{
    puts("Shape Area Calculator");
    puts("=====================");
    puts("1. Square");
    puts("2. Rectangle");
    puts("3. Triangle");
    puts("0. Back");
    printf(">> ");

    int userSelection;
    scanf("%d", &userSelection);
    system("cls");
    processShape(userSelection);
}

void gradeCalculator()
{
    double mathScore = -1;
    double englishScore = -1;
    double historyScore = -1;
    double artScore = -1;
    while ((mathScore > 10) || (mathScore < 0))
    {
        printf("Enter Math Score [0.0 - 10.0]: ");
        scanf("%lf", &mathScore);
    }
    while ((englishScore > 10) || (englishScore < 0))
    {
        printf("Enter English Score [0.0 - 10.0]: ");
        scanf("%lf", &englishScore);
    }
    while ((historyScore > 10) || (historyScore < 0))
    {
        printf("Enter History Score [0.0 - 10.0]: ");
        scanf("%lf", &historyScore);
    }
    while ((artScore > 10) || (artScore < 0))
    {
        printf("Enter Art Score [0.0 - 10.0]: ");
        scanf("%lf", &artScore);
    }

    double averageScore = (mathScore + englishScore + historyScore + artScore) / 4;
    system("cls");

    printf("Report Card\n");
    printf("===========\n");
    printf("Math: %.1lf\n", mathScore);
    printf("English: %.1lf\n", englishScore);
    printf("History: %.1lf\n", historyScore);
    printf("Art: %.1lf\n", artScore);
    printf("Average: %.1lf\n", averageScore);
    printf("Final Grade: %c", getGrade(averageScore));

    getchar();
    continueScreen();
    mainScreen();
}

void exitingScreen()
{
    puts("\"Wonderful things can be achieved when there's ");
    puts(" teamwork, hardwork, and perseverance\"");
    puts(" - BlueJackets 22-2");
    printf("\n\t\t\t\"Berisik lu\" - Vinsen");
    getchar();
    continueScreen();
}

void squareCalculator()
{
    printf("Input Side: ");
    double side;
    scanf("%lf", &side);

    double squareArea = side * side;
    printf("Square Area: %.2lf", squareArea);
    getchar();
    continueScreen();
    shapeAreaCalculator();
}

void rectangleCalculator()
{
    printf("Input Height: ");
    double height;
    scanf("%lf", &height);
    printf("Input Width: ");
    double width;
    scanf("%lf", &width);

    double rectangleArea = height * width;
    printf("Rectangle Area: %.2lf", rectangleArea);
    getchar();
    continueScreen();
    shapeAreaCalculator();
}

void triangleCalculator()
{
    printf("Input Base: ");
    double base;
    scanf("%lf", &base);
    printf("Input Height: ");
    double height;
    scanf("%lf", &height);

    double triangleArea = base * height / 2;
    printf("Triangle Area: %.2lf", triangleArea);
    getchar();
    continueScreen();
    shapeAreaCalculator();
}

char getGrade(double average)
{
    if (average >= 9)
    {
        return 'A';
    }
    else if (average >= 8)
    {
        return 'B';
    }
    else if (average >= 7)
    {
        return 'C';
    }
    else if (average >= 6)
    {
        return 'D';
    }
    else if (average < 6)
    {
        return 'F';
    }
    else
    {
        return '0';
        puts("Error Code 1");
    }
}

void continueScreen()
{
    printf("\n\n");
    puts("=======================");
    puts("Press enter to continue");
    getchar();
    system("cls");
}