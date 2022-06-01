#include <stdio.h>

int main(void) {
    long long int k, y;
    scanf("%lld%lld", &k, &y);
    if ((0 <= y) && (y <= (k-1)))
        printf("legal");
    else printf("out of bounds");
}