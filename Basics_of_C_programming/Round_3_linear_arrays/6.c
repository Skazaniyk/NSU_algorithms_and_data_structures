#include <stdio.h>

int main() {
    int n, a, array[5000] = {0}, sum = 0, L = 0, R = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        sum += a;
        array[i] = sum;
    }

    int sum_max = array[0];
    for (int l = 0; l < n - 1; ++l) {
        for (int r = l + 1; r < n; ++r) {
            sum = array[r] - array[l];
            if (sum > sum_max) {
                sum_max = sum;
                L = l + 1;
                R = r;
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        if (array[k] > sum_max) {
            sum_max = array[k];
            L = 0;
            R = k;
        }
    }

    printf("%d %d %d", L, R, sum_max);
    return 0;
}