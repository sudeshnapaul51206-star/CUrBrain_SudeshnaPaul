#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int countPrimes(int n) {
    if (n <= 2) return 0;

    bool *isPrime = (bool *)malloc((size_t)n * sizeof(bool));
    if (!isPrime) return 0;

    for (int i = 0; i < n; i++) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;

    for (long long p = 2; p * p < n; p++) {
        if (isPrime[p]) {
            for (long long multiple = p * p; multiple < n; multiple += p) {
                isPrime[multiple] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            count++;
        }
    }

    free(isPrime);
    return count;
}

int main(void) {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%d\n", countPrimes(n));
    }
    return 0;
}