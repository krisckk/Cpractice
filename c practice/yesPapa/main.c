#include <stdio.h>
#include <string.h>

// Function to compare two strings according to Johnny's rule
int stringCompare(char *a, char *b, int length) {
    if (length % 2 == 1) {
        return strcmp(a, b) == 0;
    } else {
        int half_length = length / 2;

        char a1[half_length + 1], a2[half_length + 1], b1[half_length + 1], b2[half_length + 1];
        strncpy(a1, a, half_length);
        a1[half_length] = '\0';
        strncpy(a2, a + half_length, half_length);
        a2[half_length] = '\0';
        strncpy(b1, b, half_length);
        b1[half_length] = '\0';
        strncpy(b2, b + half_length, half_length);
        b2[half_length] = '\0';

        int case1 = (stringCompare(a1, b1, half_length) && stringCompare(a2, b2, half_length));
        int case2 = (stringCompare(a1, b2, half_length) && stringCompare(a2, b1, half_length));

        return case1 || case2;
    }
}

int main() {
    int testCase = 0;
    scanf("%d", &testCase);
    while (testCase--) {
        char firstString[1004], secondString[1004];
        scanf("%s", firstString);
        scanf("%s", secondString);
        int length = strlen(firstString);
        if (stringCompare(firstString, secondString, length) == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
