#include <stdio.h>
#include <string.h>

int calcLetters(char *iStr, int *oLowerCnt, int *oUpperCnt, int *oDigitsCnt) {
    *oDigitsCnt = 0, *oUpperCnt = 0;
    *oLowerCnt = 0;

    int k = strlen(iStr);
    for (int i = 0; i < k; ++i) {
        if ((iStr[i] >= 'a') && (iStr[i] <= 'z')) {
            ++*oLowerCnt;
        }
        if ((iStr[i] >= 'A') && (iStr[i] <= 'Z')) {
            ++*oUpperCnt;
        }
        if ((iStr[i] >= '0') && (iStr[i] <= '9')) {
            ++*oDigitsCnt;
        }
    }

    return strlen(iStr);
}

int main() {
    int line = 1, lower_cnt, upper_cnt, str_len, digits_cnt;
    char string[110];
    while (fgets(string, 110, stdin)) {
        str_len = calcLetters(string, &lower_cnt, &upper_cnt, &digits_cnt);
        printf("Line %d has %d chars: %d are letters (%d lower, %d upper), %d are digits.\n", line, str_len - 1,
               lower_cnt + upper_cnt, lower_cnt, upper_cnt, digits_cnt);
        ++line;
    }

    return 0;
}