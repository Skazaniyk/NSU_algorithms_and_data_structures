#include <stdio.h>
#include <math.h>

int main(void) {
    int n, left, right, search = -1, middle;
    double array[1000001], value;

    scanf("%d %lf", &n, &value);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &array[i]);
    }

    left = 0;
    right = n - 1;
    while (right - left > 1) {
        middle = (left + right) / 2;
        if (array[middle] == value) {
            search = middle;
            break;
        } else if (value < array[middle]) {
            right = middle;
        } else {
            left = middle;
        }
    }

    if (search != -1) {
        printf("%d", middle);
    } else if ((fabs(array[left] - value)) <= (fabs(array[right] - value))) {
        printf("%d", left);
    } else {
        printf("%d", right);
    }
}