#include <stdio.h>

void quick_sort(int *arr, int size) {
    int left = 0, right = size - 1, mid = arr[size / 2], tmp;
    do {
        while (arr[left] < mid)
            left++;
        while (arr[right] > mid)
            right--;
        if (left <= right) {
            tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            left++;
            right--;
        }
    } while (left <= right);
    if (right > 0)
        quick_sort(arr, right + 1);
    if (left < size)
        quick_sort(&arr[left], size - left);
}

int arr[500005];

int main() {
    FILE *input = fopen("input.bin", "rb"), *output = fopen("output.bin", "wb");
    int n;
    fread(&n, 4, 1, input);
    fread(arr, 4, n, input);

    quick_sort(arr, n);

    fwrite(arr, 4, n, output);
}