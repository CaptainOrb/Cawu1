#include <stdio.h>

bool fun(int A, int B){
    if (A == B) return true;
    else if (A == 1) return false;
    else if (A % 2 == 0) fun(A/2, B);
    else if (A % 2 != 0) fun(A*3+1, B);
}

int main(){
    int T;
    scanf("%d",&T);
    for (int tc = 1; tc <= T; tc++){
        int A, B;
        scanf("%d %d",&A,&B);
        printf("Case #%d: ", tc);
        if (fun(A, B)) printf("YES\n");
        else printf("NO\n");
    }
}