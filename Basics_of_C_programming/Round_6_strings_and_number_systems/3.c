#include <stdio.h>
#include <string.h>

int main() {
    char s1[30], s2[30], s[30] = {0};

    scanf("%s", s1);
    scanf("%s", s2);

    int k_1 = strlen(s1);
    for (int i = 0; i < k_1; ++i) {
        s[s1[i] - 'A'] = 1;
    }

    int k_2 = strlen(s2);
    for (int i = 0; i < k_2; ++i) {
        s[s2[i] - 'A'] = 0;
    }

    int flag_2 = 0;
    for (int i = 0; i < 30; ++i) {
        if (s[i] == 1) {
            printf("%c", ('A' + i));
            flag_2 = 1;
        }
    }
    if (flag_2 == 0) {
        printf("Empty Set");
    }

    return 0;
}