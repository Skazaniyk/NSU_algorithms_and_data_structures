#include <stdio.h>

typedef unsigned int bitword;
#define word_size (sizeof(bitword) * 8)

void bitsetSet(bitword *arr, int idx, int nexval) {
    int word_id = idx / word_size, bit_id = idx % word_size;
    if (nexval == 1) {
        arr[word_id] |= (1 << bit_id);
    } else {
        arr[word_id] &= ~(1 << bit_id);
    }
}

int main(void) {
    bitword *arr[1000] = {0};
    int newval, idx, n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &newval, &idx);
        bitsetSet(arr, ((31 - (idx % 32)) + (idx - idx % 32)), newval);
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}