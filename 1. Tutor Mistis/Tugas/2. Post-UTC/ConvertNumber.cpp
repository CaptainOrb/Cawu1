#include <stdio.h>

void toBinary(unsigned long long *num){
    unsigned long long ret = 0;
    unsigned long long tmp = *num;
    unsigned long long indexPlacer = 1;
    while (tmp != 0){
        ret += (tmp%2) * indexPlacer;
        printf("%llu %llu %llu bit = %llu\n", ret, indexPlacer, tmp, tmp%2);
        indexPlacer *= 10;
        tmp /= 2;
    }
    *num = ret;
}

// void toBinaryStr(int *num){
//     char res[17];
//     int index = 0;
//     int tmp = *num;
//     while (tmp != 0){
//         res[index++] = (tmp % 2) + '0';
//         tmp /= 2;
//     }
//     for (int i = index-1; i >= 0; i--) printf("%c", res[i]);
//     printf("\n");
// }

int main(){
    unsigned long long num;
    printf("Input number: "); scanf("%llu",&num);
    int opt;
    do {
        printf("1. Binary\n");
        printf("2. Octal\n");
        printf("3. Hexadecimal\n");
        printf(">> "); scanf("%d",&opt);

        if (opt == 1){
            toBinary(&num);
            printf("%llu\n", num);
        }
        // else if (opt == 2) toOctal(&num);
        // else if (opt == 3) toBinary(&num);
    } while (true);
}