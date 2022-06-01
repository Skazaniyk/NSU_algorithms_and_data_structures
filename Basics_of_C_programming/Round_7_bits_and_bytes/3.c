#include <stdio.h>

int main(void) {
    unsigned int n, new_n = 0, save_n = 0, n_2 = 0;
    scanf("%d", &n);
    save_n = n;
    for (int i = 0; i < 32; ++i) {
        new_n = (new_n << 1) | (n & 1);
        n >>= 1;
    }
    n_2 = new_n;
    for (int i = 0; i < 32; ++i) {
        printf("%d", (n_2 & 1));
        n_2 >>= 1;
    }
    printf("\n%d\n", new_n);
    for (int i = 0; i < 32; ++i) {
        printf("%d", (save_n & 1));
        save_n >>= 1;
    }
    return 0;
}