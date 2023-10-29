#include <stdio.h>

/*
    UNION NGIKUTIN SIZE DATA TYPE TERBESAR
*/

typedef union test {
    int di;
    char dc[3];
} bil;

int main(){
    bil bil1;

    printf("Sizeof bil: %d\n", sizeof(bil));

    bil1.di = 321;
    printf("di = %d\n", bil1.di);
    printf("dc[0] = %d\n", bil1.dc[0]);
    printf("dc[0] = %c\n", bil1.dc[0]);
    printf("dc[1] = %d\n", bil1.dc[1]);
    printf("dc[1] = %c\n", bil1.dc[1]);
}