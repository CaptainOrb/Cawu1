#include <stdio.h>
#include <string.h>

int len;

void swap(char *x, char *y){
    char tmp = *x;
    *x = *y;
    *y = tmp;
}

void permutate(char *str, int start = 0){
    if (start == len-1){
        printf("%s\n", str);
        return;
    }
    
    for (int target = start; target < len; target++){
        swap(&str[start], &str[target]);
        permutate(str, start+1);
        swap(&str[start], &str[target]);
    }
}

int main(){
    char str[100];
    scanf("%s", str);
    len = strlen(str);

    permutate(str, 0);
}
