#include <stdio.h>

int kthFactor(int n, int k) {
    int d;

    // First pass: find factors up to sqrt(n)
    for (d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            k--;
            if (k == 0) return d;
        }
    }

    // Adjust 'd' back to the start of the second half
    d--;
    if (d * d == n) {
        d--; // Skip duplicate square root
    }

    // Second pass: count complementary factors (n / d) in increasing order
    for (; d >= 1; d--) {
        if (n % d == 0) {
            k--;
            if (k == 0) return n / d;
        }
    }

    return -1; // Fewer than k factors exist
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        printf("%d\n", kthFactor(n, k));
    }
    return 0;
}