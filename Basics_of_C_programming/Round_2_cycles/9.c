#include <stdio.h>
#include <math.h>

int main(void) {
    double eps, x, xi, sum = 0;
    int n = 1;
    scanf("%lf", &x);
    scanf("%lf", &eps);
    xi = x;
    while (xi >= eps) {
        if (n % 4 == 3) {
            sum -= xi;
        } else {
            sum += xi;
        }
        n += 2;
        xi = (xi * x * x * (n - 2)) / n;
    }
    if (n % 4 == 3) {
        sum -= xi;
    } else {
        sum += xi;
    }
    printf("%.5lf", sum);
    return 0;
}