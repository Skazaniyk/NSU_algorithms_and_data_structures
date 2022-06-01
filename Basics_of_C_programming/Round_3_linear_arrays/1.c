#include <stdio.h>

int main() {
    int n, a, array_1[100], array_2[100], b;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        array_1[i] = a;
    }

    for (int j = 1; j <= n; ++j) {
        b = 0;
        for (int k = j + 1; k <= n; ++k) {
            if (array_1[j] > array_1[k]) {
                ++b;
            }
        }
        array_2[j] = b;
    }

    for (int l = 1; l <= n; ++l) {
        printf("%d ", array_2[l]);
    }

    return 0;
}
