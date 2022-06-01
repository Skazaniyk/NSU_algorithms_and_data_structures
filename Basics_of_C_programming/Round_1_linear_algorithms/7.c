#include <stdio.h>

int main(void) {
    int h1, m1, s1, k, h2, m2, s2, p, l;
    scanf("%i%i%i%i", &h1, &m1, &s1, &k);

    p = (s1 + k) / 60;
    s2 = (s1 + k) - 60 * p;

    l = (m1 + p) / 60;
    m2 = (m1 + p) - 60 * l;

    h2 = (h1 + l) % 24;

    if (s2 / 10 == 0) s2 = s2 % 10;
    if (m2 / 10 == 0) m2 = m2 % 10;
    if (h2 / 10 == 0) h2 = h2 % 10;

    printf("%i %i %i", h2, m2, s2);
}