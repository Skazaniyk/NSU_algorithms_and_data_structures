#include <stdio.h>
#include <string.h>

int main(void) {
    int array[100] = {0};
    char str[100];

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (scanf("%s", str) == 1) {
        array[strlen(str)] += 1;
    }

    for (int i = 0; i < 100; ++i) {
        if (array[i] > 0) {
            printf("%d - %d\n", i, array[i]);
        }
    }

    return 0;
}