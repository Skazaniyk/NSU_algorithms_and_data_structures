#include <stdio.h>

#define llu unsigned long long

llu dp[1001][1001];

llu get_num(llu num) {
    return num % 1000000007;
}

int main() {
    freopen("input.txt", "r", stdin);
    llu n;
    scanf("%llu", &n);
    for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }
    dp[0][0] = 1;

    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j <= i) {
                dp[i][j] = get_num(dp[i][j - 1] + dp[i - j][j]);
            } else {
                dp[i][j] = dp[i][i];
            }
        }
    }

    printf("%llu", dp[n][n]);
    return 0;
}
