#include <stdio.h>

int binsearch (int a [] , int l , int r , int x ){
    int search = -1;
    while(l <= r){
        int middle = (l + r)/2;
        if (x == a[middle]){
            if(a[middle + 1] == x){
                search = middle + 1;
                l= middle + 1;
            }
            else{
                search = middle;
                break;
            }
        }
        else{
            if(x < a[middle]){
                r = middle - 1;
            }
            else{
                l = middle + 1;
            }
        }
    }

    return search;
}

int main() {
    int n, a[100000],q, qi;

    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }

    scanf("%d",&q);
    printf("\n");
    int xi = 0;
    for(int i = 0; i < q; ++i){
        scanf("%d", &qi);
        xi = binsearch(a, 0, n - 1, qi + xi);
        printf("%d\n", xi);
    }

    return 0;
}