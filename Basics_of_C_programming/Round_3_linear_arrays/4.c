#include <stdio.h>

int main() {
    int n, a, array[1000500] = {0}, ans = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        array[a + 1000] = 1;
    }

    for (int i = 0; i <= 1000000; ++i) {
        if (array[i] == 1) {
            ++ans;
        }
    }

    printf("%d", ans);

    return 0;
}