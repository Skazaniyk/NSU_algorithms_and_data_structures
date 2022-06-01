#include <stdio.h>
#include <math.h>

int main(void) {
    int n;
    float d, k;
    scanf("%i", &n);
    d = 8 * n - 7;
    k = (-1 + sqrt(d)) / 2;
    if (k - (int) k == 0) {
        printf("1");
    } else {
        printf("0");
    }
}