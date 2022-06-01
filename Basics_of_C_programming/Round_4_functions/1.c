#include <stdio.h>

int gcd(int a, int b) {
    while ((a > 0) && (b > 0)) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return (a + b);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d", gcd(a, b));
    return 0;
}