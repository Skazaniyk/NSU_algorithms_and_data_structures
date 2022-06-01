#include <stdio.h>

int main(void) {
    int array[256] = {0};
    unsigned char symbol;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (scanf("%c", &symbol) == 1) {
        array[(int) symbol] += 1;
    }

    for (int i = 12; i < 256; ++i) {
        if (array[i] > 0) {
            printf("%d : %c - %d\n", i, i, array[i]);
        }
    }

    return 0;
}