#include <stdio.h>

int main(void) {
    unsigned int n, number = 0, flag;
    char symbol;
    scanf("%d", &n);
    scanf("%c", &symbol);
    for (int i = 0; i < n; ++i) {
        if ((i != 0) && (i % 8 == 0)) {
            printf("%d ", number);
            number = 0;
            flag = 1;
        }
        flag = 0;
        scanf("%c", &symbol);
        number += ((symbol - '0') * (1 << (i % 8)));
    }
    if (flag == 0) {
        printf("%d ", number);
    }
    return 0;
}
