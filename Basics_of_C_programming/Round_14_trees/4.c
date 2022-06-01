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

int leaves_tree(tree *start_tree, int neaded_level, int cur_level) {
    if (!start_tree) {
        return 0;
    }
    if (cur_level == neaded_level) {
        return 1;
    }
    return leaves_tree(start_tree->left, neaded_level, cur_level + 1) +
           leaves_tree(start_tree->right, neaded_level, cur_level + 1);
}

int main() {
    int number, level;
    tree *t = NULL;

    freopen("input.txt", "r", stdin);
    scanf("%d", &level);
    while (scanf("%d", &number) == 1) {
        t = add(t, number);
    }

    printf("%d", leaves_tree(t, level, 0));

    return 0;
}