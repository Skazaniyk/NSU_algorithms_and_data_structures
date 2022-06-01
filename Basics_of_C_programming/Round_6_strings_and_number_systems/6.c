#include <stdio.h>
#include <string.h>

char *concat(char *pref, char *suff) {
    int len_1 = strlen(pref), len_2 = strlen(suff);
    for (int i = len_1; i < len_1 + len_2; ++i) {
        pref[i] = suff[i - len_1];
    }
    return pref + len_1 + len_2;
}

int main() {
    char string[101] = {0}, string_array[1000001] = {0};
    int n;

    scanf("%d", &n);

    char *string_2 = string_array;
    for (int i = 0; i < n; ++i) {
        scanf("%s", string);
        string_2 = concat(string_2, string);
    }

    printf("%s", string_array);
    return 0;
}