#include <stdio.h>
#include <string.h>

int abso(int x, int y){
    int tmp = x - y;
    if (tmp < 0) return -tmp;
}

int anagramDeletion(char str1[], char str2[]){
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int tmp1[256] = {0}, tmp2[256] = {0};
    for (int i = 0; i < len1; i++){
        tmp1[str1[i] - 'a']++;
    }
    // for (int i = 0; i < 26; i++){
    //     printf("%d ", tmp1[i]);
    // }
    // printf("\n");
    for (int i = 0; i < len2; i++){
        tmp2[str2[i] - 'a']++; 
    }
    // for (int i = 0; i < 26; i++){
    //     printf("%d ", tmp2[i]);
    // }
    // printf("\n");

    int del = 0;
    for (int i = 0; i < 26; i++){
        if (tmp1[i] - tmp2[i] != 0) del += abso(tmp1[i], tmp2[i]);
    }
    
    if (del == len1 + len2) return -1;
    return del;
}

int main(){
    int T;
    scanf("%d",&T); getchar();
    for (int tc = 1; tc <= T; tc++){
        char N[256], M[256];

        scanf("%[^\n]", N); getchar();
        scanf("%[^\n]", M); getchar();

        int deletionRequired = anagramDeletion(N, M);
	
		printf("Test %d: ", tc);
        if (deletionRequired == -1){
            printf("Anagram not found!\n");
		}
        else{
            printf("%d\n", deletionRequired);
		}
    }
}
