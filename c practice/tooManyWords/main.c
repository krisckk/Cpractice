#include <stdio.h>

int main() {
    char input[1000]; // Assuming maximum input length is 100 characters

    while(fgets(input, sizeof(input), stdin)){
        printf("%s", input);
    }

    printf("\n");

    return 0;
}
