#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <minmax.h>

typedef struct list {
    int time;
    int money;
    int width;
} gan;

gan *create() {
    gan *G;
    G = (gan *) malloc(sizeof(gan));
    return G;
}

void swap(gan **b, gan **d) {
    gan *c = *b;
    *b = *d;
    *d = c;
}

void sort_gan(gan **G, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (G[i]->time > G[j]->time) {
                swap(&G[i], &G[j]);
            }
        }
    }
}

int max_summ(int const *p, int n) {
    int maxx_sum = 0;
    for (int i = 0; i < n; ++i) {
        if (maxx_sum < p[i]) {
            maxx_sum = p[i];
        }
    }
    return maxx_sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, k, t, tekythaya_max_summ;
    scanf("%d%d%d", &n, &k, &t);

    gan **ganster = (gan **) malloc(n * sizeof(gan *));
    int *maxxsumm = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        ganster[i] = create();
        maxxsumm[i] = 0;
        scanf("%d", &ganster[i]->time);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &ganster[i]->money);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &ganster[i]->width);
        if (ganster[i]->time < ganster[i]->width) {
            ganster[i]->money = 0;
        }
    }

    sort_gan(ganster, n);

    for (int i = 0; i < n; ++i) {
        tekythaya_max_summ = ganster[i]->money;
        for (int j = 0; j < i; ++j) {
            if (maxxsumm[j] != 0) {
                if ((ganster[i]->time - ganster[j]->time) >= (abs(ganster[i]->width - ganster[j]->width))) {
                    tekythaya_max_summ = max(tekythaya_max_summ, maxxsumm[j] + ganster[i]->money);
                }
            }
        }
        maxxsumm[i] = tekythaya_max_summ;
    }

    printf("%d", max_summ(maxxsumm, n));

    return 0;
}