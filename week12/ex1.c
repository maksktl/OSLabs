#include <stdio.h>

#define SIZE 20

int main() {
    FILE *random = fopen("/dev/random", "r");
    if (random == NULL) {
        printf("Error opening a folder");
        return 1;
    }
    char buffer[SIZE + 1];
    for (int i = 0; i < SIZE; i++) {
        int c = fgetc(random);
        if (c == EOF) {
            printf("Reading error");
            return 2;
        }
        if (c >= ' ' && c <= '~') {
            buffer[i] = c;
            continue;
        }
        i--;
    }
    buffer[SIZE] = '\0';
    for (int i = 0; i < SIZE; i++)
        printf("%c", buffer[i]);
    fclose(random);
    return 0;
}