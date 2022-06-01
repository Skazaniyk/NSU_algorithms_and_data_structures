#include <stdio.h>

unsigned int reverse(unsigned int a) {
    unsigned int b = a;
    unsigned int *p = &b;
    char *c = (char *) p, temp;
    for (int i = 0; i < 2; ++i) {
        temp = c[i];
        c[i] = c[4 - i - 1];
        c[4 - i - 1] = temp;
    }
    return b;
}

int main() {
    int n, r_n, a, summ = 0, b, answer;

    FILE *in, *out;
    in = fopen("input.bin", "rb");
    out = fopen("output.bin", "wb");

    fread(&n, sizeof(int), 1, in);
    if (n > 10000) {
        r_n = reverse(n);
        for (int i = 0; i < r_n; ++i) {
            fread(&a, sizeof(int), 1, in);
            b = reverse(a);
            summ += b;
        }
        answer = reverse(summ);
    } else {
        for (int i = 0; i < n; ++i) {
            fread(&a, sizeof(int), 1, in);
            summ += a;
        }
        answer = summ;
    }

    fwrite(&answer, sizeof(int), 1, out);
    return 0;
}