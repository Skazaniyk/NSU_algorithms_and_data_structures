#include <stdio.h>

int is_function(int R[90000][2], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (R[i][0] == R[j][0]) {
                return 0;
            }
        }
    }
    return 1;
}

int everywhere_defined_function(int n, int m) {
    if (n == m) {
        return 1;
    }
    return 0;
}

int injection(int R[90000][2], int n) {
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = i + 1; j < n; ++j) {
            if (R[i][1] == R[j][1]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int n, m, R[90000][2] = {0};

    scanf("%d%d", &n, &m);
    if (n < m) {
        printf("0");
        return 0;
    }

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &R[i][0], &R[i][1]);
        if ((R[i][0] > n) || (R[i][1] > n) || (R[i][0] < 1) || (R[i][1] < 1)) {
            printf("0");
            return 0;
        }
    }

    if (is_function(R, m) == 1) {
        printf("1 ");
        if (everywhere_defined_function(n, m) == 1) {
            printf("2 ");
        }
    }

    if (injection(R, m) == 1) {
        printf("3 ");
        if (is_function(R, m) && everywhere_defined_function(n, m) == 1) {
            printf("4 5");
        }
    }

    if (!is_function(R, m) && !injection(R, m)) {
        printf("0");
    }
    return 0;
}