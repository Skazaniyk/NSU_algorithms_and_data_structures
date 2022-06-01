#include <stdio.h>

double abss(double x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

double sin(double x) {
    double eps = 0.000000000000001, summ = x, arg = x;
    long long int n = 0;

    while (abss(arg) > eps) {
        arg = (arg * (-x * x)) / ((2 * n + 3) * (2 * n + 2));
        summ += arg;
        ++n;
    }

    return summ;
}

int main(void) {
    int n;
    double x;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &x);
        printf("%0.15lf", sin(x));
        printf("\n");
    }

    return 0;
}