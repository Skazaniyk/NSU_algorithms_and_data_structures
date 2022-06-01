#include <stdio.h>

long long lcm(long long a, long long b) {
    long long m = a * b;
    while ((a > 0) && (b > 0)) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return (m / (a + b));
}

int main() {
    long long n, a, b, array[5050];
    scanf("%lld", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &a, &b);
        array[i] = lcm(a, b);
    }

    for (int i = 0; i < n; ++i) {
        printf("%lld \n", array[i]);
    }
    return 0;
}