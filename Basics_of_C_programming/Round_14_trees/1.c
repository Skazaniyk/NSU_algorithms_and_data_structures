#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    signed long value;
    struct node *left;
    struct node *right;
} tree;

tree *add(tree *t, int n) {
    if (t == NULL) {
        t = (tree *) malloc(sizeof(tree));
        t->value = n;
        t->left = NULL;
        t->right = NULL;
        return t;
    }
    if (n < t->value) {
        t->left = add(t->left, n);
    } else {
        if (n > t->value) {
            t->right = add(t->right, n);
        }
    }
    return t;
}

void pref(tree *t) {
    if (t) {
        printf("%d ", t->value);
        pref(t->left);
        pref(t->right);
    }
}

void post(tree *t) {
    if (t) {
        post(t->left);
        post(t->right);
        printf("%d ", t->value);
    }
}

int main() {
    signed long number;
    tree *t = NULL;

    while (scanf("%d", &number) == 1) {
        t = add(t, number);
    }

    pref(t);
    printf("\n");
    post(t);

    return 0;
}