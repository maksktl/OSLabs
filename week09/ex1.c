#include <stdio.h>
#include <stdlib.h>

typedef struct page {
    int id;
    unsigned int counter;
} page_t;


page_t *search_page(page_t *pages, int id, size_t page_count) {
    for (int i = 0; i < page_count; ++i) {
        if (pages[i].id == id)
            return pages + i;
    }
    return NULL;
}


page_t *available_page(page_t *pages, size_t page_count) {
    unsigned int lowest_counter = 1 << 31;
    int lowest_id = 0;
    for (int i = 0; i < page_count; ++i) {
        if (pages[i].id == 0)
            return pages + i;

        if (pages[i].counter < lowest_counter) {
            lowest_counter = pages[i].counter;
            lowest_id = i;
        }
    }
    return pages + lowest_id;
}

int main(int argc, char *argv[]) {

    if (argc != 2 && argc != 3) {
        printf("Usage: %s <number of page frames> [input file name]\n", argv[0]);
        return 1;
    }

    int page_count = strtol(argv[1], NULL, 10);

    page_t *pages = calloc(page_count, sizeof(page_t));
    if (pages == NULL) {
        printf("Error allocating memory for page table!\n");
        return 2;
    }

    char *file = (argc == 3) ? argv[2] : "input.txt";

    FILE *input = fopen(file, "r");
    if (input == NULL) {
        printf("Cannot read input file ('%s')!\n", file);
        return 3;
    }

    int pageId;
    int value = 0, misses = 0;
    while (fscanf(input, "%d", &pageId) == 1) {

        page_t *page = search_page(pages, pageId, page_count);
        if (page != NULL) {
            value++;
        } else {
            misses++;

            page = available_page(pages, page_count);
            page->id = pageId;
            page->counter = 0;
        }

        for (int i = 0; i < page_count; ++i)
            pages[i].counter >>= 1;

        page->counter |= 1 << (sizeof(((page_t *)0)->counter) * 8 - 1);
    }

    printf("value: %d, Misses: %d\n", value, misses);
    printf("value/Misses = %f\n", (double) value / misses);

    free(pages);
    fclose(input);

    return 0;
}
