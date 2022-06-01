#include <stdio.h>

int main() {
    unsigned char cur, count = 1;
    int flag = 0;

    scanf("%c", &cur);
    while (cur != '.') {
        if (cur == 'A' && count == 2) {
            flag = 1;
        }
        scanf("%c", &cur);
        ++count;
    }

    if (flag == 1 && count == 4) {
        printf("FITS");
    } else {
        printf("DOES NOT FIT");
    }
    return 0;
}