#include <stdio.h>
#include <stdlib.h>

typedef struct string_s {
    char *string;
    signed long value;
    signed long len;
} string;

typedef string *Strings;

int main() {
    freopen("input.txt", "r", stdin);
    int n, type_operation, r = 0, size, id, cnt;
    char c;
    scanf("%d", &n);
    Strings list = (Strings) malloc(sizeof(string) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d ", &type_operation);

        switch (type_operation) {
            case 0:

                scanf("%d", &size);
                list[r].string = (char *) malloc(sizeof(char) * (size + 1));
                scanf("%s", list[r].string);
                list[r].value = r;
                list[r].len = size;
                ++r;
                break;

            case 1:

                scanf("%d", &id);
                free(list[id].string);
                list[r].value = -1;
                break;

            case 2:

                scanf("%d", &id);
                printf("%s\n", list[id].string);
                break;

            case 3:

                scanf("%d %c", &id, &c);
                cnt = 0;
                for (int m = 0; m < list[id].len; m++) {
                    cnt += (c == list[id].string[m]);
                }
                printf("%d\n", cnt);
                break;
        }
    }

    for (int i = 0; i < r; ++i) {
        if (list[r].value != -1) {
            free(list[i].string);
        }
    }
    return 0;
}