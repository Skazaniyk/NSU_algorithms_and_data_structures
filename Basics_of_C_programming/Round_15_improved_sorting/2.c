#include <stdio.h>

void shell_sort(int *array, int size) {
    for (int s = size / 2; s > 0; s /= 2) {
        for (int i = s; i < size; ++i) {
            for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s) {
                int temp = array[j];
                array[j] = array[j + s];
                array[j + s] = temp;
            }
        }
    }
}

int main() {
    int n;
    int a[1000000];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    shell_sort(a, n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}