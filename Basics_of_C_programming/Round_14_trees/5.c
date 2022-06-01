#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

typedef struct node {
    char *value;
    struct node *left;
    struct node *right;
} tree;

tree *add(tree *t, char *n) {
    if (!t) {
        t = (tree *) malloc(sizeof(tree));
        t->value = (char *) malloc(sizeof(char) * (strlen(n) + 1));
        strcpy(t->value, n);
        t->left = NULL;
        t->right = NULL;
        return t;
    }
    if (strcmp(t->value, n) > 0) {
        t->left = add(t->left, n);
    } else {
        if (strcmp(t->value, n) < 0) {
            t->right = add(t->right, n);
        }
    }
    return t;
}

void post(tree *t) {
    if (t) {
        post(t->left);
        printf("%s\n", t->value);
        post(t->right);
    }
}

int main() {
    char *number[99999];
    tree *t = NULL;

    freopen("input.txt", "r", stdin);
    while (scanf("%s", number) == 1) {
        t = add(t, number);
    }

    post(t);

    return 0;
}