#include <stdio.h>

int main() {
    unsigned char symbol_1, symbol_2;
    int count = 0;

    scanf("%c%c", &symbol_1, &symbol_2);
    if (symbol_1 != '.') {
        ++count;
    }
    while (symbol_2 != '\n') {
        if (symbol_1 == '.' && symbol_2 != '.') {
            ++count;
        }
        symbol_1 = symbol_2;
        scanf("%c", &symbol_2);
    }

    printf("%d", count);
    return 0;
}