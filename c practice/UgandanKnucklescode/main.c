#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    const char *str_a = *(const char **)a;
    const char *str_b = *(const char **)b;
    return strlen(str_a) - strlen(str_b);
}

int main() {
    int n;
    scanf("%d", &n);
    char **string = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++) {
        string[i] = (char *)malloc(1001 * sizeof(char));
        scanf("%s", string[i]);
    }

    qsort(string, n, sizeof(char *), cmp);

    for (int i = 0; i < n - 1; i++) {
        if (strstr(string[i + 1], string[i]) == NULL) {
            printf("NO\n");
            for (int j = 0; j < n; j++) {
                free(string[j]);
            }
            free(string);
            return 0;
        }
    }

    printf("YES\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", string[i]);
        free(string[i]);
    }
    free(string);
    return 0;
}