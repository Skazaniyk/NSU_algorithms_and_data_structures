#include <stdio.h>
#include <malloc.h>

typedef unsigned long long ull;

typedef struct answer {
    ull price;
    ull number;
} answer;

typedef struct choice {
    ull price;
    ull wight;
} choice;

ull cheslo_v_stepeni(ull a, ull n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 1) {
        return a * cheslo_v_stepeni(a, n - 1);
    } else {
        return cheslo_v_stepeni(a * a, n / 2);
    }
}

ull get_price_of_number(ull number, choice *array, ull n, ull max_weght) {
    ull sum = 0, weight = 0;
    ull i = 0;
    while (number != 0) {
        if (number & 1) {
            sum += array[i].price;
            weight += array[i].wight;
            if (weight > max_weght) {
                return 0;
            }
        }
        i++;
        number >>= 1;
    }
    return sum;
}

ull get_count_items(ull n) {
    ull count = 0;
    while (n != 0) {
        if (n & 1) {
            count += 1;
        }
        n >>= 1;
    }

    return count;
}

int main(void) {
    freopen("input.txt", "r", stdin);
    ull w, n;
    scanf("%llu%llu", &n, &w);
    choice *array = (choice *) malloc(sizeof(choice) * (n + 10));
    for (ull i = 0; i < n; i++) {
        scanf("%llu%llu", &array[i].wight, &array[i].price);
    }
    struct answer *p = (struct answer *) malloc(sizeof(struct answer));
    p->price = 0;
    p->number = 0;

    ull upper_bound = cheslo_v_stepeni(2, n), price, count_items;
    for (ull i = 0; i < upper_bound; ++i) {
        price = get_price_of_number(i, array, n, w);
        if (price > p->price) {
            p->price = price;
            p->number = i;
        }
    }

    count_items = get_count_items(p->number);
    printf("%llu %llu\n", p->price, count_items);
    ull k = p->number, i = 0;
    while (k != 0) {
        if (k & 1) {
            printf("%llu ", i + 1);
        }
        i++;
        k >>= 1;
    }
    return 0;
}