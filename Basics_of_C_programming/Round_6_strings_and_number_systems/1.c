#include <stdio.h>
#include <string.h>

int main() {
    char string[30], current_letter = 'a';
    int winner = 2, n, flag_1, flag_2 = 0;

    while (scanf("%s", string) == 1) {
        flag_1 = 0;
        n = strlen(string);
        for (int i = 0; i < n; ++i) {
            if (string[i] == current_letter) {
                flag_1 = 1;
                break;
            }
        }
        if (flag_1 == 0) {
            flag_2 = 1;
            break;
        }

        winner = (winner + 1) % 2;
        ++current_letter;
    }

    if (flag_2 == 0) {
        printf("NO WINNER");
    } else {
        if (winner == 0) {
            winner = 2;
        }
        printf("PLAYER %d", winner);
    }
    return 0;
}