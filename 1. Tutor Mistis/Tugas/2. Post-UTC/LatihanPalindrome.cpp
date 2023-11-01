#include <stdio.h>
#include <string.h>

bool isPalindrome(char *str){
    int left = 0;
    int right = strlen(str)-1;
    while (left < right){
        // tinggal ubah 2 line di bawah ini
        while (str[left] == ' ' || str[left] == ',') left++;
        while (str[right] == ' ' || str[right] == ',') right--;
        if (str[left] == str[right]){
            left++; right--;
        }
        else return false;
    }
    return true;
}

int main(){
    do {
        char str[100];
        scanf("%[^\n]", str); getchar();
        if (isPalindrome(str)) printf("YES\n");
        else printf("NO\n");
    } while(true);
}