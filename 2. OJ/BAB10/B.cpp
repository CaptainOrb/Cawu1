#include <stdio.h>

unsigned long long M;
unsigned long long K;
unsigned long long low;
unsigned long long high;
unsigned long long mid;
unsigned long long sum;
// long double sum;

unsigned long long binarySumSearch(unsigned long long target) {
    low = 1;
    high = 1500000;

    while (low < high) {
        mid = low + (high - low) / 2;
        sum = mid * (mid + 1) * (2 * mid + 1) / 6;
        if (sum >= target)
            high = mid;
        else
            low = mid + 1;
    }
    return high;
}

int main() {
    int Q;
    scanf("%d", &Q);
    for (int tc = 1; tc <= Q; tc++) {
        scanf("%llu", &M);

        K = binarySumSearch(M);
        printf("Case #%d: %llu\n", tc, K);
    }
}