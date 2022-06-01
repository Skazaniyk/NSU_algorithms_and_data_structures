#include <stdio.h>
#include "malloc.h"
#include "stdlib.h"

#define MAX INT_MAX

struct list {
    int data;
    struct list *next;
};

typedef struct stack {
    struct list *top;
} Stack;

Stack *create() {
    Stack *S;
    S = (Stack *) malloc(sizeof(Stack));
    S->top = NULL;
    return S;
}

void makenull(Stack *S) {
    while (S->top) {
        struct list *p = S->top;
        S->top = p->next;
        free(p);
    }
}

int empty(Stack *S) {
    return (S->top == NULL);
}

int top(Stack *S) {
    return (S->top->data);
}

int pop(Stack *S) {
    int a;
    struct list *p;
    p = S->top;
    a = p->data;
    S->top = p->next;
    free(p);
    return a;
}

void push(Stack *S, int a) {
    struct list *p;
    p = (struct list *) malloc(sizeof(struct list));
    p->data = a;
    p->next = S->top;
    S->top = p;
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, m, p, k, transfer_rate, server_1, server_2;
    scanf("%d%d%d%d", &n, &m, &p, &k);
    int array[301][301] = {0}, d[301][301] = {0}, v[301] = {0};

    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &server_1, &server_2, &transfer_rate);
        if (array[server_1][server_2] == 0 || array[server_1][server_2] > transfer_rate) {
            array[server_1][server_2] = transfer_rate;
            array[server_2][server_1] = transfer_rate;
        }
    }

    int end, weight, count, minindex, min, temp;
    Stack *stack = create();

    for (int j = 0; j < (n + 1); ++j) {
        for (int i = 1; i < (n + 1); i++) {
            d[j][i] = MAX;
            v[i] = 1;
        }
        d[j][j] = 0;
        do {
            minindex = MAX;
            min = MAX;
            for (int i = 1; i < (n + 1); i++) {
                if ((v[i] == 1) && (d[j][i] < min)) {
                    min = d[j][i];
                    minindex = i;
                }
            }
            if (minindex != MAX) {
                for (int i = 1; i < (n + 1); i++) {
                    if (array[minindex][i] > 0) {
                        temp = min + array[minindex][i];
                        if (temp < d[j][i]) {
                            d[j][i] = temp;
                        }
                    }
                }
                v[minindex] = 0;
            }
        } while (minindex < MAX);
    }

    int start, final;
    for (int j = 0; j < p; ++j) {
        scanf("%d %d", &start, &final);

        printf("%d ", d[start][final]);

        end = final;
        weight = d[start][end];
        count = 1;

        while (end != start) {
            for (int i = 1; i < (n + 1); i++)
                if (array[i][end] != 0) {
                    temp = weight - array[i][end];
                    if (temp == d[start][i]) {
                        weight = temp;
                        end = i;
                        count++;
                        push(stack, i);
                    }
                }
        }
        printf("%d ", count);
        while (!empty(stack)) {
            printf("%d ", pop(stack));
        }
        printf("%d", final);
        printf("\n");
    }

    for (int j = 0; j < k; ++j) {
        scanf("%d %d", &start, &final);
        printf("%d\n", d[start][final]);
    }

    return 0;
}