#include <stdio.h>

int main() {
    int n, a = 1, b;
    long long ans = 0;
    scanf("%d", &n);

    while (a * a * a <= n) {
        b = a;
        while (a * b * b <= n) {
            ans += n / (a * b) - (b - 1);
            ++b;
        }
        ++a;
    }

    printf("%lld", ans);
    return 0;
}