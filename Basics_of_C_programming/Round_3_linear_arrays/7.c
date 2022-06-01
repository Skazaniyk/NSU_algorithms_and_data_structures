#include <stdio.h>

int main() {
    long long int n, x, a, array[1000001], ans = -1000001, left = 0, right, middle;
    scanf("%lld %lld", &n, &x);

    array[0] = -1000001;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a);
        array[i] = a;
    }

    right = n - 1;
    while (left <= right) {
        middle = (left + right) / 2;
        if (x == array[middle]) {
            ans = middle;
            break;
        }
        if (x > array[middle]) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    if (ans != -1000001) {
        printf("%lld", ans);
    } else {
        printf("-1");
    }
    return 0;
}