#include <stdio.h>

int main() {
    long long int n, a, array[100000] = {0}, sum;
    scanf("%lld", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a);
        array[i] = a;
    }

    for (int i = 1; i <= n; ++i) {
        sum = 0;
        for (int j = i; j <= n; j += i) {
            sum += array[j];
        }
        printf("%lld \n", sum);
    }

    return 0;
}