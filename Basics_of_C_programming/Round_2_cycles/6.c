#include <stdio.h>
#include <math.h>

int main() {
    int n, k, minus = 0, plus = 0, zero = 0;
    double minus_ans, plus_ans, zero_ans;
    scanf("%i", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%i", &k);
        if (k > 0) {
            plus++;
        } else {
            if (k < 0) {
                minus++;
            } else {
                zero++;
            }
        }
    }

    minus_ans = (double) minus / n;
    plus_ans = (double) plus / n;
    zero_ans = (double) zero / n;

    printf("%.5f %.5f %.5f", minus_ans, zero_ans, plus_ans);
    return 0;
}