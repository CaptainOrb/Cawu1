#include <stdio.h>

int main()
{
    int N;
    long long int A[5555];
    int happyCustomer = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
        bool happy = true;
        for (int j = 0; j < i; j++)
        {
            if (A[i] == A[j])
            {
                happy = false;
                break;
            }
        }
        if (happy)
        {
            happyCustomer++;
        }
    }
    printf("%d\n", happyCustomer);
}

// #include <stdio.h>

// int main()
// {
//     int i, j, amount;
//     long long int room[5000];
//     int happy, count = 0;

//     scanf("%d", &amount);

//     for (i = 0; i < amount; i++)
//     {
//         scanf("%lld", &room[i]);
//         happy = 1;
//         for (j = 0; j < i; j++)
//         {
//             if (room[i] == room[j])
//             {
//                 happy = 0;
//                 break;
//             }
//         }
//         if (happy == 1)
//         {
//             count++;
//         }
//     }
//     printf("%d\n", count);
//     return 0;
// }