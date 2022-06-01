#include <stdio.h>

int main() {
    unsigned char symbol;
    int sum = 0, ans = 0;

    scanf("%c", &symbol);
    while (symbol != '.') {
        if ('0' <= symbol && symbol <= '9') {
            sum = 10 * sum + (symbol - '0');
        } else {
            ans += sum;
            sum = 0;
        }
        scanf("%c", &symbol);
    }
    ans += sum;

    printf("%d ", ans);
    return 0;
}