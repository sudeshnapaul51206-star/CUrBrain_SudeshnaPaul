#include <stdio.h>
#include <stdbool.h>

// Helper function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to find the next prime strictly greater than n
int nextPrime(int n) {
    int candidate = n + 1;
    while (!isPrime(candidate)) {
        candidate++;
    }
    return candidate;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%d\n", nextPrime(n));
    }
    return 0;
}