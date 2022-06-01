#include <stdio.h>
#include <malloc.h>

struct list {
    int data;
    struct list *next;
};

int main() {
    freopen("input.txt", "r", stdin);
    struct list *head = NULL;
    struct list *p, *t;
    int number, cnt = 0;

    while (scanf("%d", &number) == 1) {
        p = (struct list *) malloc(sizeof(struct list));
        p->data = number;
        p->next = head;
        head = p;
    }

    t = head;
    while (t != NULL) {
        if ((t->data < 0) && (t->data % 7 == 0)) {
            ++cnt;
        }
        p = t;
        t = t->next;
        free(p);
    }

    printf("%d", cnt);
    return 0;
}