#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        int N;
        scanf("%d", &N);

        int arr[100];
        int xorResult[10000], index = 0;
        int onBit = 0, offBit = 0;
        int threeBit = 0;
        int threeOffBit = 0;
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &arr[j]);
        }

        for (int j = 0; j < N - 1; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                xorResult[index] = arr[j] ^ arr[k];
                index++;
            }
        }

        for (int j = 0; j < index; j++)
        {
            // printf("%d ", xorResult[j]);
            int remainder = xorResult[j];
            int bit;

            while (remainder >= 1)
            {
                bit = remainder % 2;
                // printf("%d ", bit);
                remainder /= 2;

                if (bit == 1)
                {
                    onBit++;
                }
                else if (bit == 0)
                {
                    offBit++;
                }
                else
                {
                    printf("Error Code 1.\n");
                }
            }

            if (onBit >= 3)
            {
                threeBit++;
            }
            else
            {
                threeOffBit++;
            }
        }

        printf("Case #%d: %d %d\n", i, threeBit, threeOffBit);
    }
}