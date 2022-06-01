#include <stdio.h>
#include <math.h>

int main() {
    int n, f;

    scanf("%i", &n);

    if (n <= 1) {
        printf("NO");
    } else {
        f = 1;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                f = 0;
                break;
            }
        }

        if (f == 1) {
            printf("YES");
        } else {
            printf("NO");
        }
    }
    return 0;
}