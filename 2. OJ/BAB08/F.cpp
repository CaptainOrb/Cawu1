#include <stdio.h>

int main(){
    int N;
    scanf("%d",&N);

    int num;
    for (int i=0; i<N; i++){
        scanf("%d",&num);
        if (num == 1){
            printf("not easy\n");
            return 0;
        }
    }
    printf("easy\n");
}