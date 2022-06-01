#include <stdio.h>

void qsortRecursive(int *mas, int size) {
    int i = 0, j = size - 1, mid = mas[size / 2];

    do {
        while (mas[i] < mid) {
            i++;
        }
        while (mas[j] > mid) {
            j--;
        }

        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) {
        qsortRecursive(mas, j + 1);
    }
    if (i < size) {
        qsortRecursive(&mas[i], size - i);
    }
}

int main() {
    int n;
    int a[1000000];
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    qsortRecursive(a, n);

    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }

    return 0;
}