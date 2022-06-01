#include <stdio.h>
#include <stdlib.h>

int modul(int number, int mod) {
    if (number < 0 && number % mod != 0) {
        return (number % mod) + mod;
    } else {
        return number % mod;
    }
}

void initialized(int *array_1, int *array_2, int size) {
    for (int i = 0; i < size; i++) {
        array_1[i] = 0;
        array_2[i] = 0;
    }
}

void function(int *array_1, int *array_2, int number, int k) {
    int mod = modul(number, k);

    for (int i = 0; i < k; i++) {
        if (array_2[i] == 1) {
            array_1[modul(i + mod, k)] = 1;
            array_1[modul(i - mod, k)] = 1;
            array_2[i] = 0;
        }
    }
}

int proverka(int const *array_1, int const *array_2, int n) {
    if ((n - 1) % 2 == 0) {
        if (array_1[0] == 1) {
            return 1;
        }
        return 0;
    } else {
        if (array_2[0] == 1) {
            return 1;
        }
        return 0;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, k, number;
    scanf("%d%d", &n, &k);
    int *array_1 = malloc(sizeof(int) * (k + 2));
    int *array_2 = malloc(sizeof(int) * (k + 2));
    initialized(array_1, array_2, k + 1);

    scanf("%d", &number);
    array_1[modul(number, k)] = 1;

    for (int i = 1; i < n; i++) {
        scanf("%d", &number);
        if (i % 2 == 0) {
            function(array_1, array_2, number, k);
        } else {
            function(array_2, array_1, number, k);
        }
    }

    if (proverka(array_1, array_2, n)) {
        printf("Divisible");
    } else {
        printf("Not divisible");
    }
    return 0;
}