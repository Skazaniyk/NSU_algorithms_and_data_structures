#include <stdio.h>

int main() {
    char symbol;
    int star = 0;

    while (scanf("%c", &symbol) == 1) {
        if (symbol == '/') {
            star = 0;
            scanf("%c", &symbol);
            if (symbol == '/') {
                while (scanf("%c", &symbol) == 1 && symbol != '\n') {}
                printf("\n");
            } else if (symbol == '*') {
                while (scanf("%c", &symbol) == 1) {
                    if (symbol == '\n') {
                        star = 0;
                        printf("\n");
                    } else if (symbol == '*') {
                        star = 1;
                    } else if (symbol == '/' && star == 1) {
                        break;
                    } else {
                        star = 0;
                    }
                }
            } else {
                printf("/%c", symbol);
            }
        } else {
            printf("%c", symbol);
        }
    }

    return 0;
}