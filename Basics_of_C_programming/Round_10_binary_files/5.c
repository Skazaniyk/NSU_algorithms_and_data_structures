#include <stdio.h>

int partition(int *a, int n, int pivot) {
    int min[1000050], max[1000050], e_p[1000050];
    int id_max = 0, id_min = 0, id_ep = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] > pivot) {
            max[id_max++] = a[i];
        }
        if (a[i] < pivot) {
            min[id_min++] = a[i];
        }
        if (a[i] == pivot) {
            e_p[id_ep++] = a[i];
        }
    }

    int id = 0;
    for (int i = 0; i < id_min; i++) {
        a[id++] = min[i];
    }
    for (int i = 0; i < id_ep; i++) {
        a[id++] = e_p[i];
    }
    for (int i = 0; i < id_max; i++) {
        a[id++] = max[i];
    }

    return id_min + id_ep / 2;
}

int main(void) {
    int Pivot, N;
    int a[1000050];

    FILE *in, *out;
    in = fopen("input.bin", "rb");
    out = fopen("output.bin", "wb");

    fread(&N, sizeof(int), 1, in);
    fread(&Pivot, sizeof(int), 1, in);

    for (int i = 0; i < N; ++i) {
        fread(&a[i], sizeof(int), 1, in);
    }

    int k = partition(a, N, Pivot);

    fwrite(&k, sizeof(int), 1, out);
    for (int i = 0; i < N; ++i) {
        fwrite(&a[i], sizeof(int), 1, out);
    }

    fclose(in);
    fclose(out);
    return 0;
}