#include <stdio.h>

int main(void) {
    unsigned int number, max = 0, cnt = 0;
    scanf("%d", &number);
    while (number != 0) {
        if ((number & 1) == 1) {
            ++cnt;
            if (cnt > max) {
                max = cnt;
            }
        } else {
            cnt = 0;
        }
        number >>= 1;
    }
    printf("%d", max);
    return 0;
}