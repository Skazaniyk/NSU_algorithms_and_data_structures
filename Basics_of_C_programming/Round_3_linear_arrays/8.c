#include <stdio.h>

int main() {
    long long int n, k, a, array[100001];
    scanf("%lld %lld", &n, &k);

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a);
        array[n - i - 1] = a;
    }

    k = k % n;
    for (int i = 0; i <= k / 2 - 1; ++i) {
        long long int t = array[k - i - 1];
        array[k - i - 1] = array[i];
        array[i] = t;
    }

    for (long long int i = k; i <= (n - k) / 2 + k - 1; ++i) {
        long long int t = array[i];
        array[i] = array[n - 1 - i + k];
        array[n - 1 - i + k] = t;
    }

    for (int i = 0; i < n; ++i) {
        printf("%lld ", array[i]);
    }
    return 0;
}