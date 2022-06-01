#include <stdio.h>
#include <malloc.h>


typedef struct heap {
    int size;
    int position;
    int *arr;
} heap;

heap *create() {
    heap *arr;
    arr = (heap *) malloc(sizeof(heap));
    arr->position = 0;
    arr->size = 1;
    arr->arr = (int *) malloc(sizeof(int) * arr->size);
    return arr;
}

int left(int i) {
    return 2 * i;
}

int right(int i) {
    return 2 * i + 1;
}

int parent(int i) {
    return i / 2;
}

void sift_down(heap *s, int i) {
    int l = left(i), r = right(i), largest;
    if ((l < s->position) && (s->arr[l] < s->arr[i])) {
        largest = l;
    } else {
        largest = i;
    }

    if ((r <= s->position) && (s->arr[r] < s->arr[largest])) {
        largest = r;
    }
    if (largest != i) {
        int t = s->arr[i];
        s->arr[i] = s->arr[largest];
        s->arr[largest] = t;
        sift_down(s, largest);
    }
}

void sift_up(heap *s, int i) {
    if (i == 0) {
        return;
    }
    if (s->arr[i] < s->arr[parent(i)]) {
        int t = s->arr[i];
        s->arr[i] = s->arr[parent(i)];
        s->arr[parent(i)] = t;
        sift_up(s, parent(i));
    }
}

void push(heap *S, int a) {
    if (S->position == S->size) {
        S->size *= 2;
        S->arr = (int *) realloc(S->arr, sizeof(int) * S->size);
    }
    S->arr[S->position++] = a;
    sift_up(S, S->position - 1);
}

int pop(heap *S) {
    int a = S->arr[0];
    S->arr[0] = S->arr[S->position - 1];
    S->position--;
    sift_down(S, 0);
    return a;
}

int empty(heap *S) {
    return (S->position == 0);
}

int main(void) {
    freopen("input.txt", "r", stdin);
    int q, number;
    char str[1000000], comand[4];
    heap *s = create();

    scanf("%d", &q);
    gets(str);
    for (int i = 0; i < q; ++i) {
        gets(str);
        sscanf(str, "%s %d", comand, &number);

        if (comand[1] == 'u') {
            push(s, number);
        } else {
            if (!empty(s)) {
                printf("%d\n", pop(s));
            } else {
                printf("Heap is empty\n");
            }
        }
    }

    return 0;
}