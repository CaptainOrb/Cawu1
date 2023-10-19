#include <stdio.h>

int main()
{
    double nilaiTugas, nilaiMid, nilaiUjian;
    scanf("%lf %lf %lf", &nilaiTugas, &nilaiMid, &nilaiUjian);
    // nilaiUjian *= 2;
    // nilaiMid *= 3;
    // nilaiUjian *= 5;
    double average = (nilaiTugas*2/10 + nilaiMid*3/10 + nilaiUjian/2);
    printf("%.2lf\n", average);
}