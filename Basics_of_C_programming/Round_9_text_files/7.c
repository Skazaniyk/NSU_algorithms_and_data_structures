#include <stdio.h>

#define MAX 3000002

char all_symbols[MAX];
int all_position[MAX] = {0};

int main() {

    int current_id = 0, current_line = 1, left_edge, right_edge, flag;
    all_position[0] = -1;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (scanf("%c", &all_symbols[current_id]) == 1) {
        if (all_symbols[current_id] == '\n') {
            all_position[current_line] = current_id;
            ++current_line;
        }
        ++current_id;
    }

    for (int left = current_line - 1; left >= 0; --left) {
        flag = 0;
        left_edge = all_position[left];
        right_edge = all_position[left + 1];
        for (int i = left_edge + 1; i < right_edge; ++i) {
            printf("%c", all_symbols[i]);
            flag = 1;
        }
        if (flag) {
            printf("\n");
        }
    }

    return 0;
}