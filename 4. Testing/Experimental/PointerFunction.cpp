#include <stdio.h>

int pangkatDua(int num)
{
    return num * num;
}

int pangkatTiga(int num)
{
    return num * num * num;
}

int main()
{
    int number;
    scanf("%d", &number);

    int (*pangkat[])(int) = {pangkatDua, pangkatTiga};

    int select;
    scanf("%d", &select);
    // sesuai indeks:
    // jika kita input angka 0, maka fungsi pangkatDua yang akan dijalankan
    // jika kita input angka 1, maka fungsi pangkatTiga yang akan dijalankan

    printf("%d\n", (pangkat[select])(number));
}