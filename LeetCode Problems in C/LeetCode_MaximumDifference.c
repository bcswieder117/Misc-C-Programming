/*
Blaine Swieder
C Programming: Max Difference You Can Get From Changing an Integer
Date: June 15th, 2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper to replace digits in a string and return integer
int replaceDigit(char *s, char from, char to) {
    char temp[12]; // Enough for 10^8
    int i = 0;
    while (s[i]) {
        temp[i] = (s[i] == from) ? to : s[i];
        i++;
    }
    temp[i] = '\0';
    return atoi(temp);
}

int maxDiff(int num) {
    char s[12];
    sprintf(s, "%d", num);

    // Max: Replace first non-9 digit with 9
    char *p = s;
    char fromMax = 0;
    while (*p) {
        if (*p != '9') {
            fromMax = *p;
            break;
        }
        p++;
    }

    int maxNum = fromMax ? replaceDigit(s, fromMax, '9') : num;

    // Min: Replace first digit if not 1, else next non-0/1 digit with 0
    char fromMin = 0;
    if (s[0] != '1') {
        fromMin = s[0];
    } else {
        for (int i = 1; s[i]; i++) {
            if (s[i] != '0' && s[i] != '1') {
                fromMin = s[i];
                break;
            }
        }
    }

    int minNum = fromMin ? replaceDigit(s, fromMin, (s[0] != '1') ? '1' : '0') : num;

    return maxNum - minNum;
}

int main() {
    int num = 9288; // test value
    int result = maxDiff(num);
    printf("Max difference: %d\n", result);
    return 0;
}






