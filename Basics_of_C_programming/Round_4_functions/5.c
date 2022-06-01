#include <stdio.h>

void shake_sort(int *a, int n) {
    int f = 1, left = 0, right = n - 1;

    while (f == 1) {
        f = 0;
        int i = left;

        while (i < right) {
            if (a[i] > a[i + 1]) {
                int t = a[i];
                a[i] = a[i + 1];
                a[i + 1] = t;
                f = 1;
            }
            ++i;
        }
        --right;

        if (f == 1) {
            f = 0;
            i = right;
            while (i > left) {
                if (a[i] < a[i - 1]) {
                    int t = a[i];
                    a[i] = a[i - 1];
                    a[i - 1] = t;
                    f = 1;
                }
                --i;
            }
        }
        ++left;
    }
}

int main() {
    int n, a[100000];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    shake_sort(a, n);

    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}