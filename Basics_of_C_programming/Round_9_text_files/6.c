#include <stdio.h>
#include <string.h>

#define N 1050

char strs[N][N];

int main() {
    int n = 0;
    char s[N] = {0};

    FILE *input, *output;
    output = fopen("output.txt", "w");
    input = fopen("input.txt", "r");

    while (fgets(strs[n], N, input) != NULL) {
        ++n;
    }

    for (int i = 0; i < n / 2; ++i) {
        strcpy(s, strs[i]);
        strcpy(strs[i], strs[n - i - 1]);
        strcpy(strs[n - i - 1], s);
    }

    for (int i = 0; i < n; ++i) {
        fprintf(output, "%s\n", strs[i]);
    }

    fclose(input);
    fclose(output);
    return 0;
}