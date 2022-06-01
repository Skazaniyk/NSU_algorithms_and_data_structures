#include <stdio.h>
#include <stdlib.h>

FILE *in, *out;

typedef struct node {
    int value;
    unsigned char height;
    struct node *left;
    struct node *right;
} tree;

unsigned char height(tree *t) {
    return t ? t->height : 0;
}

int bfactor(tree *t) {
    return height(t->right) - height(t->left);
}

void fixheight(tree *t) {
    unsigned char hl = height(t->left);
    unsigned char hr = height(t->right);
    t->height = (hl > hr ? hl : hr) + 1;
}

tree *rotateright(tree *t) {
    tree *q = t->left;
    t->left = q->right;
    q->right = t;
    fixheight(t);
    fixheight(q);
    return q;
}

tree *rotateleft(tree *q) {
    tree *p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

tree *balance(tree *t) {
    fixheight(t);
    if (bfactor(t) == 2) {
        if (bfactor(t->right) < 0)
            t->right = rotateright(t->right);
        return rotateleft(t);
    }
    if (bfactor(t) == -2) {
        if (bfactor(t->left) > 0)
            t->left = rotateleft(t->left);
        return rotateright(t);
    }
    return t;
}

tree *insert(tree *t, int value) {
    if (t == NULL) {
        t = (tree *) malloc(sizeof(tree));
        t->value = value;
        t->left = NULL;
        t->right = NULL;
    } else {
        if (value < t->value) {
            t->left = insert(t->left, value);
        } else {
            t->right = insert(t->right, value);
        }
    }
    return balance(t);
}

tree *findmin(tree *t) {
    return t->left ? findmin(t->left) : t;
}

tree *removemin(tree *t) {
    if (t->left == 0)
        return t->right;
    t->left = removemin(t->left);
    return balance(t);
}

void tree_sort(tree *t) {
    if (t != NULL) {
        tree_sort(t->left);
        fwrite(&t->value, sizeof(int), 1, out);
        tree_sort(t->right);
    }
}

void free_memery(tree *t) {
    if (t != NULL) {
        free_memery(t->left);
        free_memery(t->right);
        free(t);
    }
}

int main() {
    in = fopen("input.bin", "rb");
    out = fopen("output.bin", "wb");
    int n, value;

    fread(&n, sizeof(int), 1, in);
    tree *t = NULL;
    for (int i = 0; i < n; i++) {
        fread(&value, sizeof(int), 1, in);
        t = insert(t, value);
    }

    tree_sort(t);
    free_memery(t);
    fclose(in);
    fclose(out);
    return 0;
}
