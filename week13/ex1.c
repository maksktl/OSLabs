#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXP 50
#define MAXR 50

int main(int argc, char *argv[]) {

    FILE *input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("Error in opening file!\n");
        return 2;
    }
    char buffer[256];

    int procesy[MAXP], susch_resources[MAXR], dstup_r[MAXR];
    int raspolozhenie[MAXP][MAXR], request[MAXP][MAXR];

    //input
    fgets(buffer, 256, input);
    char *p = buffer;
    int existing_count = 0;
    while (*p != '\n') {
        int temp = strtol(p, &p, 10);
        susch_resources[existing_count++] = temp;
    }
    if (getc(input) != '\n') {
        printf("error input file!\n");
        return 1;
    }
    fgets(buffer, 256, input);
    p = buffer;
    int available_count = 0;
    while (*p != '\n') {
        int temp = strtol(p, &p, 10);
        dstup_r[available_count++] = temp;
    }
    int temp;
    if (existing_count != available_count || getc(input) != '\n') {
        printf("error input file!\n");
        return 1;
    }

    int kolizhestvo = 0;
    while (strcmp(fgets(buffer, 256, input), "\n") != 0) {
        p = buffer;
        for (int i = 0; i < existing_count; i++) {
            temp = strtol(p, &p, 10);
            raspolozhenie[kolizhestvo][i] = temp;
        }
        kolizhestvo++;
    }

    for (int i = 0; i < kolizhestvo; i++) {
        fgets(buffer, 256, input);
        p = buffer;
        for (int j = 0; j < existing_count; j++) {
            temp = strtol(p, &p, 10);
            request[i][j] = temp;
        }
    }


    // algorithm
    int process_ok[MAXP] = {};

    for(;1;) {
        int udovletvoryaet = 0;
        for (int i = 0; i < kolizhestvo; i++) {
            if (process_ok[i])
                continue;
            int j;
            for (j = 0; j < available_count; j++) {
                if (request[i][j] > dstup_r[j]) {
                    break;
                }
            }
            if (j != available_count)
                continue;
            for (j = 0; j < available_count; j++) {
                dstup_r[j] += request[i][j] + raspolozhenie[i][j];
            }
            udovletvoryaet = 1;
            process_ok[i] = 1;
        }
        if (udovletvoryaet == 0)
            break;
    }


    FILE *output = fopen("output.txt", "w");

    int mertviy_lockator = 0;
    for (int i = 0; i < kolizhestvo; i++) {
        if (!process_ok[i]) {
            mertviy_lockator = 1;
            break;
        }
    }

    if (mertviy_lockator) {
        fprintf(output, "mertviy_lockator: ");
        for (int i = 0; i < kolizhestvo; i++) {
            if (!process_ok[i]) {
                fprintf(output, "%d, ", i);
            }
        }
        fprintf(output, "\n");
    } else {
        fprintf(output, "No mertviy_lockator :D\n");
    }
    return 0;
}   