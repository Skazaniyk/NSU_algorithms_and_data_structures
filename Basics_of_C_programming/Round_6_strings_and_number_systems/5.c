#include <stdio.h>
#include <string.h>

void reverse(char *start, int len) {
    for (int i = 0; i < len / 2; ++i) {
        char t = start[i];
        start[i] = start[len - i - 1];
        start[len - i - 1] = t;
    }
}

int main() {
    char string[100];
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%s", string);
        reverse(string, strlen(string));
        printf("%s\n", string);
    }

    return 0;
}