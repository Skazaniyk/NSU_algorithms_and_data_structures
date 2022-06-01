#include <stdio.h>
#include "malloc.h"
#include "string.h"

int main(void) {
    freopen("input.txt", "r", stdin);
    int len, key;
    char symbol, str[10];
    scanf("%d", &len);

    char ***array = (char ***) malloc(1000001 * sizeof(char **));
    int *array_index = (int *) malloc(1000001 * sizeof(int));
    for (int i = 0; i < 1000001; ++i) {
        array_index[i] = 0;
    }

    for (int i = 0; i < len; ++i) {
        scanf("%d", &key);
        scanf("%c", &symbol);
        scanf("%s", str);

        if (array_index[key] == 0) {
            array[key] = (char **) malloc(sizeof(char *));
        }

        array[key] = realloc(array[key], (array_index[key] + 1) * 10 * sizeof(char *));
        array[key][array_index[key]] = (char *) malloc(10 * sizeof(char));
        strcpy(array[key][array_index[key]++], str);
    }

    for (int i = 0; i < 1000001; ++i) {
        if (array_index[i] != 0) {
            for (int j = 0; j < array_index[i]; ++j) {
                printf("%d %s\n", i, array[i][j]);
            }
        }
        free(array[i]);
    }
    free(array);

    return 0;
}


