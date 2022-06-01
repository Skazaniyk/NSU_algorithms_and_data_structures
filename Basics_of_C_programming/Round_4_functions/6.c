#include <stdio.h>

int invtab_to_permut(int b[], int a[], int n) {
    int flag = 1;
    for (int i = 0; i < n; ++i) {
        if (0 > b[i] || b[i] > (n - i - 1)) {
            flag = 0;
            break;
        }
    }

    if (flag == 0) {
        return 0;
    } else {
        for (int j = 1; j <= n; ++j) {
            int i = 0, position = b[j - 1] + 1;
            while (position > 0) {
                if (a[i] == 0) {
                    --position;
                }
                ++i;
            }
            a[i - 1] = j;
        }
    }

    return 1;
}

int main() {
    int n, a[1000] = {0}, b[1000] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }

    if (invtab_to_permut(b, a, n) == 0) {
        printf("NO");
    } else {
        for (int i = 0; i < n; ++i) {
            printf("%d ", a[i]);
        }
    }

    return 0;
}