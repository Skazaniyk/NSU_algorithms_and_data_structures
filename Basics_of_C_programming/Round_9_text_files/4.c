#include <stdio.h>

int main(void) {
    int array[256] = {0};
    unsigned char symbol;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (scanf("%c", &symbol) == 1) {
        array[(int) symbol] += 1;
    }

    for (int i = 32; i <= 126; ++i) {
        if (array[i] > 0) {
            printf("%c ", i);
            for (int j = 0; j < array[i]; ++j) {
                printf("#");
            }
            printf("\n");
        }
    }

    return 0;
}