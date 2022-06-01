#include <stdio.h>

int merge(const int *a, int ak, const int *b, int bk, int *res) {
    int id_a = 0, id_b = 0, rk = ak + bk;

    for (int i = 0; i < rk; ++i) {
        if ((id_a < ak) && (id_b < bk)) {
            if (a[id_a] > b[id_b]) {
                res[i] = b[id_b];
                ++id_b;
            } else {
                res[i] = a[id_a];
                ++id_a;
            }
        } else break;
    }

    if (id_a == ak) {
        for (int j = id_b; j < bk; ++j) {
            res[ak + j] = b[j];
        }
    }
    if (id_b == bk) {
        for (int j = id_a; j < ak; ++j) {
            res[bk + j] = a[j];
        }
    }

    return rk;
}

int main(void) {
    int M, N, res[2 * 1000050], a[1000050], b[1000050];

    FILE *in, *out;
    in = fopen("input.bin", "rb");
    out = fopen("output.bin", "wb");
    fread(&N, sizeof(int), 1, in);
    fread(&M, sizeof(int), 1, in);

    for (int i = 0; i < N; ++i) {
        fread(&a[i], sizeof(int), 1, in);
    }
    for (int j = 0; j < M; ++j) {
        fread(&b[j], sizeof(int), 1, in);
    }

    int rk = merge(a, N, b, M, res);

    for (int i = 0; i < rk; ++i) {
        fwrite(&res[i], sizeof(int), 1, out);
    }

    fclose(in);
    fclose(out);
    return 0;
}