#include <stdio.h>
#include <stdlib.h>

int main() {
    freopen("input.txt", "r", stdin);
    int number_of_topic, number_of_dependencies, lecture_1, lecture_2;
    scanf("%d%d", &number_of_topic, &number_of_dependencies);
    int **array = malloc(sizeof(int *) * (number_of_topic + 5));
    int *count_of_zero = malloc(sizeof(int) * (number_of_topic + 5));
    int *answer = malloc(sizeof(int) * (number_of_topic + 5));
    for (int i = 1; i <= number_of_topic; i++) {
        array[i] = malloc(sizeof(int) * (number_of_topic + 5));
        for (int j = 1; j <= number_of_topic; j++) {
            array[i][j] = 0;
        }
        count_of_zero[i] = 0;
        answer[i] = 0;
    }
    for (int i = 1; i <= number_of_dependencies; i++) {
        scanf("%d%d", &lecture_1, &lecture_2);
        if (array[lecture_1][lecture_2] == 0) {
            count_of_zero[lecture_2]++;
        }
        array[lecture_1][lecture_2] = 1;
    }

    int count = 1, flag;
    while (count <= number_of_topic + 1) {
        flag = 0;
        for (int i = 1; i <= number_of_topic; i++) {
            if (count_of_zero[i] == 0) {
                count_of_zero[i] = -1;
                flag = 1;
                answer[count++] = i;
                for (int j = 1; j <= number_of_topic; j++) {
                    if (array[i][j] == 1) {
                        count_of_zero[j]--;
                        array[i][j] = 0;
                    }
                }
                break;
            }
        }
        if (flag == 0) {
            break;
        }
    }


    if (count - 1 == number_of_topic) {
        for (int i = 1; i < count; i++) {
            printf("%d ", answer[i]);
        }
    } else {
        printf("bad course");
    }

    return 0;
}
