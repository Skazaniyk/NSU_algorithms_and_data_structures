#include <stdio.h>

#define N 1005

double bin_coef_array[N][N] = {0};

void binomial_coefficient(void) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (i == j) {
                bin_coef_array[i][j] = 1;
            } else {
                bin_coef_array[i][j] = bin_coef_array[i - 1][j - 1] + bin_coef_array[i - 1][j];
            }
        }
    }
}

int main() {
    int q, n, k;

    scanf("%d", &q);

    binomial_coefficient();

    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &n, &k);
        printf("%0.10g\n", bin_coef_array[n][k]);
    }

    return 0;
}