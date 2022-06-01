#include <stdio.h>
#include <math.h>

int main(void) {
    int n, id = 1;
    double k, zazor1, zazor2, zazor, min_zazor = 1000;
    scanf("%i", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%lf", &k);
        zazor1 = ceil(k) - k;
        zazor2 = k - floor(k);
        if (zazor2 > zazor1) {
            zazor = zazor1;
        } else {
            zazor = zazor2;
        }
        if (zazor < min_zazor) {
            id = i;
            min_zazor = zazor;
        }
    }

    printf("%i", id);
    return 0;
}