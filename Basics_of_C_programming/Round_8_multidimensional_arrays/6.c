#include <stdio.h>

int main() {
    int n, code[260][260], id = 0;
    char word[260][260], symbol, str[100000] = {0};

    scanf("%d", &n);
    n *= 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &code[i][j]);
        }
    }
    scanf("%c", &symbol);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%c", &word[i][j]);
        }
        scanf("%c", &symbol);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (code[i][j] == 1) {
                if (word[i][j] == '0') {
                    printf("No");
                    return 0;
                } else {
                    str[id] = word[i][j];
                    word[i][j] = '0';
                    ++id;
                }
            }
        }
    }
    for (int j = 0; j < n; ++j) {
        for (int i = n - 1; i >= 0; --i) {
            if (code[i][j] == 1) {
                if (word[j][n - 1 - i] == '0') {
                    printf("No");
                    return 0;
                } else {
                    str[id] = word[j][n - 1 - i];
                    word[j][n - 1 - i] = '0';
                    ++id;
                }
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (code[i][j] == 1) {
                if (word[n - 1 - i][n - 1 - j] == '0') {
                    printf("No");
                    return 0;
                } else {
                    str[id] = word[n - 1 - i][n - 1 - j];
                    word[n - 1 - i][n - 1 - j] = '0';
                    ++id;
                }
            }
        }
    }
    for (int j = n - 1; j >= 0; --j) {
        for (int i = 0; i < n; ++i) {
            if (code[i][j] == 1) {
                if (word[n - 1 - j][i] == '0') {
                    printf("No");
                    return 0;
                } else {
                    str[id] = word[n - 1 - j][i];
                    word[n - 1 - j][i] = '0';
                    ++id;
                }
            }
        }
    }
    for (int i = 0; i < id; ++i) {
        printf("%c", str[i]);
    }

    return 0;
}
