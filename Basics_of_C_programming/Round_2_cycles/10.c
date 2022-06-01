#include <stdio.h>
#include <math.h>


int main(void) {
    int k, l = -1, n = 1, x, ans;
    scanf("%d", &k);

    while (l == -1) {
        if ((9 * pow(10, n - 2) * (n - 1) < k) && (k <= 9 * pow(10, n - 1) * n)) {
            l = n;
        }
        k -= 9 * pow(10, n - 2) * (n - 1);
        n++;
    }

    x = pow(10, l - 1);
    while (k > l) {
        x++;
        k -= l;
    }
    ans = x / (pow(10, l - k));
    ans %= 10;

    printf("%d", ans);
    return 0;
}