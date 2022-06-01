#include <stdio.h>

void select_sort(int *a, int n) {
    int min = a[0], min_index = 0;
    for (int i = 0; i < n; ++i) {

        for (int j = i; j < n; ++j) {
            if (a[j] < min) {
                min = a[j];
                min_index = j;
            }
        }

        int t = a[min_index];
        a[min_index] = a[i];
        a[i] = t;

        min = a[i + 1];
        min_index = i + 1;
    }
}

int main() {
    int n, a[100000];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    select_sort(a, n);

    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}