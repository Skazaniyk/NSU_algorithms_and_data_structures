#include <stdio.h>

double abss(double x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

double exp(double x) {
    double eps = 0.0000000000000001, summ = 1, arg = 1;
    int n = 1;

    while (abss(arg) > eps) {
        arg *= x / n;
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
        if (x > 0) {
            printf("%0.15g", exp(x));
            printf("\n");
        } else {
            double a = 1 / exp(abss(x));
            printf("%0.15g", a);
            printf("\n");
        }
    }

    return 0;
}