#include <stdio.h>
#include <malloc.h>

typedef struct heap {
    int heap_size;
    int position;
    int *arr;
} heap;

heap *create(int n) {
    heap *arr = (heap *) malloc(sizeof(heap));
    arr->heap_size = n;
    arr->position = 0;
    arr->arr = (int *) malloc(sizeof(int) * (n + 10));
    return arr;
}

void swap(int *a, int *b) {
    int t = *b;
    *b = *a;
    *a = t;
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

int parent(int i) {
    return (i + 1) / 2;
}

void sift_down(heap *s, int i) {
    int l = left(i), r = right(i), largest;

    if ((l < s->heap_size) && (s->arr[l] > s->arr[i])) {
        largest = l;
    } else {
        largest = i;
    }

    if ((r < s->heap_size) && (s->arr[r] > s->arr[largest])) {
        largest = r;
    }

    if (largest != i) {
        swap(&s->arr[i], &s->arr[largest]);
        sift_down(s, largest);
    }
}

void sift_up(heap *s, int i) {
    if (i == 0) {
        return;
    }
    if (s->arr[i] > s->arr[parent(i)]) {
        swap(&s->arr[i], &s->arr[parent(i)]);
        sift_up(s, parent(i));
    }
}

void push(heap *S, int a) {
    S->arr[S->position++] = a;
    //sift_up(S, S->position - 1);
}

void Build_Max_Heap(heap *s) {
    for (int i = (s->heap_size - 1) / 2; i >= 0; i--) {
        sift_down(s, i);
    }
}

void Heapsort(heap *s) {
    Build_Max_Heap(s);

    int len = s->heap_size - 1;
    while (len != 0) {
        swap(&s->arr[0], &s->arr[len]);
        s->heap_size--;
        sift_down(s, 0);
        len--;
    }
}

int main(void) {
    freopen("input.txt", "r", stdin);
    int n, number;

    scanf("%d", &n);
    heap *s = create(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &number);
        push(s, number);
    }

    int x = s->heap_size;
    Heapsort(s);
    s->heap_size = x;

    for (int j = 0; j < s->heap_size; ++j) {
        printf("%d ", s->arr[j]);
    }

    return 0;
}