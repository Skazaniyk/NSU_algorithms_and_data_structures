#include <stdio.h>
#include <math.h>

int day_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int day_in_leap_month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int data_correct(int d, int m, int y) {

    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
        if (d > day_in_leap_month[m - 1]) {
            return 1;
        }
    } else {
        if (d > day_in_month[m - 1]) {
            return 1;
        }
    }

    if (y > 2050 || y < 1) {
        return 1;
    }
    if (m > 12 || m < 1) {
        return 1;
    }

    return 0;
}


int main() {
    int d1, m1, y1, d2, m2, y2, total_days_1 = 0, total_days_2 = 0, total_days;
    scanf("%d %d %d", &d1, &m1, &y1);
    scanf("%d %d %d", &d2, &m2, &y2);

    if (data_correct(d1, m1, y1) == 1 || data_correct(d2, m2, y2) == 1) {
        printf("ERROR");
        return 0;
    }

    total_days_1 = 365 * y1 + ((y1 - 1) / 4 - (y1 - 1) / 100 + (y1 - 1) / 400);
    total_days_1 += d1;
    if (y1 % 4 == 0 && y1 % 100 != 0 || y1 % 400 == 0) {
        for (int m = 0; m < m1 - 1; ++m) {
            total_days_1 += day_in_leap_month[m];
        }
    } else {
        for (int m = 0; m < m1 - 1; ++m) {
            total_days_1 += day_in_month[m];
        }
    }

    total_days_2 = 365 * y2 + ((y2 - 1) / 4 - (y2 - 1) / 100 + (y2 - 1) / 400);
    total_days_2 += d2;
    if (y2 % 4 == 0 && y2 % 100 != 0 || y2 % 400 == 0) {
        for (int m = 0; m < m2 - 1; ++m) {
            total_days_2 += day_in_leap_month[m];
        }
    } else {
        for (int m = 0; m < m2 - 1; ++m) {
            total_days_2 += day_in_month[m];
        }
    }

    total_days = abs(total_days_1 - total_days_2);
    printf("%d", total_days);
    return 0;
}