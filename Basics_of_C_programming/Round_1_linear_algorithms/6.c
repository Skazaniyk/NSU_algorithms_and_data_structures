#include <stdio.h>

int main(void) {
    int x, y, z, s;
    scanf("%i%i%i", &x, &y, &z);

    if ((x <= 0) || (y <= 0) || (z <= 0)) {
        if (x <= 0)
            printf("-1");
        else {
            if (y <= 0)
                printf("-2");
            else {
                if (z <= 0)
                    printf("-3");
            }
        }
    } else {
        s = 2 * (x * y + y * z + z * x);
        printf("%i", s);
    }

    return 0;
}