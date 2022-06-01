#include <stdio.h>

int main() {
    int n, m, array[11][11], cnt = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &array[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (array[i][j] == 1) {
                ++cnt;
            } else {
                if (cnt != 0) {
                    printf("%d ", cnt);
                    cnt = 0;
                }
            }
        }
        if (cnt != 0) {
            printf("%d ", cnt);
            cnt = 0;
        }
        printf("\n");
    }

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (array[i][j] == 1) {
                ++cnt;
            } else {
                if (cnt != 0) {
                    printf("%d ", cnt);
                    cnt = 0;
                }
            }
        }
        if (cnt != 0) {
            printf("%d ", cnt);
            cnt = 0;
        }
        printf("\n");
    }

    return 0;
}