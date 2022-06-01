#include <stdio.h>
#include <malloc.h>

typedef struct list {
    int data;
    struct list *next;
    struct list *prev;
} list;

int main() {
    freopen("input.txt", "r", stdin);
    list *head = NULL, *p, *t, *pred;
    int n, k;
    scanf("%d%d", &n, &k);

    p = (struct list *) malloc(sizeof(struct list));
    p->data = 1;
    p->next = NULL;
    head = p;
    pred = p;

    for (int i = 2; i <= n; ++i) {
        p = (struct list *) malloc(sizeof(struct list));
        p->next = NULL;
        p->prev = pred;
        p->data = i;
        pred->next = p;
        pred = pred->next;
    }
    pred->next = head;
    head->prev = pred;

    t = head->prev;
    while (t->next != t) {
        for (int i = 0; i < k; ++i) {
            t = t->next;
        }
        p = t->prev;
        t->prev->next = t->next;
        t->next->prev = t->prev;
        free(t);
        t = p;
    }

    printf("%d", t->data);
    return 0;
}