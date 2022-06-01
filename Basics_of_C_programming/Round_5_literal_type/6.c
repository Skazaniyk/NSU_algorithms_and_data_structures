#include <stdio.h>

void swap_int(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void next_permut(int *a, int n) {
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
    int n, a[27];
    unsigned char symbol;

    scanf("%d", &n);
    scanf("%c", &symbol);
    a[0] = (int) symbol;
    for (int i = 0; i < n; ++i) {
        scanf("%c", &symbol);
        a[i] = (int) symbol;
        scanf("%c", &symbol);
    }

    next_permut(a, n);

    for (int i = 0; i < n; ++i) {
        printf("%c ", (char) a[i]);
    }

    return 0;
}