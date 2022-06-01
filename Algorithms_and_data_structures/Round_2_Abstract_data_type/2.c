#include <stdio.h>
#include "malloc.h"
#include "stdlib.h"
#include "string.h"

typedef struct Stack {
    int size;
    int top;
    int *arr;
} Stack;

Stack *create() {
    Stack *s;
    s = (Stack *) malloc(sizeof(Stack));
    s->top = 0;
    s->size = 1;
    s->arr = (int *) malloc(sizeof(int) * s->size);

    return s;
}

void makenull(Stack *S) {
    S->top = 0;
}

int empty(Stack *S) {
    return (S->top == 0);
}

int top(Stack *S) {
    return (S->arr[S->top - 1]);
}

int pop(Stack *S) {
    int a = S->arr[S->top - 1];
    S->top--;
    return a;
}

void push(Stack *S, int a) {
    if (S->top == S->size) {
        S->size *= 2;
        S->arr = (int *) realloc(S->arr, sizeof(int) * S->size);
    }
    S->arr[S->top++] = a;
}

int operation(char c, int a, int b) {
    if (c == '-') {
        return a - b;
    }
    if (c == '+') {
        return a + b;
    }
    if (c == '*') {
        return a * b;
    }
    if (c == '/') {
        return a / b;
    }
}

int main(void) {
    freopen("input.txt", "r", stdin);
    char symbol, x[2001];
    int number, summ, number_1, number_2;
    Stack *s = create();

    gets(x);
    char *pch = strtok(x, " ");
    while (pch != NULL) {
        if (pch[0] >= '0' && pch[0] <= '9') {
            sscanf(pch, "%d", &number);
            push(s, number);
        } else {
            sscanf(pch, "%c", &symbol);
            number_1 = pop(s);
            number_2 = pop(s);
            push(s, operation(symbol, number_2, number_1));
        }
        pch = strtok(NULL, " ");
    }

    printf("%d", pop(s));

    return 0;
}