#include <stdio.h>
#include <string.h>

int main() {
    char s[30] = {0}, s1[30] = {0}, abs[26] = {0};
    int flag;

    scanf("%s", s);
    int k = strlen(s);
    for (int i = 0; i < k; ++i) {
        abs[s[i] - 'a'] = 1;
    }

    while (scanf("%s", s1) == 1) {
        flag = 1;
        int l = strlen(s1);
        for (int i = 0; i < l; ++i) {
            if (abs[s1[i] - 'a'] == 1) {
                flag = 0;
                break;
            }
        }

        if (flag) {
            printf("%s\n", s1);
        }
    }

    return 0;
}