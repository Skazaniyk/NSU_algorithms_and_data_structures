#include <stdio.h>
#include "malloc.h"
#include "string.h"

typedef struct Queue {
    int size;
    int first;
    int leng;
    int *arr;
} Queue;

Queue *create() {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->first = 0;
    q->leng = 0;
    q->size = 1;
    q->arr = (int *) malloc(sizeof(int) * q->size);
    return q;
}

int empty(Queue *q) {
    return (q->leng == 0);
}

void enqueue(Queue *q, int a) {
    if (q->leng == q->size) {
        q->arr = (int *) realloc(q->arr, sizeof(int) * q->size * 2);
        if (q->first > 0)
            memcpy(q->arr + q->size, q->arr, (q->first) * sizeof(int));
        q->size *= 2;
    }
    q->arr[(q->first + q->leng++) % q->size] = a;
}

int dequeue(Queue *q) {
    int a = q->arr[q->first++];
    q->first %= q->size;
    q->leng--;
    return a;
}

int main(void) {
    freopen("input.txt", "r", stdin);
    Queue *q = create();

    int size_of_queue, m, number, items, summ = 0, delitel, queue_len;
    scanf("%d%d", &size_of_queue, &m);

    while (scanf("%d", &items) == 1) {
        if (items < 0) {
            if (q->leng < -items) {
                delitel = q->leng;
                queue_len = q->leng;
                for (int i = 0; i < queue_len; ++i) {
                    summ += dequeue(q);
                }
                if (delitel != 0) {
                    printf("%d\n", summ / delitel);
                }
                summ = 0;
                printf("Empty queue\n");
            } else {
                for (int i = 0; i < -items; ++i) {
                    summ += dequeue(q);
                }
                printf("%d\n", summ / -items);
                summ = 0;
            }
            continue;
        }

        if (items > size_of_queue - q->leng) {
            queue_len = q->leng;
            for (int i = 0; i < size_of_queue - queue_len; ++i) {
                scanf("%d", &number);
                enqueue(q, number);
            }
            for (int i = 0; i < items - size_of_queue + queue_len; ++i) {
                scanf("%d", &number);
            }
            printf("Memory overflow\n");
        } else {
            for (int i = 0; i < items; ++i) {
                scanf("%d", &number);
                enqueue(q, number);
            }
        }
    }

    return 0;
}