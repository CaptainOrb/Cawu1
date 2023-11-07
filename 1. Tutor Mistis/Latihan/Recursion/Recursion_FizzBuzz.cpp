/*
    SIMULASI RECURSION
    Wesley Aldrich
    PPTI 17

    Bahan Belajar Kelompok Tutor Mistis: Fizz Buzz
*/

#include <stdio.h>

int num = 1;
int main(){
    if (num == 101) return 0;
    if (num % 3 == 0) printf("Fizz");
    if (num % 5 == 0) printf("Buzz");
    if (num % 3 != 0 && num % 5 != 0) printf("%d", num);
    printf(" ");
    num++;
    main();
}