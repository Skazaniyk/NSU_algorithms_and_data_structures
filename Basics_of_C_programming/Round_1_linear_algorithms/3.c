#include <stdio.h>

int main(void) {
    int a,b,c,min;
    scanf("%i%i%i",&a,&b,&c);

    if (a < b)
        min = a;
    else min = b;

    if (min > c)
        min = c;

    printf("%i", min);
}
