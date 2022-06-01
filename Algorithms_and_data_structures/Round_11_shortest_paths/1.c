#include <stdio.h>

#define MAX 100050

int main() {
    freopen("input.txt", "r", stdin);
    int n, transfer_rate, sender_server, recipients_servers, server_1, server_2;
    scanf("%d", &n);
    int array[101][101] = {0}, d[101] = {0}, v[101] = {0};
    scanf("%d%d", &sender_server, &recipients_servers);
    while (scanf("%d%d%d", &server_1, &server_2, &transfer_rate) == 3) {
        array[server_2][server_1] = transfer_rate;
        array[server_1][server_2] = transfer_rate;
    }
    for (int i = 1; i <= n; i++) {
        d[i] = MAX;
        v[i] = 1;
    }
    d[sender_server] = 0;
    int minindex, min, temp;
    do {
        min = MAX;
        minindex = MAX;
        for (int i = 1; i <= n; i++) {
            if ((v[i] == 1) && (d[i] < min)) {
                min = d[i];
                minindex = i;
            }
        }

        if (minindex != MAX) {
            for (int i = 1; i <= n; i++) {
                if (array[minindex][i] > 0) {
                    temp = min + array[minindex][i];
                    if (temp < d[i]) {
                        d[i] = temp;
                    }
                }
            }
            v[minindex] = 0;
        }
    } while (minindex < MAX);

    if (d[recipients_servers] == MAX) {
        printf("no");
    } else {
        printf("%d", d[recipients_servers]);
    }

    return 0;
}