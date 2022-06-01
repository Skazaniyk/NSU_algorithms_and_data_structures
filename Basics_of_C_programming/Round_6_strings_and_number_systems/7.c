#include <stdio.h>
#include <string.h>

int answer[10000000];

int main() {
    int n, b, count = 0, a;
    scanf("%d", &b);
    scanf("%d", &n);

    if (n == 0) {
        printf("0");
        return 0;
    }

    while (n > 0) {
        a = n % b;

        if (0 <= a && a <= 9) {
            answer[count] = '0' + a;
        } else {
            answer[count] = 'a' + a - 10;
        }
        ++count;

        n /= b;
    }

    for (int i = count - 1; i >= 0; --i) {
        printf("%c", answer[i]);
    }
    return 0;
}