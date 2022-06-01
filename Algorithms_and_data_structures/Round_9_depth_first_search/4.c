#include <stdio.h>
#include <stdlib.h>

void DFS(char **array, int index_1, int index_2, int max_size) {
    if (array[index_1][index_2] == ' ') {
        array[index_1][index_2] = '*';
        if (index_1 < max_size) {
            DFS(array, index_1 + 1, index_2, max_size);
        }
        if (index_1 > 1) {
            DFS(array, index_1 - 1, index_2, max_size);
        }
        if (index_2 < max_size) {
            DFS(array, index_1, index_2 + 1, max_size);
        }
        if (index_2 > 1) {
            DFS(array, index_1, index_2 - 1, max_size);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    char symbol;
    scanf("%d", &n);
    char **array = malloc(sizeof(char *) * (n + 5));

    scanf("%c", &symbol);
    for (int i = 1; i <= n; i++) {
        array[i] = malloc(sizeof(char) * (n + 5));
        for (int j = 1; j <= n; j++) {
            scanf("%c", &symbol);
            array[i][j] = symbol;
        }
        scanf("%c", &symbol);
    }

    for (int i = 1; i <= n; i++) {
        if (array[1][i] == ' ') {
            DFS(array, 1, i, n);
            break;
        }
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (array[i][j] == ' ') {
                DFS(array, i, j, n);
                count++;
            }
        }
    }

    printf("%d", count);

    return 0;
}
