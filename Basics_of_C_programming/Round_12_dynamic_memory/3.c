#include <stdio.h>
#include <stdlib.h>

typedef struct list_s {
    struct list_s *next;
    signed short data;
} list;

int main() {
    freopen("input.txt", "r", stdin);
    list *head = NULL;
    list *p, *t;
    signed long number, cnt = 0, sum = 0;

    scanf("%d", &number);
    p = (list *) malloc(sizeof(list));
    p->data = number;
    p->next = NULL;
    head = p;

    while (scanf("%d", &number) == 1) {
        p = (list *) malloc(sizeof(list));
        p->data = number;
        p->next = NULL;
        t = head;
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = p;
    }

    t = head;
    while (t != NULL) {
        sum += t->data;
        ++cnt;

        p = t;
        t = t->next;
        free(p);
    }

    printf("%d", sum / cnt);
    return 0;
}