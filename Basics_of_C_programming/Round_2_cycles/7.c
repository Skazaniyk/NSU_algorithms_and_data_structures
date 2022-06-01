#include <stdio.h>
#include <math.h>

int main() {
    int n, min, max, k, min_id, max_id;
    scanf("%i", &n);
    scanf("%i", &min);
    max = min;
    min_id = 1;
    max_id = 1;
    for (int i = 2; i <= n; ++i) {
        scanf("%i", &k);
        if (k > max) {
            max = k;
            max_id = i;
        }
        if (k < min) {
            min = k;
            min_id = i;
        }
    }

    printf("%i %i %i %i", min, min_id, max, max_id);
    return 0;
}