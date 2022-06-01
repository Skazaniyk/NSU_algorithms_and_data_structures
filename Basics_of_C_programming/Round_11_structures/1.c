#include <stdio.h>

typedef struct DateTime_s {
    int year, month, day;
    int hours, minutes, seconds;
} DateTime;
DateTime dates[50050];

is_date_min(int id_1, int id_2) {
    if ((dates[id_1].year - dates[id_2].year) != 0) {
        return dates[id_1].year - dates[id_2].year;
    }
    if ((dates[id_1].month - dates[id_2].month) != 0) {
        return dates[id_1].month - dates[id_2].month;
    }
    if ((dates[id_1].day - dates[id_2].day) != 0) {
        return dates[id_1].day - dates[id_2].day;
    }
    if ((dates[id_1].hours - dates[id_2].hours) != 0) {
        return dates[id_1].hours - dates[id_2].hours;
    }
    if ((dates[id_1].minutes - dates[id_2].minutes) != 0) {
        return dates[id_1].minutes - dates[id_2].minutes;
    }
    if ((dates[id_1].seconds - dates[id_2].seconds) != 0) {
        return dates[id_1].seconds - dates[id_2].seconds;
    }
    return 0;
}

DateTime min(const DateTime *arr, int cnt) {
    int min_id = 0;
    for (int i = 0; i < cnt; ++i) {
        if (is_date_min(i, min_id) < 0) {
            min_id = i;
        }
    }
    return arr[min_id];
}

int main() {
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d%d%d", &dates[i].year, &dates[i].month, &dates[i].day,
              &dates[i].hours, &dates[i].minutes, &dates[i].seconds);
    }

    DateTime minimum_date = min(dates, n);

    printf("%d %d %d %d %d %d", minimum_date.year, minimum_date.month,
           minimum_date.day, minimum_date.hours, minimum_date.minutes, minimum_date.seconds);
    return 0;
}