#include <stdio.h>
#include <math.h>

int main() {
    int n, k, ans = 0;
    scanf("%i", &n);

    while (n > 0) {
        k = n % 10;
        ans = ans * 10 + k;
        n /= 10;
    }

    printf("%i", ans);
    return 0;
}