#include <stdio.h>

int main(void) {
    unsigned int number;
    int n, count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &number);
        while (number > 0) {
            if ((number & 1) == 1) {
                printf("%d\n", 1 << count);
                break;
            }
            number >>= 1;
            ++count;
        }
        count = 0;
    }

    return 0;
}