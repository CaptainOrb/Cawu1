#include <stdio.h>

int survivor = -1;
void josephus(int people[], int N, int K){
    int index = 0;
    int killed = 0;
    while (killed < N){
        for (int i = 1; i <= K; i++){
            index++;
            while (people[index%N] == 1) index++;
        }
        people[index%N] = 1;
        killed++;
    }
    survivor = index%N;
}

int main(){
    int T;
    scanf("%d", &T);
    
    for (int tc = 1; tc <= T; tc++){
        int people[10000] = {0};
        int N, K;
        scanf("%d %d", &N, &K);

        josephus(people, N, K);
        printf("Case #%d: %d\n", tc, survivor);
    }
}