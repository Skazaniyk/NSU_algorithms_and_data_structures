#include <stdio.h>

int main(void) {
    int n = 0;
    char symbol;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (scanf("%c", &symbol) == 1) {
        if (symbol == '\n') {
            ++n;
        }
    }
    printf("%d", n);

    return 0;
}