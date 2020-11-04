#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SZ 128

int main(int argc, char *argv[]) {
    int x = 0;

    if (argc > 1 && strcmp(argv[1], "-a") == 0)
        x = 1;

    int sz_file = argc - x - 1;
    FILE **objects = malloc(sz_file * sizeof(FILE * ));
    if (objects == NULL) {
        printf("There are was an error\n");
        return 1;
    }
    const char *regime;
    if (x) regime = "a";
    else regime = "w";
    for (int i = 0; i < sz_file; i++) {
        objects[i] = fopen(argv[i + x + 1], regime);
        if (objects[i] == NULL) {
            printf("There are was an error with file %s\n", argv[i + x + 1]);
            return 2;
        }
    }

    char buffer[SZ];
    while (fgets(buffer, SZ-1, stdin) != NULL) {
        printf("%s", buffer);
        for (int i = 0; i < sz_file; i++) {
            fprintf(objects[i], "%s", buffer);
        }
    }

    for (int i = 0; i < sz_file; i++) {
        fclose(objects[i]);
    }
    free(objects);
    return 0;
}