#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateStrings(char* chars, int n, int k, char* current, int depth) {
    if (depth == k) {
        printf("%s\n", current);
        return;
    }
    
    for (int i = 0; i < n; i++) {
        current[depth] = chars[i];
        generateStrings(chars, n, k, current, depth + 1);
    }
}

int main() {
    char chars[21];  // Max 20 characters + null terminator
    int k;

    scanf("%s", &chars);
    scanf("%d", &k);
    int n = strlen(chars);

    char* current = (char*)malloc((k + 1) * sizeof(char));
    current[k] = '\0';

    generateStrings(chars, n, k, current, 0);

    free(current);
    return 0;
}