#include <stdio.h>
#include "malloc.h"

typedef struct Stack {
    int size;
    int top;
    char *arr;
} Stack;

Stack *create() {
    Stack *s;
    s = (Stack *) malloc(sizeof(Stack));
    s->top = 0;
    s->size = 1;
    s->arr = (char *) malloc(sizeof(char) * s->size);

    return s;
}

void makenull(Stack *S) {
    S->top = 0;
}

int empty(Stack *S) {
    return (S->top == 0);
}

char top(Stack *S) {
    return (S->arr[S->top - 1]);
}

char pop(Stack *S) {
    char a = S->arr[S->top - 1];
    S->top--;
    return a;
}

void push(Stack *S, char a) {
    if (S->top == S->size) {
        S->size *= 2;
        S->arr = (char *) realloc(S->arr, sizeof(char) * S->size);
    }
    S->arr[S->top++] = a;
}

int is_operation(char a) {
    char array[] = "+-*/=";
    for (int i = 0; i < 5; ++i) {
        if (array[i] == a) {
            return 1;
        }
    }
    return 0;
}

int prioritet(char a) {
    if (a == '(') {
        return 1;
    }
    if (a == ')') {
        return 2;
    }
    if (a == '=') {
        return 3;
    }
    if (a == '+' || a == '-') {
        return 4;
    }
    if (a == '*' || a == '/') {
        return 5;
    }
    return 0;
}

int main(void) {
    freopen("input.txt", "r", stdin);
    char output_str[1001] = {0}, symbol;
    int i = 0;
    Stack *s = create();

    while (scanf("%c", &symbol) == 1) {
        if (symbol >= 'a' && symbol <= 'z') {
            output_str[i] = symbol;
            ++i;
            continue;
        }

        if (symbol == '(') {
            push(s, symbol);
            continue;
        }

        if (symbol == ')') {
            while (top(s) != '(') {
                output_str[i] = pop(s);
                ++i;
            }
            pop(s);
            continue;
        }

        if (is_operation(symbol)) {
            while (!empty(s) && (prioritet(top(s)) >= prioritet(symbol))) {
                output_str[i] = pop(s);
                ++i;
            }
            push(s, symbol);
            continue;
        }
    }
    while (!empty(s)) {
        output_str[i] = pop(s);
        ++i;
    }
    output_str[i] = '\0';
    printf("%s", output_str);

    return 0;
}