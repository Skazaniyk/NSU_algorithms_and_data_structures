#include <stdio.h>
#include <string.h>

typedef struct Label_s {
    char name[16]; //имя автора (заканчивается нулём)
    int age; //возраст автора (сколько лет)
} Label;

typedef struct AgeStats_s {
    int cntTotal; //сколько всего подписей
    int cntAdults; //сколько подписей взрослых (хотя бы 18 лет)
    int cntKids; //сколько подписей детей (меньше 14 лет)
} AgeStats;

typedef struct NameStats_s {
    int cntTotal; //сколько всего подписей
    int cntLong; //сколько подписей с именами длиннее 10 букв
} NameStats;

void calcStats(const Label *arr, int cnt, NameStats *oNames, AgeStats *oAges) {
    oNames->cntLong = 0;
    oNames->cntTotal = 0;
    oAges->cntAdults = 0;
    oAges->cntTotal = 0;
    oAges->cntKids = 0;

    for (int i = 0; i < cnt; ++i) {
        oNames->cntTotal++;
        if (strlen(arr[i].name) > 10) {
            oNames->cntLong++;
        }

        oAges->cntTotal++;
        if (arr[i].age >= 18) {
            oAges->cntAdults++;
        }
        if (arr[i].age < 14) {
            oAges->cntKids++;
        }
    }
}

int main() {
    int n;
    char let[4] = {0};
    Label author[1050];
    NameStats oNames;
    AgeStats oAges;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%s", author[i].name, &author[i].age, let);
    }

    calcStats(author, n, &oNames, &oAges);

    printf("names: total = %d\n", oNames.cntTotal);
    printf("names: long = %d\n", oNames.cntLong);
    printf("ages: total = %d\n", oAges.cntTotal);
    printf("ages: adult = %d\n", oAges.cntAdults);
    printf("ages: kid = %d\n", oAges.cntKids);
    return 0;
}