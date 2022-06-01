#include <stdio.h>
#include <malloc.h>

typedef unsigned int bitword;

#define word_size (sizeof(bitword) * 8)
#define max_size 2000000000/word_size

void bitsetZero(bitword *arr, int num) {
    for (int i = 0; i < (num + word_size) / word_size; ++i) {
        arr[i] = 0;
    }
}

int bitsetGet(const bitword *arr, int idx) {
    int word_id = idx / word_size;
    bitword value = arr[word_id];
    value >>= (idx % word_size);
    return (value & 1);
}

void bitsetSet(bitword *arr, int idx, int nexval) {
    int word_id = idx / word_size, bit_id = idx % word_size;
    if (nexval == 1) {
        arr[word_id] |= (1 << bit_id);
    } else {
        arr[word_id] &= ~(1 << bit_id);
    }
}

int bitsetAny(const bitword *arr, int left, int right) {
    int word_left_id = left / word_size, bit_left_id = left % word_size;
    int word_right_id = right / word_size, bit_right_id = right % word_size;
    bitword value, mask;
    for (int i = word_left_id; i <= word_right_id; ++i) {
        value = arr[i];
        if (i == word_left_id) {
            mask = (~0);
            mask <<= bit_left_id;
            value &= mask;
        }
        if (i == word_right_id) {
            mask = (~0);
            if (bit_right_id > 0) {
                mask >>= (word_size - bit_right_id);
            } else {
                mask = 0;
            }
            value &= mask;
        }
        if (value != 0) {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int size = (max_size + word_size) / word_size;
    bitword *arr = (bitword *) malloc(size);
    int right, left, newval, nummber, idx, command, n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &command);
        if (command == 0) {
            scanf("%d", &nummber);
            bitsetZero(arr, nummber);
            continue;
        }
        if (command == 1) {
            scanf("%d", &idx);
            printf("%d\n", bitsetGet(arr, idx));
            continue;
        }
        if (command == 2) {
            scanf("%d%d", &idx, &newval);
            bitsetSet(arr, idx, newval);
            continue;
        }
        if (command == 3) {
            scanf("%d%d", &left, &right);
            if (bitsetAny(arr, left, right)) {
                printf("some\n");
            } else {
                printf("none\n");
            }
            continue;
        }
    }

    return 0;
}