#include <stdio.h>

int main() {
    int n, m, current_line, current_row, steps = 0, flag;
    char array[11][11], symbol;
    scanf("%d%d%d", &n, &m, &current_row);
    scanf("%c", &symbol);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%c", &array[i][j]);
        }
        scanf("%c", &symbol);
    }

    current_line = 0;
    --current_row;
    while (1) {
        flag = 1;
        if (array[current_line][current_row] == 'S') {
            flag = 0;
            if (current_line == n - 1) {
                printf("%d step(s) to exit", steps + 1);
                break;
            } else {
                array[current_line][current_row] = (char) steps;
                ++steps;
                ++current_line;
            }
        }
        if (array[current_line][current_row] == 'N') {
            flag = 0;
            if (current_line == 0) {
                printf("%d step(s) to exit", steps + 1);
                break;
            } else {
                array[current_line][current_row] = (char) steps;
                ++steps;
                --current_line;
            }
        }
        if (array[current_line][current_row] == 'E') {
            flag = 0;
            if (current_row == m - 1) {
                printf("%d step(s) to exit", steps + 1);
                break;
            } else {
                array[current_line][current_row] = (char) steps;
                ++steps;
                ++current_row;
            }
        }
        if (array[current_line][current_row] == 'W') {
            flag = 0;
            if (current_row == 0) {
                printf("%d step(s) to exit", steps + 1);
                break;
            } else {
                array[current_line][current_row] = (char) steps;
                ++steps;
                --current_row;
            }
        }
        if (flag) {
            printf("%d step(s) before a loop of %d step(s)", (int) array[current_line][current_row],
                   steps - (int) array[current_line][current_row]);
            break;
        }
    }

    return 0;
}