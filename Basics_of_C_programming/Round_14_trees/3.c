#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

typedef struct node {
    int value;
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

int leaves_tree(tree *start_tree) {
    if (!start_tree) return 0;
    if (start_tree->left == NULL && start_tree->right == NULL) {
        return 1;
    }
    return leaves_tree(start_tree->left) + leaves_tree(start_tree->right);
}

int main() {
    int number;
    tree *t = NULL;

    freopen("input.txt", "r", stdin);
    while (scanf("%d", &number) == 1) {
        t = add(t, number);
    }

    printf("%d", leaves_tree(t));

    return 0;
}