#include <stdio.h>

int main() {
    int n, sum = 0, a;
    scanf("%i", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%i", &a);
        if (a % 2 == 0) {
            sum += a;
        }
    }

    printf("%i", sum);

    return 0;
}