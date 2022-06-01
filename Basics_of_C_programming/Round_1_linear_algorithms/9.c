#include <stdio.h>
#include <math.h>

int main(void) {
    double n, m, p, k, l, podezd, etag, kvnaetag;
    scanf("%lf", &n);
    scanf("%lf%lf%lf%lf", &m, &p, &k, &l);
    kvnaetag = ceil(m / ((p - 1) * l + k));
    podezd = ceil((n / (l * kvnaetag)));
    etag = ceil((n - l * kvnaetag * (podezd - 1)) / kvnaetag);
    printf("%i %i ", (int) podezd, (int) etag);
    return 0;
}