#include <stdio.h>

void permut_to_invtab(int a[], int b[], int n) {
    for (int i = 1; i <= n; ++i) {
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j] == i) {
                b[i - 1] = ans;
                break;
            } else {
                if (a[j] > i) {
                    ++ans;
                }
            }
        }
    }
}

int main() {
    int n, a[1000] = {0}, b[1000] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    permut_to_invtab(a, b, n);

    for (int i = 0; i < n; ++i) {
        printf("%d ", b[i]);
    }

    return 0;
}