#include <stdio.h>
#include <string.h>

bool isUnique(char *str, int length, char listed[][1001], int listedPalindrome){
    for (int i = 0; i < listedPalindrome; i++)
        if (strncmp(str, listed[i], length) == 0) return false;
    return true;
}

bool isUniquePalindrome(char *str, int length, char listed[][1001], int listedPalindrome){
    int left = 0, right = length-1;
    while (left < right)
        if (str[left++] != str[right--]) return false;
    if (isUnique(str, length, listed, listedPalindrome)) return true;
    else return false;
}

int main(){
    char str[1001];
    scanf("%s", str); getchar();

    int length = strlen(str);
    int palindromeCount = 0;
    for (int sublength = 1; sublength <= length; sublength++){
        char listed[1001][1001] = {};
        int listedPalindrome = 0;
        for (int start = 0; start < length-sublength+1; start++){
            if (isUniquePalindrome(str + start, sublength, listed, listedPalindrome)){
                palindromeCount++;
                strncpy(listed[listedPalindrome++], str+start, sublength);
            }
        }
    }
    printf("%d\n", palindromeCount);
}