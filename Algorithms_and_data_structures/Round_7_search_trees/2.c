#include <stdio.h>
#include <stdlib.h>
#include <minmax.h>
#include <limits.h>

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

tree *removess(tree *t, int value) {
    if (!t) {
        return 0;
    }
    if (value < t->value) {
        t->left = removess(t->left, value);
    } else {
        if (value > t->value) {
            t->right = removess(t->right, value);
        } else {
            tree *q = t->left;
            tree *r = t->right;
            free(t);
            if (!r) {
                return q;
            }
            tree *min = findmin(r);
            min->right = removemin(r);
            min->left = q;
            return balance(min);
        }
    }
    return balance(t);
}

int value_in_tree(tree *t, int value) {
    if (t != NULL) {
        if (t->value == value) {
            return 1;
        }
        if (value > t->value) {
            if (t->right != NULL) {
                return value_in_tree(t->right, value);
            } else {
                return 0;
            }
        } else {
            if (t->left != NULL) {
                return value_in_tree(t->left, value);
            } else {
                return 0;
            }
        }
    }
    return 0;
}

int findmin_value(tree *t, int value) {
    if (t == NULL) {
        return INT_MAX;
    }
    if (t->value >= value) {
        if (t->left == NULL) {
            return t->value;
        }
        return min(findmin_value(t->left, value), t->value);
    } else {
        return findmin_value(t->right, value);
    }
}

void tree_sort(tree *t) {
    if (t != NULL) {
        tree_sort(t->left);
        printf("%d ", t->value);
        tree_sort(t->right);
    }
    printf("\n");
}

void free_memery(tree *t) {
    if (t != NULL) {
        free_memery(t->left);
        free_memery(t->right);
        free(t);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int m, number, res;
    char string[10], null_string[10], add[3] = "add", remove[6] = "remove", lower[5] = "lower";
    scanf("%d", &m);
    tree *t = NULL;
    tree *p;
    gets(null_string);
    for (int i = 0; i < m; i++) {
        gets(null_string);
        sscanf(null_string, "%s %d", string, &number);
        if (string[0] == add[0]) {
            if (!value_in_tree(t, number)) {
                t = insert(t, number);
                printf("added\n");
            } else {
                printf("dupe\n");
            }
            continue;
        }
        if (string[0] == remove[0]) {
            if (value_in_tree(t, number)) {
                t = removess(t, number);
                printf("removed\n");
            } else {
                printf("miss\n");
            }
            continue;
        }
        if (string[0] == lower[0]) {
            res = findmin_value(t, number);
            if (res != INT_MAX) {
                printf("%d\n", res);
            } else {
                printf("###\n");
            }
            continue;
        }
    }

    free_memery(t);
    return 0;
}
