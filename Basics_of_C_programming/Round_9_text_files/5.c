#include <stdio.h>

#define N 100000

void quicksort(int number[N], int first, int last) {
    int i, j, pivot, temp;

    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while (number[i] <= number[pivot] && i < last)
                i++;
            while (number[j] > number[pivot])
                j--;
            if (i < j) {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }

        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quicksort(number, first, j - 1);
        quicksort(number, j + 1, last);

    }
}

int main(void) {
    int array[N] = {0}, id = 0, shag;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (scanf("%d", &array[id]) == 1) {
        ++id;
    }

    quicksort(array, 0, id - 1);

    shag = array[1] - array[0];
    for (int i = 2; i < id; ++i) {
        if ((array[i] - array[i - 1]) != shag) {
            printf("NO");
            return 0;
        }
    }

    printf("%d", shag);
    return 0;
}