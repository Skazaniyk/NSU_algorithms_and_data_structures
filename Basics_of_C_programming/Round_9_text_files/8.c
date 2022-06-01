#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXIM_ID 1001

int identification[MAXIM_ID][2] = {0};

void print_splitters(int n_1, int n_2, int n_3) {
    printf("+");
    int m[3] = {n_1, n_2, n_3};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < m[i]; ++j) {
            printf("-");
        }
        printf("+");
    }
    printf("\n");
}


void print_blank(int n) {
    for (int i = 0; i < n; ++i) {
        printf(" ");
    }
}

int int_len(int n) {
    return (int) (log10(n)) + 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int num_users, id, clip_len;
    scanf("%d", &num_users);

    int max_len_1 = 0, max_len_2 = 0, max_len_3 = 0, cur_len_1, cur_len_2, cur_len_3;
    for (int i = 0; i < num_users; ++i) {
        scanf("%d%d", &id, &clip_len);
        identification[id][0] += 1;
        identification[id][1] += clip_len;

        cur_len_1 = int_len(id);
        cur_len_2 = int_len(identification[id][0]);
        cur_len_3 = int_len(identification[id][1]);

        max_len_1 = (cur_len_1 > max_len_1) ? cur_len_1 : max_len_1;
        max_len_2 = (cur_len_2 > max_len_2) ? cur_len_2 : max_len_2;
        max_len_3 = (cur_len_3 > max_len_3) ? cur_len_3 : max_len_3;
    }

    int max_lens[3] = {max_len_1, max_len_2, max_len_3}, blank;
    for (id = 0; id < MAXIM_ID; ++id) {
        if (identification[id][0] > 0) {
            print_splitters(max_len_1 + 2, max_len_2 + 2, max_len_3 + 2);
            for (int j = 0; j < 3; ++j) {
                printf("| ");
                if (j == 0) {
                    blank = max_len_1 - int_len(id);
                    print_blank(blank);
                    printf("%d ", id);
                    continue;
                }
                blank = max_lens[j] - int_len(identification[id][j - 1]);
                print_blank(blank);
                printf("%d ", identification[id][j - 1]);
            }
            printf("|\n");
        }
    }

    print_splitters(max_len_1 + 2, max_len_2 + 2, max_len_3 + 2);
    return 0;
}