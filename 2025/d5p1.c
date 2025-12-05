#include<stdio.h>
#include<stdlib.h>

int main(void) {
    FILE *file = fopen("./input/d5-input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Input file not found");
        return 1;
    }

    unsigned int ranges_lines_count = 0;
    char buffer[240];

    while(fgets(buffer, sizeof buffer, file) != NULL) {
        if (buffer[0] == '\n') {
            break;
        }

        ranges_lines_count++;
    }

    rewind(file);

    typedef struct Range {
        unsigned long lower_bound;
        unsigned long upped_bound;
    } Range;

    Range ranges[ranges_lines_count];

    unsigned int index = 0;
    while(fgets(buffer, sizeof buffer, file) != NULL) {
        if (buffer[0] == '\n') {
            break;
        }

        Range range;
        sscanf(buffer, "%lu-%lu",&range.lower_bound, &range.upped_bound);
        ranges[index] = range;
        index++;
    }

    unsigned int fresh_ingredients = 0;

    while(fgets(buffer, sizeof buffer, file) != NULL) {
        unsigned long target = strtoul(buffer, NULL, 10);
        for (unsigned  int i = 0; i < ranges_lines_count; i++) {
            Range range = ranges[i];
            if (target >= range.lower_bound && target <= range.upped_bound) {
                fresh_ingredients++;
                break;
            }
        }
    }

    printf("%d\n", fresh_ingredients); //529

    return 0;
}
