#include <stdio.h>

int main() {
    long long int n, a, array[1000500] = {0};
    scanf("%lld", &n);

    for (long long int i = 1; i <= n; ++i) {
        array[i] = i;
    }

    for (long long int j = 2; j <= n; ++j) {
        if (array[j] != 0) {
            for (long long int k = j * j; k <= n; k += j) {
                array[k] = 0;
            }
        }
    }

    for (long long int i = 2; i <= n; ++i) {
        if (array[i] != 0) {
            printf("%lld ", array[i]);
        }
    }

    return 0;
}