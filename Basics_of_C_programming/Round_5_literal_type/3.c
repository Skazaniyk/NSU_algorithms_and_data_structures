#include <stdio.h>

void swap(char *cur, char *last_cur) {
    char t = *cur;
    *cur = *last_cur;
    *last_cur = t;
}

int main() {
    unsigned char cur, last_cur;

    scanf("%c%c", &cur, &last_cur);
    while (last_cur != '.') {
        printf("%c", cur);
        swap(&cur, &last_cur);
        scanf("%c", &last_cur);
    }

    if (cur != 'r' && cur != 'e') {
        printf("%c", cur);
        printf("er");
        return 0;
    }
    if (cur == 'r') {
        printf("st");
        return 0;
    }
    if (cur == 'e') {
        printf("er");
    }

    return 0;
}