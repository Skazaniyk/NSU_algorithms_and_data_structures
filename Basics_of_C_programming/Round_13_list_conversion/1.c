#include <stdio.h>
#include <malloc.h>

struct list {
    int data;
    struct list *next;
};

int main() {
    freopen("input.txt", "r", stdin);
    struct list *head = NULL;
    struct list *last, *p, *t, *pred;
    struct list *nn;
    int number;

    scanf("%d", &number);
    p = (struct list *) malloc(sizeof(struct list));
    p->data = number;
    p->next = NULL;
    last = p;
    head = p;

    while (scanf("%d", &number) == 1) {
        p = (struct list *) malloc(sizeof(struct list));
        last->next = p;
        p->data = number;
        last = p;
        p->next = NULL;
    }

    t = head;
    pred = t;
    t = t->next;
    while (t != NULL) {
        if (t->data != pred->data) {
            pred = t;
            t = t->next;
        } else {
            nn = t->next;
            free(t);
            t = nn;
            pred->next = t;
        }
    }

    t = head;
    while (t != NULL) {
        printf("%d ", t->data);
        p = t;
        t = t->next;
        free(p);
    }

    return 0;
}