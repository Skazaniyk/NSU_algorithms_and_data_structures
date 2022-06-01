#include <stdio.h>
#include <malloc.h>

int proverka_kandidata(int n, int m, char **array, int index, int i) {
    for (int j = index - 1; j >= 0; j--) {
        if (array[j][i] == 'X') {
            return 0;
        }
    }
    int x = i - 1, y = index - 1;
    while (x >= 0 && y >= 0) {
        if (array[y][x] == 'X') {
            return 0;
        }
        y--;
        x--;
    }
    x = i + 1, y = index - 1;
    while (x < n && y < m && x >= 0 && y >= 0) {
        if (array[y][x] == 'X') {
            return 0;
        }
        y--;
        x++;
    }
    return 1;
}

int try(int n, int m, char **array, int index) {
    for (int i = 0; i < n; ++i) {
        if (array[index][i] == '?') {
            if (proverka_kandidata(n, m, array, index, i)) {
                array[index][i] = 'X';
                if (index < m - 1) {
                    if (try(n, m, array, index + 1) == 0) {
                        array[index][i] = '?';
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(void) {
    freopen("input.txt", "r", stdin);
    int m, n;
    char symbol;
    scanf("%d%d%c", &m, &n, &symbol);
    char **field = (char **) malloc(sizeof(char *) * (m + 2));
    for (int i = 0; i < m; ++i) {
        field[i] = (char *) malloc(sizeof(char) * (n + 2));
        for (int j = 0; j < n; ++j) {
            scanf("%c", &field[i][j]);
        }
        scanf("%c", &symbol);
    }

    if (try(n, m, field, 0) == 1) {
        printf("YES\n");
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (field[i][j] == '?') {
                    field[i][j] = '.';
                }
                printf("%c", field[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("NO");
    }

    return 0;
}