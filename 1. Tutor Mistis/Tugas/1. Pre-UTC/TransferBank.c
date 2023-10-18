#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// NOTE: KALAU TERMINAL ERROR DAN NGEPRINT TERUS-TERUSAN,
// PENCET "CTRL+C" UNTUK KELUAR DARI TERMINAL!!!

int main()
{
    char nomorRekening[11];
    printf("NOMOR REKENING TUJUAN: ");
    scanf("%s", nomorRekening); getchar();
    printf("\n");

    double nominalTransfer = 0;
    printf("NOMINAL UANG TRANSFER: ");
    scanf("%lf", &nominalTransfer); getchar();

    bool success = false;
    char correctPIN[7] = "161616";
    char userPIN[7];
    int errorCount = 0;

    while (success == false)
    {
        if (errorCount == 3)
        {
            printf("REKENING ANDA DIBLOCK!\n");
            return -1;
        }
        printf("\nMASUKKAN PIN ANDA: ");
        scanf("%s", userPIN); getchar();
        printf("\n");


        if (strcmp(userPIN, correctPIN) == 0)
        {
            printf("UANG SEBESAR %.2lf BERHASIL DITRANSFER KE %s.",
            nominalTransfer, nomorRekening);
            success = true;
        }

        else
        {
            printf("PIN YANG ANDA MASUKKAN SALAH!\n");
            errorCount++;
            printf("ANDA TELAH SALAH SEBANYAK %d KALI.\n", errorCount);
        }
    }
}