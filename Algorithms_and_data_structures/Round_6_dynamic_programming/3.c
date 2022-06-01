#include <stdio.h>
#include <stdlib.h>

typedef struct info {
    int weight;
    int price;
} info;

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, w;
    scanf("%d%d", &n, &w);
    int **dp = (int **) malloc(sizeof(int *) * (n + 5));
    info *array = (info *) malloc(sizeof(info) * (n + 5));
    for (int i = 0; i <= n; i++) {
        scanf("%d%d", &array[i + 1].weight, &array[i + 1].price);
        dp[i] = malloc(sizeof(int) * (w + 5));
        dp[i][0] = 0;
    }
    for (int i = 0; i <= w; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (j < array[i].weight) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - array[i].weight] + array[i].price);
            }
        }
    }

    int i = n, j = w, sum = dp[n][w], count = 0, summ_weight = 0;
    int *array_answer = (int *) malloc(sizeof(int) * (n + 2));
    while (dp[i][j] != 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            array_answer[count++] = i;
            summ_weight += array[i].weight;
            j -= array[i].weight;
        }
        i--;
    }

    printf("%d %d %d\n", count, summ_weight, sum);
    for (int i = count - 1; i >= 0; i--) {
        printf("%d ", array_answer[i]);
    }


    return 0;
}
