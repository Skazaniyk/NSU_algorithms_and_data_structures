#include <stdio.h>
#include <math.h>

int main(void) {
    int x1, x2, x3, x4;
    float a, b, r;
    scanf("%f%f", &a, &b);

    r = a / b;
    x2 = ceil(r);
    x1 = floor(r);

    if (a > 0) {
        x3 = x1;
        x4 = (int) a - (int) b * x3;
    } else {
        x3 = x2;
        x4 = (int) a - (int) b * x1;
    }

    printf("%i %i %i %i", x1, x2, x3, x4);
}