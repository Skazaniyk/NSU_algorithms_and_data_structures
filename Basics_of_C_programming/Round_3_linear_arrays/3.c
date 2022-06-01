#include <stdio.h>

int main() {
    int n, a, array[100500] = {0};
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        ++array[a];
    }

    for (int i = 1; i <= 100001; ++i) {
        if (array[i] != 0) {
            printf("%d: %d \n", i, array[i]);
        }
    }

    return 0;
}