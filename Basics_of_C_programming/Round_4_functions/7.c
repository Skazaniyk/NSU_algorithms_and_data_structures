#include <stdio.h>

void swap_int(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void next_permut(int a[], int n) {
    int i = n - 1;
    while (i > 0) {
        if (a[i - 1] < a[i]) {
            break;
        }
        --i;
    }

    if (i == 0) {
        for (int j = 0; j < n / 2; ++j) {
            swap_int(&a[j], &a[n - j - 1]);
        }
        return;
    }

    for (int j = i; j < (n + i) / 2; ++j) {
        swap_int(&a[j], &a[n + i - j - 1]);
    }

    for (int j = i; j < n; ++j) {
        if (a[i - 1] < a[j]) {
            swap_int(&a[i - 1], &a[j]);
            break;
        }
    }
}

int main() {
    int n, a[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    next_permut(a, n);

    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }

    return 0;
}