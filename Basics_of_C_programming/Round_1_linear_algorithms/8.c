#include <stdio.h>
#include <math.h>

int main(void) {
    double a, b, c, x1, x2, d;
    scanf("%lf%lf%lf", &a, &b, &c);
    if ((a == 0) && (b == 0)) {
        if (c == 0) {
            printf("MANY");
        } else {
            printf("ERROR");
        }
    } else {
        if (a == 0) {
            x1 = -c / b;
            printf("1 \n");
            printf("%0.5lf", x1);
        } else {
            d = pow(b, 2) - 4 * a * c;
            if (d < 0) {
                printf("NO");
            }
            if (d == 0) {
                x1 = -b / (2 * a);
                printf("1 \n");
                printf("%0.5lf", x1);
            }
            if (d > 0) {
                x1 = (-b + sqrt(d)) / (2 * a);
                x2 = (-b - sqrt(d)) / (2 * a);
                printf("2 \n");
                if (x1 > x2) {
                    printf("%0.5lf %0.5lf", x2, x1);
                } else {
                    printf("%0.5lf %0.5lf", x1, x2);
                }
            }
        }
    }
}