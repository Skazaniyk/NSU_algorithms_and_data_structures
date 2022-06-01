#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int compare_ll(const void *a, const void *b) {
    const long long *da = (const long long *) a;
    const long long *db = (const long long *) b;
    return (*da > *db) - (*da < *db);
}

int cmpstr(void const *a, void const *b) {
    char const *aa = (char const *) a;
    char const *bb = (char const *) b;
    return strcmp(aa, bb);
}

int lower_bound(void *const a, const void *x, size_t size, unsigned int total_elements,
                int (*cmp)(const void *, const void *)) {
    int l = 0, h = total_elements * size;
    while (l < h) {
        int mid = size * ((h + l) / size >> 1);
        if (cmp(a + mid, x) >= 0)
            h = mid;
        else
            l = mid + size;
    }
    return l / size;
}

long long A[100005];
char B[100005][32];

int main() {
    freopen("input.txt", "r", stdin);
    int n1, n2, q1, q2;
    long long x;
    char x_c[32];

    scanf("%d", &n1);
    for (int i = 0; i < n1; i++){
        scanf("%lld", &A[i]);
    }

    qsort(A, n1, sizeof(long long), compare_ll);

    scanf("%d", &n2);
    for (int i = 0; i < n2; i++){
        scanf("%s", B[i]);
    }
    scanf("%d", &q1);
    for (int i = 0; i < q1; i++) {
        scanf("%lld", &x);
        printf("%d\n", lower_bound(A, &x, sizeof(long long), n1, (int (*)(const void *, const void *)) compare_ll));
    }

    qsort(B, n2, 32, cmpstr);

    scanf("%d", &q2);
    for (int i = 0; i < q2; i++) {
        scanf("%s", x_c);
        printf("%d\n", lower_bound(B, x_c, 32, n2, cmpstr));
    }
}