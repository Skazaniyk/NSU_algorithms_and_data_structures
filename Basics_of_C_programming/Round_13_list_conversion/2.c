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
    int number, del_number;
    scanf("%d ", &del_number);

    scanf("%d", &number);
    p = (struct list *) malloc(sizeof(struct list));
    p->data = number;
    p->next = NULL;
    head = p;

    while (scanf("%d", &number) == 1) {
        p = (struct list *) malloc(sizeof(struct list));
        p->data = number;
        p->next = head;
        head = p;
    }

    t = head;
    while (t != NULL) {
        if (t->next != NULL && t->next->data == del_number) {
            p = t;
            t = p->next;
            free(p);
        } else {
            printf("%d ", t->data);
            p = t;
            t = t->next;
            free(p);
        }
    }

    return 0;
}