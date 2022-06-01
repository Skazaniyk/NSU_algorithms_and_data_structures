#include <stdio.h>
#include <string.h>

int main() {
    char color[10], spray_paint[30], first_color, second_color;
    int first_position = 0, second_position = 0;

    scanf("%s", color);
    scanf("%s", spray_paint);

    if (color[0] == 'p') {
        first_color = 'R';
        second_color = 'B';
    }
    if (color[0] == 'g') {
        first_color = 'Y';
        second_color = 'B';
    }
    if (color[0] == 'o') {
        first_color = 'R';
        second_color = 'Y';
    }

    int k = strlen(spray_paint);
    for (int i = 0; i < k; ++i) {
        if (spray_paint[i] == first_color || spray_paint[i] == second_color) {
            if (first_position == 0) {
                first_position = i + 1;
            } else {
                second_position = i + 1;
            }
        }
    }

    if (first_position > second_position) {
        int t = first_position;
        first_position = second_position;
        second_position = t;
    }

    printf("%d %d", first_position, second_position);
    return 0;
}