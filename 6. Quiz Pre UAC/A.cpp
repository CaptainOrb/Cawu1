#include <stdio.h>
#include <string.h>

typedef struct data {
    char phone[260], name[260];
} data;

int binarySearch(data users[], int N, char *target){
    int start = 0;
    int end = N-1;

    while (start <= end){
        int mid = (start+end)/2;

        if (strcmp(users[mid].phone, target) == 0) return mid;
        else if (strcmp(users[mid].phone, target) < 0) start = mid + 1;
        else end = mid-1;
    }
    return -1;
}

int main(){
    data users[10010];
    int listed = 0;

    int N;
    scanf("%d", &N); getchar();

    for (int i = 0; i < N; i++){
        data tmp;
        scanf("%s %[^\n]", tmp.phone, tmp.name); getchar();
        bool isNew = true;
        for (int j = 0; j < listed; j++){
            if (strcmp(users[j].phone, tmp.phone) == 0){
                isNew = false;
                break;
            }
        }
        if (isNew){
            users[listed] = tmp;
            listed++;
        }
    }

    char targetA[260], targetB[260];
    scanf("%[^\n]", targetA); getchar();
    scanf("%[^\n]", targetB); getchar();
    int aIdx = binarySearch(users, listed, targetA);
    int bIdx = binarySearch(users, listed, targetB);

    if (aIdx == -1 || bIdx == -1 || aIdx == bIdx)
        printf("Impossible\n");
    else
        printf("%s is calling %s\n", users[aIdx].name, users[bIdx].name);
}