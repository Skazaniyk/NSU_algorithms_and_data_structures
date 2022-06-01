#include <stdio.h>
#include <math.h>

int main() {
    int n, f;

    scanf("%i", &n);

    for (int j = 2; j <= n; j++) {
        f = j;
        for (int i = 2; i * i <= f; i++) {
            if (f % i == 0) {
                f = 0;
                break;
            }
        }
        if (f != 0) {
            printf("%i ", f);
        }
    }
    return 0;
}