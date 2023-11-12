/*
    LATIHAN SOAL
    Wesley Aldrich
    PPTI 17

    Bahan Belajar Kelompok Tutor Mistis: Diet Plan

    Catatan: Soal dimodifikasi dengan tambahan syarat
    "If there is milk remaining (not zero) at the end, your plan is failed."
*/

#include <stdio.h>

int result = 0;

void survive(int days, int milk, int cookie, int needs[], int currentDay = 1){
    // use milk
    if (milk >= needs[currentDay] && currentDay <= days){
        if (milk-needs[currentDay] == 0 && currentDay > result) result = currentDay;
        survive(days, milk-needs[currentDay], cookie, needs, currentDay+1);
    }

    // use cookie
    if (cookie > 0 && currentDay <= days){
        if (milk-needs[currentDay] == 0 && currentDay > result) result = currentDay;
        survive(days, milk, cookie-1, needs, currentDay+1);
    }
}

int main(){
    int days, milk, cookie;
    scanf("%d %d %d", &days, &milk, &cookie);

    int needs[100];
    for (int i = 1; i <= days; i++) scanf("%d", &needs[i]);

    survive(days, milk, cookie, needs);
    printf("%d\n", result);
}