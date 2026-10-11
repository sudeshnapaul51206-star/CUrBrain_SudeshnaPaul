#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num, result;
    char ch;

    // Read the first number
    scanf("%d%c", &result, &ch);

    // Continue reading numbers until Enter (newline '\n') is pressed
    while (ch != '\n') {
        scanf("%d%c", &num, &ch);
        result = gcd(result, num);
    }

    printf("%d\n", result);
    return 0;
}