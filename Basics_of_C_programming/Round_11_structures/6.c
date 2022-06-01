#include <stdio.h>

struct list {
    double number;
    int index;
} array[100050];

int main() {
    int n, id;

    scanf("%d%d", &n, &id);
    for (int i = 0; i < n; ++i) {
        scanf("%lf%d", &array[i].number, &array[i].index);
    }

    while (array[id].index != -1) {
        printf("%0.3lf ", array[id].number);
        id = array[id].index;
        printf("\n");
    }
    printf("%0.3lf ", array[id].number);

    return 0;
}