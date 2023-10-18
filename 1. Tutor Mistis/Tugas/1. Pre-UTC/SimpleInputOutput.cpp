#include <stdio.h>
#include <math.h>

int main()
{
    printf("Simple Input\\Output Program\n");
    printf("===========================\n");
    printf("Welcome to \"Algorithm and Programming\"!\n\n");

    // puts("Simple Input\\Output Program"); // auto newline
    // puts("===========================");
    // puts("Welcome to \"Algorithm and Programming\"");

    // Duplicate Line: VScode (CTRL + ALT + down), Dev C++ (CTRL + E)

    // Everything that we typed (not yet entered/sent) is stored in "Input Buffer".
    // Example: If we input "abcde", the input buffer will take "abcde\n".

    // Both %s and %c will take things from the input buffer.
    // That's why we need getchar(), to prevent "uncleared" newline.

    char userName[101];
    int age;
    printf("Enter your name: ");
    scanf("%[^\n]", userName);
    getchar(); // try without getchar
    printf("Enter your age: ");
    scanf("%d", &age);
    getchar();
    printf("\n");

    printf("Hi, %s!\n\n", userName);

    double num1, num2;
    printf("Enter first number: ");
    scanf("%lf", &num1);
    getchar();
    printf("Enter second number: ");
    scanf("%lf", &num2);
    getchar();
    printf("Arithmetic Calculation Result:\n");
    printf("\t%lf + %lf = %.2lf\n", num1, num2, num1 + num2);
    printf("\t%lf - %lf = %.2lf\n", num1, num2, num1 - num2);
    printf("\t%lf * %lf = %.2lf\n", num1, num2, num1 * num2);
    printf("\t%lf / %lf = %.2lf\n\n", num1, num2, num1 / num2);

    // int integer1 = trunc(num1);
    // int integer2 = trunc(num2);
    int integer1 = (int)num1;
    int integer2 = (int)num2;

    printf("Number Checking Result:\n");
    printf("\tFirst Number: %d\n", integer1);
    printf("\tSecond Number: %d\n", integer2);
    printf("\tFirst Number is Odd Number: %d\n", (integer1 % 2 == 1));
    printf("\tFirst Number is Even Number: %d\n", (integer1 % 2 == 0));
    printf("\tSecond Number is Odd Number: %d\n", (integer2 % 2 == 1));
    printf("\tSecond Number is Even Number: %d\n", (integer2 % 2 == 0));

    puts("Press any key to exit...");
    getchar(); // to make the terminal not stop immediately
    return 0;
}