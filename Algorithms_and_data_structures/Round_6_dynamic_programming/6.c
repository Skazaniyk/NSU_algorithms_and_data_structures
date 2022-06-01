#include <stdio.h>
#include <stdlib.h>

#define llu long long int

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    llu *array_number = (llu *) malloc(sizeof(llu) * (n + 5));
    llu *array_len = (llu *) malloc(sizeof(llu) * (n + 5));
    llu *array_prev = (llu *) malloc(sizeof(llu) * (n + 5));

    for (int i = 0; i < n; i++) {
        scanf("%lld", &array_number[i]);
        array_len[i] = 0;
        array_prev[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        array_len[i] = 1;
        array_prev[i] = -1;
        for (int j = 0; j < n; j++) {
            if ((array_number[j] < array_number[i]) && (array_len[j] + 1 > array_len[i])) {
                array_len[i] = array_len[j] + 1;
                array_prev[i] = j;
            }
        }
    }

    llu last = 0, lenght = 0;
    for (int i = 0; i < n; i++) {
        if (array_len[i] > lenght) {
            last = i;
            lenght = array_len[i];
        }
    }

    llu count = last;
    int l = 0;
    llu *array_answer = (llu *) malloc(sizeof(llu) * (lenght + 5));
    llu *array_answer_index = (llu *) malloc(sizeof(llu) * (lenght + 5));
    while (count != -1) {
        array_answer[l] = array_number[count];
        array_answer_index[l] = count;
        count = array_prev[count];
        l++;
    }

    printf("%d\n", l);
    for (int i = l - 1; i >= 0; i--) {
        printf("A[%lld] = %lld\n", array_answer_index[i] + 1, array_answer[i]);
    }
    return 0;
}
