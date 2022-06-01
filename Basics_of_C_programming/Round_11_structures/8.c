#include <stdio.h>

typedef struct LongNum_s {
    int len; //сколько цифр в числе
    int arr[500]; //массив десятичных цифр числа
} LongNum;


int main() {
    int n, mod, div;
    LongNum number_1, number_2;
    scanf("%d", &n);

    for (int i = 0; i < 500; ++i) {
        number_1.arr[i] = 0;
        number_2.arr[i] = 0;
    }

    number_1.len = 1;
    number_1.arr[0] = 1;
    --n;
    number_2.len = 0;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < 500; ++j) {
                if (number_1.arr[j] + number_2.arr[j] > 9) {
                    mod = (number_1.arr[j] + number_2.arr[j]) % 10;
                    div = (number_1.arr[j] + number_2.arr[j]) / 10;
                    number_2.arr[j] = mod;
                    number_2.arr[j + 1] += div;
                } else {
                    number_2.arr[j] = number_2.arr[j] + number_1.arr[j];
                }

                if ((number_2.arr[j] == 0) && (j >= number_2.len)) {
                    number_2.len = j;
                    break;
                }
            }
        } else {
            for (int j = 0; j < 500; ++j) {
                if (number_1.arr[j] + number_2.arr[j] > 9) {
                    mod = (number_1.arr[j] + number_2.arr[j]) % 10;
                    div = (number_1.arr[j] + number_2.arr[j]) / 10;
                    number_1.arr[j] = mod;
                    number_1.arr[j + 1] += div;
                } else {
                    number_1.arr[j] = number_2.arr[j] + number_1.arr[j];
                }

                if ((number_1.arr[j] == 0) && (j >= number_1.len)) {
                    number_1.len = j;
                    break;
                }
            }
        }
    }

    if ((n - 1) % 2 == 0) {
        for (int i = number_2.len - 1; i >= 0; --i) {
            printf("%d", number_2.arr[i]);
        }
    } else {
        for (int i = number_1.len - 1; i >= 0; --i) {
            printf("%d", number_1.arr[i]);
        }
    }

    return 0;
}