#include <stdio.h>
#include <math.h>

int main() {
    int a, b;
    long long summ;

    FILE *in, *out;
    in = fopen("input.bin", "rb");
    out = fopen("output.bin", "wb");

    fread(&a, sizeof(int), 1, in);
    fread(&b, sizeof(int), 1, in);
    summ = floor((double)((long long)a + b)/2);
    int result = (int) summ;

    fwrite(&result, sizeof(int), 1, out);
    return 0;
}