#include <stdio.h>
#include <math.h>

double abss(double x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

int main(void) {
    int n;
    double a_x, a_y, b_x, b_y, c_x, c_y;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf%lf%lf%lf%lf%lf", &a_x, &a_y, &b_x, &b_y, &c_x, &c_y);
        double x_1 = b_x - a_x, x_2 = c_x - a_x, y_1 = b_y - a_y, y_2 = c_y - a_y;
        double angle = abss(atan2(x_1 * y_2 - y_1 * x_2, x_1 * x_2 + y_1 * y_2));
        printf("%0.20g\n", (angle * 180) / M_PI);
    }

    return 0;
}