#include <stdio.h>

void swap(char *cur, char *last_cur) {
    char t = *cur;
    *cur = *last_cur;
    *last_cur = t;
}

int main() {
    unsigned char cur, last_cur;
    int summ = 0;

    scanf("%c%c", &cur, &last_cur);
    while (last_cur != '.') {
        summ += cur - '0';
        swap(&cur, &last_cur);
        scanf("%c", &last_cur);
    }
    summ += cur - '0';

    if ((summ % 3 == 0) && (cur == '0' || cur == '5')) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}