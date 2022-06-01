#include <stdio.h>
#include <string.h>

char number[10000000];

int main() {
    int b, answer = 0;
    scanf("%d", &b);
    scanf("%s", number);

    for (int j = 0; j < strlen(number); ++j) {
        if ('0' <= number[j] && number[j] <= '9') {
            answer = answer * b + (number[j] - '0');
        } else {
            answer = answer * b + (number[j] - 'a') + 10;
        }
    }
    printf("%d", answer);

    return 0;
}