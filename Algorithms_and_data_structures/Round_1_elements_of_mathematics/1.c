#include <stdio.h>
#include <string.h>

int main(void) {
    int q, len_1, len_2;
    char str[100] = {0}, logN[4] = "logN", log_v_stepeni[10] = {0}, n_v_stepeni[10] = {0}, str_2[100] = {
            0}, null_str[100];
    double n_v_stepeni_1 = 0, n_v_stepeni_2 = 0, log_v_stepeni_1 = 0, log_v_stepeni_2 = 0, osnovanie_chesla_v_stepeni_n_1 = 0, osnovanie_chesla_v_stepeni_n_2 = 0;

    scanf("%d", &q);
    gets(null_str);
    for (int i = 0; i < q; ++i) {
        gets(str);
        char *pch = strtok(str, "O ()");
        n_v_stepeni_1 = 0;
        log_v_stepeni_1 = 0;
        osnovanie_chesla_v_stepeni_n_1 = 1;
        while (pch != NULL) {

            if (pch[0] == 'N') {
                if (pch[1] != '\0') {
                    strcpy(n_v_stepeni, &pch[2]);
                    sscanf(n_v_stepeni, "%lf", &n_v_stepeni_1);
                } else {
                    n_v_stepeni_1 = 1;
                }

                pch = strtok(NULL, "O ()");
                continue;
            }

            len_1 = strlen(pch);
            if (len_1 >= 4) {
                if (pch[1] == logN[1] && pch[2] == logN[2] && pch[3] == logN[3] && pch[0] == logN[0]) {
                    if (pch[4] != '\0') {
                        strcpy(log_v_stepeni, &pch[5]);
                        sscanf(log_v_stepeni, "%lf", &log_v_stepeni_1);
                    } else {
                        log_v_stepeni_1 = 1;
                    }

                    pch = strtok(NULL, "O ()");
                    continue;
                }
            }

            if (pch[len_1 - 1] == 'N' && pch[len_1 - 2] == '^') {
                sscanf(pch, "%lf", &osnovanie_chesla_v_stepeni_n_1);

                pch = strtok(NULL, "O ()");
                continue;
            }

            pch = strtok(NULL, "O ()");
        }

        gets(str_2);
        char *pch_2 = strtok(str_2, "O ()");
        n_v_stepeni_2 = 0;
        log_v_stepeni_2 = 0;
        osnovanie_chesla_v_stepeni_n_2 = 1;
        while (pch_2 != NULL) {

            if (pch_2[0] == 'N') {
                if (pch_2[1] != '\0') {
                    strcpy(n_v_stepeni, &pch_2[2]);
                    sscanf(n_v_stepeni, "%lf", &n_v_stepeni_2);
                } else {
                    n_v_stepeni_2 = 1;
                }

                pch_2 = strtok(NULL, "O ()");
                continue;
            }

            len_2 = strlen(pch_2);
            if (len_2 >= 4) {
                if (pch_2[1] == logN[1] && pch_2[2] == logN[2] && pch_2[3] == logN[3] && pch_2[0] == logN[0]) {
                    if (pch_2[4] != '\0') {
                        strcpy(log_v_stepeni, &pch_2[5]);
                        sscanf(log_v_stepeni, "%lf", &log_v_stepeni_2);
                    } else {
                        log_v_stepeni_2 = 1;
                    }

                    pch_2 = strtok(NULL, "O ()");
                    continue;
                }
            }

            if (pch_2[len_2 - 1] == 'N' && pch_2[len_2 - 2] == '^') {
                sscanf(pch_2, "%lf", &osnovanie_chesla_v_stepeni_n_2);

                pch_2 = strtok(NULL, "O ()");
                continue;
            }

            pch_2 = strtok(NULL, "O ()");
        }

        if (osnovanie_chesla_v_stepeni_n_1 > osnovanie_chesla_v_stepeni_n_2) {
            printf("1");
        } else if (osnovanie_chesla_v_stepeni_n_2 > osnovanie_chesla_v_stepeni_n_1) {
            printf("-1");
        } else {
            if (n_v_stepeni_1 > n_v_stepeni_2) {
                printf("1");
            } else if (n_v_stepeni_2 > n_v_stepeni_1) {
                printf("-1");
            } else {
                if (log_v_stepeni_1 > log_v_stepeni_2) {
                    printf("1");
                } else if (log_v_stepeni_2 > log_v_stepeni_1) {
                    printf("-1");
                } else {
                    printf("0");
                }
            }
        }

        printf("\n");
    }


    return 0;
}