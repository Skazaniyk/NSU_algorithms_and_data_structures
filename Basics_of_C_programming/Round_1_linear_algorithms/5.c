#include <stdio.h>
#include <math.h>

double len_vector(double x1, double x2, double y1, double y2) {
    double l;
    l = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    return l;
}

int main(void) {
    double x1, x2, x3, y1, y2, y3, l1, l2, l3, p, per, s;
    scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
    l1 = len_vector(x1, x2, y1, y2);
    l2 = len_vector(x2, x3, y2, y3);
    l3 = len_vector(x3, x1, y3, y1);
    per = l1 + l2 + l3;
    p = per / 2;
    s = sqrt(p * (p - l1) * (p - l2) * (p - l3));
    printf("%0.3lf \n", per);
    printf("%0.3lf", s);
}