#include <stdio.h>

int main(void) {
    freopen("input.txt", "r", stdin);
    int n, array[100] = {0};
    scanf("%d", &n);
    array[0] = 0;
    array[1] = 2;
    array[2] = 3;
    for (int i = 3; i <= n; i++) {
        array[i] = array[i - 1] + array[i - 2];
    }
    printf("%d", array[n]);
    return 0;
}